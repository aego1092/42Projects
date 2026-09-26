#!/usr/bin/env python3


class Plant:
    def __init__(self, name: str, height: int, days: int) -> None:
        self.name = name.capitalize()
        self.height = height
        self.days = days

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.days} days old")


def main() -> None:
    print("=== Garden Plant Registry ===")
    rose = Plant("rose", 25, 30)
    rose.show()
    sunflower = Plant("sunflower", 80, 45)
    sunflower.show()
    cactus = Plant(name="Cactus", days=120, height=15)
    cactus.show()


if __name__ == "__main__":
    main()
