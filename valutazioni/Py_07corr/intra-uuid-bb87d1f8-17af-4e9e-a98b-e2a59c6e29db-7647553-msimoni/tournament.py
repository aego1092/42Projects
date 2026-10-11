#!/bin/python3


import ex0
import ex1
import ex2


Opponents = list[tuple[ex0.CreatureFactory, ex2.BattleStrategy]]


def battle(opponents: Opponents) -> None:
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")
    print()

    creatures = [
        (factory.create_base(), strategy) for factory, strategy in opponents
    ]

    for i in range(len(creatures)):
        for j in range(i + 1, len(creatures)):
            creature_a, strategy_a = creatures[i]
            creature_b, strategy_b = creatures[j]

            print("* Battle *")
            print(creature_a.describe())
            print(" vs.")
            print(creature_b.describe())
            print(" now fight!")

            try:
                strategy_a.act(creature_a)
                strategy_b.act(creature_b)
            except ex2.InvalidStrategyError as error:
                print(f"Battle error, aborting tournament: {error}")
                return
            print()


def main() -> None:
    flame_factory = ex0.FlameFactory()
    aqua_factory = ex0.AquaFactory()
    healing_factory = ex1.HealingCreatureFactory()
    transform_factory = ex1.TransformCreatureFactory()

    normal = ex2.NormalStrategy()
    aggressive = ex2.AggressiveStrategy()
    defensive = ex2.DefensiveStrategy()

    print("Tournament 0 (basic)")
    print(" [ (Flameling+Normal), (Healing+Defensive) ]")
    battle([
        (flame_factory, normal),
        (healing_factory, defensive),
    ])

    print("Tournament 1 (error)")
    print(" [ (Flameling+Aggressive), (Healing+Defensive) ]")
    battle([
        (flame_factory, aggressive),
        (healing_factory, defensive),
    ])

    print("Tournament 2 (multiple)")
    print(" [ (Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive) ]")
    battle([
        (aqua_factory, normal),
        (healing_factory, defensive),
        (transform_factory, aggressive),
    ])


if __name__ == "__main__":
    main()
