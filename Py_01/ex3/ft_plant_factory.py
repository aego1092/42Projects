#!/usr/bin/env python3

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
    """Instantiate and initialize the class for new plant at same time"""

# Istanziazione della singola pianta dalla classe
# Se non definiti esplicitamente, li associa secondo l ordine posizionale
    rose = Plant(name="Rose", height_in_cm=25, age_in_days=30, grow_rate=0.8)
    oak = Plant("Oak", 200.0, 365, 0.1)
    cactus = Plant("Cactus", 5.0, 90, 0.02)
    sunflower = Plant("Sunflower", 80.0, 45, 0.03)
    fern = Plant("Fern", 15.0, 120, 0.04)

    # Lista per dare un ordine a oggetti istanziati
    plants = [rose, oak, cactus, sunflower, fern]

    print("=== Plant Factory Output ===")
    for plant in plants:
        plant.show()


if __name__ == "__main__":
    main()
