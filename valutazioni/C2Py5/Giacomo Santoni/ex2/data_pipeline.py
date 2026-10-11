import typing
import abc


class ValidationError(Exception):
    pass


class InvalidProcessor(Exception):
    def __init__(self, message: str = "Invalid Processor"):
        super().__init__(message)
        self.message = message


class DataStreamError(Exception):
    def __init__(self, element: typing.Any, message: str =
                 "DataStream error - Can't process element in stream: "):
        full_message = f"{message}{element}"
        super().__init__(full_message)


class ExportPlugin(typing.Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        pass


class DataProcessor(abc.ABC):
    def __init__(self, ingestions: list[typing.Any] = [], total: int = 0):
        self.ingestions = ingestions
        self.total = total

    @abc.abstractmethod
    def validate(self, data: typing.Any) -> bool:
        pass

    @abc.abstractmethod
    def ingest(self, data: typing.Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if len(self.ingestions) == 0:
            print("No data have been processed yet")
            return (0, "")
        p = self.ingestions[0]
        out = (self.total - len(self.ingestions), p)
        self.ingestions = self.ingestions[1:]
        return out


class NumericProcessor(DataProcessor):
    def __init__(self, ingestions: list[str] = [], total: int = 0):
        super().__init__(ingestions, total)

    def validate(self, data: typing.Any) -> bool:
        if type(data) in [int, float]:
            return True
        else:
            return False

    def ingest(self, data: typing.Any) -> None:
        if type(data) is list:
            for x in data:
                if self.validate(x) is False:
                    raise ValidationError("Improper numeric data")
                else:
                    self.total += 1
                    self.ingestions.append(str(x))
        else:
            if self.validate(data) is False:
                raise ValidationError("Improper numeric data")
            else:
                self.total += 1
                self.ingestions.append(str(data))


class TextProcessor(DataProcessor):
    def __init__(self, ingestions: list[str] = [], total: int = 0):
        super().__init__(ingestions, total)

    def validate(self, data: typing.Any) -> bool:
        if type(data) is str:
            return True
        else:
            return False

    def ingest(self, data: typing.Any) -> None:
        if type(data) is list:
            for x in data:
                if self.validate(x) is False:
                    raise ValidationError("Improper textual data")
                else:
                    self.total += 1
                    self.ingestions.append(x)
        else:
            if self.validate(data) is False:
                raise ValidationError("Improper textual data")
            else:
                self.total += 1
                self.ingestions.append(data)


class LogProcessor(DataProcessor):
    def __init__(self, ingestions: list[str] = [], total: int = 0):
        super().__init__(ingestions, total)

    def validate(self, data: typing.Any) -> bool:
        if type(data) is dict:
            for x in data.keys():
                if type(x) is not str or type(data[x]) is not str:
                    return False
            return True
        else:
            return False

    def ingest(self, data: typing.Any) -> None:
        if type(data) is list:
            for x in data:
                if self.validate(x) is False:
                    raise ValidationError("Improper dictionary data")
                else:
                    self.total += 1
                    self.ingestions.append(f"{x['log_level']}: " +
                                           f"{x['log_message']}")
        else:
            if self.validate(data) is False:
                raise ValidationError("Improper dictionary data")
            else:
                self.total += 1
                self.ingestions.append(f"{data['log_level']}: " +
                                       f"{data['log_message']}")


class DataStream:
    def __init__(self, processors: dict[str, DataProcessor] = {},
                 stats: dict[str, int] = {}):
        self.processors = processors
        self.stats = stats

    def register_processor(self, proc: typing.Any) -> None:
        if type(proc) is NumericProcessor:
            self.processors['Numeric'] = proc
            self.stats['Numeric'] = 0
        elif type(proc) is TextProcessor:
            self.processors['Text'] = proc
            self.stats['Text'] = 0
        elif type(proc) is LogProcessor:
            self.processors['Log'] = proc
            self.stats['Log'] = 0
        else:
            raise InvalidProcessor

    def process_stream(self, stream: list[typing.Any]) -> None:
        for x in stream:
            try:
                processed: bool = False
                for proc in self.processors.values():
                    try:
                        proc.ingest(x)
                        processed = True
                        n = 0
                        if type(x) is list:
                            n = len(x)
                        else:
                            n = 1
                        if type(proc) is NumericProcessor:
                            self.stats['Numeric'] += n
                        elif type(proc) is TextProcessor:
                            self.stats['Text'] += n
                        elif type(proc) is LogProcessor:
                            self.stats['Log'] += n
                        break
                    except ValidationError:
                        continue
                if not processed:
                    raise DataStreamError(x)
            except DataStreamError as e:
                print(e)
        return

    def print_processors_stats(self) -> None:
        if self.processors == {}:
            print("No processor found, no data")
        for x in self.processors.keys():
            print(f"{x} processor: total {self.stats[x]} processed, rema" +
                  f"ining {len(self.processors[x].ingestions)} on processor")

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for x in self.processors.values():
            l: list[tuple[int, str]] = []
            i = 0
            while i in range(nb) and len(x.ingestions) > 0:
                l.append(x.output())
                i += 1
            plugin.process_output(l)


class CSV:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        out = ""
        for i in range(len(data)):
            out += data[i][1]
            if i < len(data) - 1:
                out += ","
        print("CSV Output:")
        print(out)


class JSON:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        out: dict[str, str] = {}
        for x in data:
            out[f"item_{x[0]}"] = x[1]
        print("JSON Output:")
        print(out)


if __name__ == "__main__":
    print("=== Code Nexus - Data Pipeline ===")

    print("\nInitialize Data Stream...")
    ds = DataStream()

    print("\n== Data Stream statistica ==")
    ds.print_processors_stats()

    np = NumericProcessor()
    tp = TextProcessor()
    lp = LogProcessor()
    print("\nRegistering Processors")
    ds.register_processor(np)
    ds.register_processor(tp)
    ds.register_processor(lp)

    data = ['Hello world', [3.14, -1, 2.71],
            [{'log_level': 'WARNING',
             'log_message': 'Telnet access! Use ssh instead'},
             {'log_level': 'INFO', 'log_message': 'User wil is connected'}],
            42, ['Hi', 'five']]
    print(f"\nSend first batch of data on the stream: {data}")
    ds.process_stream(data)
    print(np.ingestions)

    csv = CSV()
    print("\nSend 3 processed data from each processor to a CSV plugin")
    ds.output_pipeline(3, csv)
    print(np.ingestions)

    print("\n== Data stream statistics ==")
    ds.print_processors_stats()

    data = [21, ['I love AI', 'LLMs are wonderful', 'Stay healthy'],
            [{'log_level': 'ERROR', 'log_message': '500 server crash'},
             {'log_level': 'NOTICE',
              'log_message': 'Certificate expires in 10 days'}],
            [32, 42, 64, 84, 128, 168], 'World hello']
    print(f"\nSend another batch of data on the stream: {data}")
    ds.process_stream(data)
    print(np.ingestions)

    print("\n== Data stream statistics ==")
    ds.print_processors_stats()

    json = JSON()
    print("\nSend 5 processed data from each processor to a JSON plugin")
    ds.output_pipeline(5, json)

    print("\n== Data stream statistics ==")
    ds.print_processors_stats()
