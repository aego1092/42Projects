#!/bin/python3


import ex0


def test_factory(factory: ex0.CreatureFactory) -> None:
    print("Testing factory")
    base_creature = factory.create_base()
    print(base_creature.describe())
    print(base_creature.attack())

    evolved_creature = factory.create_evolved()
    print(evolved_creature.describe())
    print(evolved_creature.attack())


def test_battle(
    factory_a: ex0.CreatureFactory, factory_b: ex0.CreatureFactory
) -> None:
    print("Testing battle")
    creature_a = factory_a.create_base()
    creature_b = factory_b.create_base()

    print(creature_a.describe())
    print("vs.")
    print(creature_b.describe())
    print("fight!")
    print(creature_a.attack())
    print(creature_b.attack())


def main() -> None:
    flame_factory: ex0.CreatureFactory = ex0.FlameFactory()
    aqua_factory: ex0.CreatureFactory = ex0.AquaFactory()

    test_factory(flame_factory)
    print()
    test_factory(aqua_factory)
    print()
    test_battle(flame_factory, aqua_factory)


if __name__ == "__main__":
    main()
