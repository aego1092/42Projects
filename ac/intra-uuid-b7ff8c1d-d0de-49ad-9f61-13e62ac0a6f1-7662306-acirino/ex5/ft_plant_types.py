#!/usr/bin/env python3


class Plant:
    def __init__(self, name: str, height: float, days: int) -> None:
        self.name = name.capitalize()
        self._height = 0.0
        self.set_height(height)
        self._days = 0
        self.set_age(days)

    def show(self) -> None:
        print(
            f"{self.name}:",
            f"{round(self.get_height(), 2)}cm,",
            f"{self.get_age()} days old",
        )

    def grow(self, n: float) -> bool:
        return self.set_height(self.get_height() + n)

    def age(self, n: int = 1) -> bool:
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
        print(
            self.__class__.__name__,
            self.name,
            f"now produces a shade of {self.get_height()}cm long",
            f"and {self.trunk_diameter}cm wide.",
        )


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


def main() -> None:
    print("=== Garden Plant Types ===")
    print("=== Flower")
    rose = Flower("rose", 15.0, 10, "red")
    rose.show()
    print("[asking the rose to bloom]")
    rose.bloom()
    rose.show()
    print("\n=== Tree")
    oak = Tree("oak", 200.0, 365, 5.0)
    oak.show()
    print("[asking the oak to produce shade]")
    oak.produce_shade()
    print("\n=== Vegetable")
    tomato = Vegetable("tomato", 5.0, 10, "april")
    tomato.show()
    print("[make tomato grow and age for 20 days]")
    for _ in range(20):
        tomato.grow(2.1)
        tomato.age()
    tomato.show()


if __name__ == "__main__":
    main()
