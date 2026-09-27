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
    rose = Plant(name="rose", height=25.0, days=30)
    oak = Plant("oak", 200.0, 365)
    cactus = Plant("cactus", 5.0, 90)
    sunflower = Plant("sunflower", 80.0, 45)
    fern = Plant("fern", 15.0, 120)
    plants = [rose, oak, cactus, sunflower, fern]
    print("=== Plant Factory Output ===")
    for plant in plants:
        print("Created:", end=" ")
        plant.show()


if __name__ == "__main__":
    main()
