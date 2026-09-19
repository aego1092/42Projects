#!/usr/bin/env python3

class Plant:
    """Class representing the blueprint for any plant."""
    # class attributes_empty

    @staticmethod
    def is_older_than_a_year(age_in_days: int) -> bool:
        return age_in_days > 365

    @classmethod
    def create_anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0, 0.0)

    class _Statistical_data:
        def __init__(self) -> None:
            self._grow_calls = 0
            self._age_calls = 0
            self._show_calls = 0

        # metodi di notifica (registrano un evento)
        def update_stats_grow(self) -> None:
            self._grow_calls += 1

        def update_stats_age(self) -> None:
            self._age_calls += 1

        def update_stats_show(self) -> None:
            self._show_calls += 1

        def display(self) -> None:
            print(
                f"Stats: {self._grow_calls} grow, "
                f"{self._age_calls} age, {self._show_calls} show"
            )

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

        self._stats = Plant._Statistical_data()				# attribute instance

    def grow(self, time: int) -> None:
        """Method that simulate plant growth over time, update its stats."""
        self._stats.update_stats_grow()
        if (self._grow_rate * time) < 0:
            print(
                f"{self._name}: Error, height can't be negative\n"
                "Height update rejected")
            return  				# rifiuta il dato
        self._height_in_cm += self._grow_rate * time

    def age(self, time: int) -> None:
        """Method that simulate the plant aging over time, update its stats."""
        self._stats.update_stats_age()
        self._age_in_days += time

    def show(self) -> None:
        """Display the plant's information, update its stats."""
        self._stats.update_stats_show()
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


class Seed(Flower):
    def __init__(
        self,
        name: str,
        height_in_cm: float,
        age_in_days: int,
        grow_rate: float,
        color: str,
        blooming: bool
    ) -> None:
        super().__init__(name, height_in_cm, age_in_days, grow_rate,
                         color, blooming)
        self.seeds = 0

    def bloom(self) -> None:
        super().bloom()
        self.seeds = 42

    def show(self) -> None:
        super().show()
        print(f" Seeds: {self.seeds}")


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
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.is_older_than_a_year(30)}")
    print(f"Is 400 days more than a year? -> "
          f"{Plant.is_older_than_a_year(400)}")
    print()

    print("=== Flower")
    rose = Flower("Rose", 15.0, 10, 0.8, "red", False)
    rose.show()
    rose._stats.display()
    print("[asking the rose to grow and bloom]")
    rose.grow(time=10)
    rose.bloom()
    rose.show()
    rose._stats.display()

    print("\n=== Tree")
    oak = Tree("Oak", 200.0, 365, 100, 5.0, False)
    oak.show()
    oak._stats.display()
    print("[asking the oak to produce shade]")
    oak.produce_shade()
    oak._stats.display()

    print("\n=== Seed")
    sunflower = Seed("Sunflower", 80.0, 45, 1.5, "yellow", False)
    sunflower.show()
    print("[make sunflower grow, age and bloom]")
    sunflower.grow(time=20)
    sunflower.age(time=20)
    sunflower.bloom()
    sunflower.show()
    sunflower._stats.display()

    print("\n=== Anonymous")
    anonymous = Plant.create_anonymous()
    anonymous.show()
    print("[statistics for Unknown plant]")
    anonymous._stats.display()


if __name__ == "__main__":
    main()
