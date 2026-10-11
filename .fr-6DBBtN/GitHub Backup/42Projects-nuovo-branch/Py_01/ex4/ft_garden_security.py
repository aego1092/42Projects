#!/usr/bin/env python3

class Plant:
    """Class representing the blueprint for any plant."""
    # class attributes_empty
    def __init__(
        self,
        name: str,
        height_in_cm: float,
        age_in_days: int,
        grow_rate: float
     ) -> None:
        """Method that initialize a new Plant instance."""

        self._name = name			        		# attribute instance
        if height_in_cm < 0:
            raise ValueError(
                f"{self._name}: Error, height can't be negative")
            # rifiuta l inizializzazione e blocca per dato invalido

        self._height_in_cm = height_in_cm   		# attribute instance
        if age_in_days < 0:
            raise ValueError(
                f"{self._name}: Error, age can't be negative")
            # rifiuta l inizializzazione e blocca per dato invalido

        self._age_in_days = age_in_days	    		# attribute instance

        self._grow_rate = grow_rate					# attribute instance

    def grow(self, time: float) -> None:
        """Method that simulate plant growth over time."""
        if (self._grow_rate * time) < 0:
            print(
                f"{self._name}: Error, height can't be negative\n"
                "Height update rejected")
            return  				# rifiuta il dato
        self._height_in_cm += self._grow_rate * time

    def age(self, time: int) -> None:
        """Method that simulate the plant aging over time."""
        self._age_in_days += time

    def show(self) -> None:
        """Display the plant's information formatted as required."""
        print(
            f"{self._name}: {self.get_height():.1f}cm, "
            f"{self.get_age()} days old"
        )

    def get_height(self) -> float:
        return self._height_in_cm

    def get_age(self) -> int:
        return self._age_in_days

    def set_height(self, new_height_in_cm: float) -> bool:
        if new_height_in_cm < 0:
            print(
                f"{self._name}: Error, height can't be negative\n"
                "Height update rejected")
            return False 				# rifiuta la modifica, il dato resta invariato
        self._height_in_cm = new_height_in_cm
        return True

    def set_age(self, new_age_in_days: int) -> bool:
        if new_age_in_days < 0:
            print(
                f"{self._name}: Error, age can't be negative\n"
                "Age update rejected")
            return False				# rifiuta la modifica, il dato resta invariato
        self._age_in_days = new_age_in_days
        return True


def main() -> None:
    """Instantiate and initialize the class for new plant at same time"""

# Istanziazione della singola pianta dalla classe
# Se non definiti esplicitamente,
# python li associa secondo l ordine posizionale
    try:
        rose = Plant(
            name="Rose", height_in_cm=15, age_in_days=10, grow_rate=0.8)
        print("=== Garden Security System ===")
        print("Plant created: ")
        rose.show()
        print()

        if rose.set_height(25):
            print(f"Height updated: {round(rose.get_height(), 1)}cm")

        if rose.set_age(30):
            print(f"Age updated: {rose.get_age()} days")

        print()

        rose.set_height(-25)

        rose.set_age(-30)

        print("\nCurrent state: ")
        rose.show()
    except ValueError as e:
        print(f"{e}")


if __name__ == "__main__":
    main()
