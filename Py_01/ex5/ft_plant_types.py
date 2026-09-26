#!/usr/bin/env python3

class Plant:
    """Class representing the blueprint for any plant."""
    # class attributes_empty
    def __init__(
        self,
        name: str,
        height_in_cm: float,
        age_in_days: int,
        grow_rate: float,
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

    def grow(self, time: int) -> None:
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


class Flower(Plant):
    def __init__(
        self,
        name: str,
        height_in_cm: float,
        age_in_days: int,
        grow_rate: float,
        color: str,
        blooming: bool
    ) -> None:
        super().__init__(name, height_in_cm, age_in_days, grow_rate)
        self.color = color
        self.blooming = blooming

    def bloom(self) -> None:
        self.blooming = True

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")
        if self.blooming is False:
            print(f" {self._name} has not bloomed yet")
        else:
            print(f" {self._name} is blooming beautifully!")


class Tree(Plant):
    def __init__(
        self,
        name: str,
        height_in_cm: float,
        age_in_days: int,
        grow_rate: float,
        trunk_diameter: float,
        shading: bool
    ) -> None:
        super().__init__(name, height_in_cm, age_in_days, grow_rate)
        self.trunk_diameter = trunk_diameter
        self.shading = shading

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter}cm")

    def produce_shade(self) -> None:
        self.shading = True
        if self.shading is False:
            pass
        else:
            print(
                f"Tree {self._name} now produces a shade of "
                f"{self._height_in_cm}cm long and {self.trunk_diameter}cm "
                f"wide."
            )


class Vegetable(Plant):
    def __init__(
        self,
        name: str,
        height_in_cm: float,
        age_in_days: int,
        grow_rate: float,
        harvest_season: str,
        nutritional_value: int
    ) -> None:
        super().__init__(name, height_in_cm, age_in_days, grow_rate)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {self.nutritional_value}")

    def grow(self, time: int) -> None:
        """Method that simulate plant growth over time."""
        if (self._grow_rate * time) < 0:
            print(
                f"{self._name}: Error, height can't be negative\n"
                "Height update rejected")
            return  				# rifiuta il dato
        self._height_in_cm += self._grow_rate * time
        self.nutritional_value += 2 * time


def main() -> None:
    print("=== Garden Plant Types ===")
    print("=== Flower")
    rose = Flower("Rose", 15.0, 10, 0.8, "red", False)
    rose.show()
    print("[asking the rose to bloom]")
    rose.bloom()
    rose.show()

    print("\n=== Tree")
    oak = Tree("Oak", 200.0, 365, 100, 5.0, False)
    oak.show()
    print("[asking the oak to produce shade]")
    oak.produce_shade()

    print("\n=== Vegetable")
    tomato = Vegetable("Tomato", 5.0, 10, 4.2, "April", 0)
    tomato.show()
    print("[make tomato grow and age for 20 days]")
    tomato.grow(time=10)
    tomato.age(time=10)
    tomato.show()


if __name__ == "__main__":
    main()
