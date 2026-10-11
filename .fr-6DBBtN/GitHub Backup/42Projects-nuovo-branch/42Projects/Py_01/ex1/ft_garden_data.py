#!/usr/bin/env python3
"""Module to handle plant registry using the Plant class."""


class Plant:
    """Class representing the blueprint for any plant"""
    # class attributes empty

    def __init__(self, name: str, height: int, age: int) -> None:
        """Method that initialize a new Plant instance."""
        self.name: str = name		# attribute instance
        self.height: int = height   # attribute instance
        self.age: int = age			# attribute instance

    def show(self) -> None:
        """Display the plant's information formatted as required."""
        print(f"{self.name}: {self.height}cm, {self.age} days old")


def main() -> None:
    """Instantiate plant objects and display the garden registry."""
    print("=== Garden Plant Registry ===")

    # Istanziazione delle singole piante
    rose = Plant(name="x", height=0, age=0)
    rose.name = "Rose"
    rose.height = 25
    rose.age = 30
    sunflower = Plant(height=80, name="Sunflower", age=45)
    cactus = Plant("Cactus", 15, 120)

    # Chiamata al metodo show() per ciascuna istanza
    rose.show()				# chiamata tramite istanza
    Plant.show(sunflower)   # chiamata dalla classe(passando l'istanza)
    cactus.show()


if __name__ == "__main__":
    main()
