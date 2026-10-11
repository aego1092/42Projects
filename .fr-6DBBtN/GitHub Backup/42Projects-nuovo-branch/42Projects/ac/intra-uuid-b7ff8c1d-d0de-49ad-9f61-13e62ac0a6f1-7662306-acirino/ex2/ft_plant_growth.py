#!/usr/bin/env python3


class Plant:
    def __init__(self, name: str, height: float, days: int) -> None:
        self.name = name.capitalize()
        self.height = height
        self.days = days

    def show(self) -> None:
        print(f"{self.name}: {round(self.height, 2)}cm, {self.days} days old")

    def grow(self, n: float) -> None:
        self.height += n

    def age(self, n: int = 1) -> None:
        self.days += n


def main() -> None:
    rose = Plant(name="rose", height=25, days=30)
    print("=== Garden Plant Growth ===")
    rose.show()
    difference = 0.0
    for day in range(7):
        print(f"=== Day {day + 1} ===")
        difference -= rose.height
        rose.grow(0.8)
        difference += rose.height
        rose.age()
        rose.show()
    print(f"Growth this week: {round(difference, 2)}cm")


if __name__ == "__main__":
    main()
