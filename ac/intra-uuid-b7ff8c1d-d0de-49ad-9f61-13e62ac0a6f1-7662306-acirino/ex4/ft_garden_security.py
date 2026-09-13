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


def main() -> None:
    print("=== Garden Security System ===")
    rose = Plant(name="rose", height=15.0, days=10)
    print("Plant created:", end=" ")
    rose.show()
    print()
    if rose.grow(10):
        print(f"Height updated: {round(rose.get_height())}cm")
    if rose.age(20):
        print(f"Age updated: {rose.get_age()} days")
    print()
    if rose.grow(-100):
        print(f"Height updated: {rose.get_height()}cm")
    if rose.age(-200):
        print(f"Age updated: {rose.get_age()} days")
    print("\nCurrent state:", end=" ")
    rose.show()


if __name__ == "__main__":
    main()
