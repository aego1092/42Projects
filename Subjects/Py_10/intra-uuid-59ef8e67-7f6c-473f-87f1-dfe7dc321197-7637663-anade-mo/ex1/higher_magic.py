#! /usr/bin/env python3

"""Higher-order functions: spells that take and return other spells.

Concepts learned:
 Higher-order functions: taking functions as arguments and returning new
 functions.

"""

from collections.abc import Callable


# output formatting constants
FIZZLE: str = "Spell fizzled"
TITLE: str = "Higher-order Functions: Spell Combiners and Amplifiers"
COMBINE_HEADER: str = "Testing spell combiner..."
AMPLIFY_HEADER: str = "Testing power amplifier..."
CONDITIONAL_HEADER: str = "Testing conditional caster..."
SEQUENCE_HEADER: str = "Testing spell sequence..."


# test data for spells and powers
test_spells: list[str] = ["fireball", "heal", "shield", "blizzard"]
test_powers: list[int] = [15, 22, 34, 47]


def heal(target: str, power: int) -> str:
    return f"Heal restores {target} for {power} HP"


# callable function to create spells
def spell_factory(name: str) -> Callable[[str, int], str]:

    def cast(target: str, power: int) -> str:
        if name == "heal":
            return (f"{name.capitalize()}"
                    f" restores {target} for {power} HP")
        if name == "shield":
            return (f"{name.capitalize()}"
                    f" rose {target} defense by {power} points")
        if name == "blizzard":
            return (f"{name.capitalize()}"
                    f" started, hit {target} for {power} damage")
        if name == "fireball":
            return (f"{name.capitalize()}"
                    f" hits {target} for {power} damage")
        return f"Unknown spell: {name.capitalize()}"
    return cast


# create a list of callable spells using spell_factory
spells: list[Callable[[str, int], str]] = [
    spell_factory(name) for name in test_spells]


# a function to check if a spell has enough power
def has_enough_power(target: str, power: int) -> bool:
    return power >= 20


# the functions imposed by the exercise, which take and return other
# functions, are defined below.
def spell_combiner(spell1: Callable[[str, int], str],
                   spell2: Callable[[str, int], str]
                   ) -> Callable[[str, int], tuple[str, str]]:

    if not callable(spell1) or not callable(spell2):
        raise TypeError("spell_combiner needs two callable spells")

    def combined(target: str, power: int) -> tuple[str, str]:
        return spell1(target, power), spell2(target, power)

    return combined


def power_amplifier(base_spell: Callable[[str, int], str],
                    multiplier: int
                    ) -> Callable[[str, int], str]:

    if not callable(base_spell):
        raise TypeError("power_amplifier needs a callable base_spell")

    def amplified(target: str, power: int) -> str:
        return base_spell(target, power * multiplier)

    return amplified


def conditional_caster(condition: Callable[[str, int], bool],
                       spell: Callable[[str, int], str]
                       ) -> Callable[[str, int], str]:

    if not callable(condition) or not callable(spell):
        raise TypeError("conditional_caster needs two callable arguments")

    def guarded(target: str, power: int) -> str:
        if condition(target, power):
            return spell(target, power)
        return FIZZLE

    return guarded


def spell_sequence(spells: list[Callable[[str, int], str]]
                   ) -> Callable[[str, int], list[str]]:

    if not all(callable(spell) for spell in spells):
        raise TypeError("spell_sequence needs a list of callable spells")

    def sequence(target: str, power: int) -> list[str]:
        return [spell(target, power) for spell in spells]

    return sequence


# test functions, which print their results

def test_combine() -> None:
    print(f"{COMBINE_HEADER}")
    combined = spell_combiner(spells[0], spells[1])
    for result in combined("Dragon", 15):
        print(f"  {result}")
    print()


def test_amplify() -> None:
    print(f"{AMPLIFY_HEADER}")
    amplified = power_amplifier(spells[0], 3)
    print(f"  Original: {test_powers[0]}, Amplified: {test_powers[0] * 3}")
    print(f"  {spells[0]('Dragon', test_powers[0])}")
    print(f"  {amplified('Dragon', test_powers[0])}")
    print()


def test_conditional() -> None:
    print(f"{CONDITIONAL_HEADER}")
    guarded = conditional_caster(has_enough_power, spells[0])
    for level in (25, 15):
        print(f"  power {level} -> {guarded('Dragon', level)}")
    print()


def test_sequence() -> None:
    print(f"{SEQUENCE_HEADER}")
    cast_all = spell_sequence(spells)
    for result in cast_all("Dragon", test_powers[0]):
        print(f"  {result}")
    print()


def main() -> None:
    print(f"\n{TITLE}")
    print("=" * len(TITLE))
    print()
    test_combine()
    test_amplify()
    test_conditional()
    test_sequence()


if __name__ == "__main__":
    main()
