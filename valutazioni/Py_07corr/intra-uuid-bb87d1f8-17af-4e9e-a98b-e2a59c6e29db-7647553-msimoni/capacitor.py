#!/bin/python3


import ex1


def test_healing(factory: ex1.HealingCreatureFactory) -> None:
    print("Testing Creature with healing capability")

    print(" base:")
    base = factory.create_base()
    print(base.describe())
    print(base.attack())
    print(base.heal())

    print(" evolved:")
    evolved = factory.create_evolved()
    print(evolved.describe())
    print(evolved.attack())
    print(evolved.heal())


def test_transform(factory: ex1.TransformCreatureFactory) -> None:
    print("Testing Creature with transform capability")

    print(" base:")
    base = factory.create_base()
    print(base.describe())
    print(base.attack())
    print(base.transform())
    print(base.attack())
    print(base.revert())

    print(" evolved:")
    evolved = factory.create_evolved()
    print(evolved.describe())
    print(evolved.attack())
    print(evolved.transform())
    print(evolved.attack())
    print(evolved.revert())


def main() -> None:
    test_healing(ex1.HealingCreatureFactory())
    test_transform(ex1.TransformCreatureFactory())


if __name__ == "__main__":
    main()
