#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.days_old = age

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.days_old} days old")


if __name__ == "__main__":
    print("=== Plant Factory Output ===")
    plant1 = Plant("Tomato", 30.0, 45)
    plant2 = Plant("Cucumber", 25.0, 30)
    plant3 = Plant("Lettuce", 15.0, 20)
    plant4 = Plant("Carrot", 10.0, 25)
    plant5 = Plant("Pepper", 20.0, 35)

    plants = [plant1, plant2, plant3, plant4, plant5]
    for plant in plants:
        print("Created: ", end="")
        plant.show()
