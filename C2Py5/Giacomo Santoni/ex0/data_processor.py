import typing
import abc


class ValidationError(Exception):
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


if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===")

    np = NumericProcessor()
    print("\nTesting Numeric Processor...")
    a = 42
    print(f"Trying to validate input '{a}': {np.validate(a)}")
    b = "Hello"
    print(f"Trying to validate input '{b}': {np.validate(b)}")
    c = "foo"
    print(f"Test invalid ingestion of string '{c}' without prior validation:")
    try:
        np.ingest(c)
    except ValidationError as e:
        print("Got exception:", e)
    ndata = [1, 2, 3, 4, 5]
    print(f"Processing data: {ndata}")
    np.ingest(ndata)
    print("Extracting 3 values...")
    for i in range(3):
        print(f"Numeric value {i}: {np.ingestions[i]}")

    tp = TextProcessor()
    print("\nTesting Text Processor...")
    a = 42
    print(f"Trying to validate input '{a}': {tp.validate(a)}")
    tdata = ["Hello", "Nexus", "World"]
    print(f"Processing data: {tdata}")
    tp.ingest(tdata)
    print("Extracting 1 value...")
    for i in range(1):
        print(f"Text value {i}: {tp.ingestions[i]}")

    lp = LogProcessor()
    print("\nTesting Log Processor...")
    b = "Hello"
    print(f"Trying to validate input '{a}': {lp.validate(a)}")
    ldata = [{'log_level': 'NOTICE', 'log_message': 'Connection to server'},
             {'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}]
    print(f"Processing data: {ldata}")
    lp.ingest(ldata)
    print("Extracting 2 values...")
    for i in range(2):
        print(f"Log entry {i}: {lp.ingestions[i]}")
