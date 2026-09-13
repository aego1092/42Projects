#!/usr/bin/env python3


class Plant:
    def __init__(self, name: str, height: float, days: int) -> None:
        self.name = name.capitalize()
        self._height = 0.0
        self.set_height(height)
        self._days = 0
        self.set_age(days)
        self.stats = self.Statistics(self)

    def show(self) -> None:
        self.stats.record("show")
        print(
            f"{self.name}:",
            f"{round(self.get_height(), 2)}cm,",
            f"{self.get_age()} days old",
        )

    def grow(self, n: float) -> bool:
        self.stats.record("grow")
        return self.set_height(self.get_height() + n)

    def age(self, n: int = 1) -> bool:
        self.stats.record("age")
        return self.set_age(self.get_age() + n)

    def set_height(self, height: float) -> bool:
        if height < 0:
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")
            return False
        else:
            self._height = height
            return True

    def set_age(self, days: int) -> bool:
        if days < 0:
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")
            return False
        else:
            self._days = days
            return True

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._days

    @staticmethod
    def check_year(days: int) -> bool:
        return days > 365

    @classmethod
    def anonymous(cls, height: float = 0.0, days: int = 0) -> "Plant":
        return cls("Unknown plant", height, days)

    class Statistics:
        def __init__(self, plant: "Plant"):
            self._plant = plant
            self._counts = {
                "grow": 0,
                "age": 0,
                "show": 0,
            }
            self._additional_counts: dict[str, int] = {}

        def record(self, action: str) -> None:
            if action in self._counts:
                self._counts[action] += 1
            elif action in self._additional_counts:
                self._additional_counts[action] += 1

        def get_count(self, action: str) -> int:
            if action in self._counts:
                return self._counts[action]
            elif action in self._additional_counts:
                return self._additional_counts[action]
            return 0

        def show(self) -> None:
            print(f"[statistics for {self._plant.name}]")
            print("Stats:", end=" ")
            s_list = [
                    f"{self._counts[action]} {action}"
                    for action in self._counts
                    ]
            print(*s_list, sep=", ")
            if self._additional_counts:
                print(end=" ")
                s_list = [
                    f"{self._additional_counts[action]} {action}"
                    for action in self._additional_counts
                ]
                print(*s_list, sep=", ")


class Flower(Plant):
    def __init__(self, name: str, height: float, days: int, color: str):
        super().__init__(name, height, days)
        self.color = color
        self.bloomed = False

    def bloom(self) -> None:
        self.bloomed = True

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")
        if self.bloomed:
            print(f" {self.name} is blooming beautifully!")
        else:
            print(f" {self.name} has not bloomed yet")


class Seed(Flower):
    def __init__(self, name: str, height: float, days: int, color: str):
        super().__init__(name, height, days, color)
        self.seeds = 0

    def bloom(self) -> None:
        super().bloom()
        self.seeds = 42

    def show(self) -> None:
        super().show()
        print(f" Seeds: {self.seeds}")


class Tree(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        days: int,
        trunk_diameter: float,
    ):
        super().__init__(name, height, days)
        self.trunk_diameter = trunk_diameter

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter}cm")

    def produce_shade(self) -> None:
        self.stats.record("shade")
        print(
            self.__class__.__name__,
            self.name,
            f"now produces a shade of {self.get_height()}cm long",
            f"and {self.trunk_diameter}cm wide.",
        )

    class Statistics(Plant.Statistics):
        def __init__(self, plant: "Plant"):
            super().__init__(plant)
            self._additional_counts["shade"] = 0


class Vegetable(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        days: int,
        harvest_season: str,
    ):
        super().__init__(name, height, days)
        self.harvest_season = harvest_season.capitalize()
        self.nutritional_value = 0.0

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {round(self.nutritional_value)}")

    def grow(self, n: float) -> bool:
        self.nutritional_value += n / 4
        return super().grow(n)

    def age(self, n: int = 1) -> bool:
        self.nutritional_value += n / 2
        return super().age(n)


def print_plant_stats(plant: "Plant") -> None:
    plant.stats.show()


def main() -> None:
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.check_year(30)}")
    print(f"Is 400 days more than a year? -> {Plant.check_year(400)}")
    print()
    print("=== Flower")
    rose = Flower("rose", 15.0, 10, "red")
    rose.show()
    print_plant_stats(rose)
    print("[asking the rose to grow and bloom]")
    rose.grow(8.0)
    rose.bloom()
    rose.show()
    print_plant_stats(rose)
    print("\n=== Tree")
    oak = Tree("oak", 200.0, 365, 5.0)
    oak.show()
    print_plant_stats(oak)
    print("[asking the oak to produce shade]")
    oak.produce_shade()
    print_plant_stats(oak)
    print("\n=== Seed")
    sunflower = Seed("sunflower", 80.0, 45, "yellow")
    sunflower.show()
    print("[make sunflower grow, age and bloom]")
    sunflower.grow(30.0)
    sunflower.age(20)
    sunflower.bloom()
    sunflower.show()
    print_plant_stats(sunflower)
    print("\n=== Anonymous")
    anonymous = Plant.anonymous()
    anonymous.show()
    print_plant_stats(anonymous)


if __name__ == "__main__":
    main()
