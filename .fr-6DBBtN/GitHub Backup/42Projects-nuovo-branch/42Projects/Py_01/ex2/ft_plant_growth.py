#!/usr/bin/env python3
"""Module to simulate plant growth using the Plant class."""


class Plant:
    """Class representing the blueprint for any plant."""
    # class attributes_empty

    def __init__(
        self, name: str,
        height_in_cm: float,
        age_in_days: int,
        grow_rate: float
     ) -> None:
        """Method that initialize a new Plant instance."""
        self.name = name			        # attribute instance
        self.height_in_cm = height_in_cm    # attribute instance
        self.age_in_days = age_in_days	    # attribute instance
        self.grow_rate = grow_rate          # attribute instance

    def grow(self, time: int) -> None:
        """Method that simulate plant growth over time."""
        self.height_in_cm += self.grow_rate * time

    def age(self, time: int) -> None:
        """Method that simulate the plant aging over time."""
        self.age_in_days += time

    def show(self) -> None:
        """Display the plant's information formatted as required."""
        print(
            f"{self.name}: {self.height_in_cm:.1f}cm, "
            f"{self.age_in_days} days old"
        )


def main() -> None:
    """Simulate a week of growth for a plant, then access the data in the class
    to get the final height_in_cm and display the total week increase."""
    print("=== Garden Plant Growth ===")

    # Istanziazione della singola pianta dalla classe
    rose = Plant(name="Rose", height_in_cm=25, age_in_days=30, grow_rate=0.8)

    # altezza iniziale
    initial_height = rose.height_in_cm
    rose.show()

    for i in range(7):
        rose.grow(time=1)
        rose.age(time=1)
        print(f"=== Day {i + 1} ===")
        rose.show()

    # incremento altezza
    height_increase = rose.height_in_cm - initial_height
    print(f"Growth this week: {round(height_increase, 1)}cm")


if __name__ == "__main__":
    main()
