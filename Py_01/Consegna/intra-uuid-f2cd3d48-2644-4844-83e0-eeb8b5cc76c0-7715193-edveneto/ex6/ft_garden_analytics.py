#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self._height = height
        self._age = age
        self._stats = self._Stats()

    class _Stats:
        def __init__(self) -> None:
            self._grow_count = 0
            self._age_count = 0
            self._show_count = 0

        def display_stats(self) -> None:
            print(
                f"Stats: {self._grow_count} grow, "
                f"{self._age_count} age, {self._show_count} show"
            )

    def grow(self) -> None:
        self._height += 1.0
        self._stats._grow_count += 1

    def age(self) -> None:
        self._age += 1
        self._stats._age_count += 1

    def show(self) -> None:
        print(f"{self.name}: {self._height}cm, {self._age} days old")
        self._stats._show_count += 1

    @staticmethod
    def check_age(age: int) -> bool:
        return age > 365

    @classmethod
    def anonymous(cls) -> 'Plant':
        return cls("Unknown plant", 0.0, 0)


class Flower(Plant):
    def __init__(self, name: str, height: float,
                 age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color = color
        self.has_bloomed = False

    def bloom(self) -> None:
        self.has_bloomed = True
        print(f"{self.name} is blooming beautifully!")

    def show(self) -> None:
        super().show()
        print(f"Color: {self.color}")
        if not self.has_bloomed:
            print(f"{self.name} has not bloomed yet")


class Seed(Flower):
    def __init__(self, name: str, height: float,
                 age: int, color: str) -> None:
        super().__init__(name, height, age, color)
        self.seed_count = 0

    def bloom(self) -> None:
        super().bloom()
        self.seed_count = 42

    def show(self) -> None:
        super().show()
        print(f"Seeds: {self.seed_count}")


class Tree(Plant):
    def __init__(self, name: str, height: float,
                 age: int, trunk_diameter: float) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter
        self._tree_stats = self._TreeStats()

    class _TreeStats(Plant._Stats):
        def __init__(self) -> None:
            super().__init__()
            self._shade_count = 0

        def display_stats(self) -> None:
            super().display_stats()
            print(f"{self._shade_count} shade")

    def produce_shade(self) -> None:
        self._tree_stats._shade_count += 1
        print(
            f"Tree {self.name} now produces a shade of "
            f"{self._height}cm long and {self.trunk_diameter}cm wide."
        )


def display_plant_stats(plant: Plant) -> None:
    print(f"[statistics for {plant.name}]")
    plant._stats.display_stats()


if __name__ == "__main__":
    print("=== Garden statistics ===")
    print("=== Check year-old ===")
    print(f"Is 30 days more than a year? -> {Plant.check_age(30)}")
    print(f"Is 400 days more than a year? -> {Plant.check_age(400)}")

    print("\n=== Flower ===")
    rose = Flower("Rose", 15.0, 10, "red")
    rose.show()
    display_plant_stats(rose)
    print("[asking the rose to grow and bloom]")
    rose.grow()
    rose.bloom()
    rose.show()
    display_plant_stats(rose)

    print("\n=== Tree ===")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    display_plant_stats(oak)
    print("[asking the oak to produce shade]")
    oak.produce_shade()
    display_plant_stats(oak)

    print("\n=== Seed ===")
    sunflower = Seed("Sunflower", 80.0, 45, "yellow")
    sunflower.show()
    print("[make sunflower grow, age and bloom]")
    sunflower.grow()
    sunflower.age()
    sunflower.bloom()
    sunflower.show()
    display_plant_stats(sunflower)

    print("\n=== Anonymous ===")
    anon_plant = Plant.anonymous()
    anon_plant.show()
    display_plant_stats(anon_plant)
