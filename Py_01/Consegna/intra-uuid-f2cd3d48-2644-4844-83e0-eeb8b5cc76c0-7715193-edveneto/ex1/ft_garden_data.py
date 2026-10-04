#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age} days old")


if __name__ == "__main__":
    print("=== Garden Plant Registry ===")

    plant1 = Plant("Tomato", 30, 45)
    plant2 = Plant("Cucumber", 25, 30)
    plant3 = Plant("Lettuce", 15, 20)

    plant1.show()
    plant2.show()
    plant3.show()
