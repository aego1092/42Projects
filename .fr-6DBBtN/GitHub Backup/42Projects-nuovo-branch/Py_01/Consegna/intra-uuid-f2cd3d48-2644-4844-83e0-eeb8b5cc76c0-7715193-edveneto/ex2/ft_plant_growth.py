#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: float,
                 age: int, rate: float) -> None:
        self.name = name
        self.height = height
        self.days_old = age
        self.growth_rate = rate

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.days_old} days old")

    def grow(self) -> None:
        self.height += self.growth_rate

    def age(self) -> None:
        self.days_old += 1


if __name__ == "__main__":
    print("=== Garden Plant Growth ===")
    plant1 = Plant("Tomato", 30.0, 45, 0.4)
    total_growth = 0.0
    start_height = plant1.height
    plant1.show()
    for day in range(1, 8):
        print(f"=== Day {day} ===")
        plant1.grow()
        plant1.age()
        plant1.height = round(plant1.height, 1)
        plant1.show()
    total_growth = plant1.height - start_height
    print(f"Growth this week: {round(total_growth, 1)}cm")
