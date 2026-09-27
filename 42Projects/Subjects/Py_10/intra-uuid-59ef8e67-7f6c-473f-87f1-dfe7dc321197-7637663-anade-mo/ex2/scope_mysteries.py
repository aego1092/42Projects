#! /usr/bin/env python3

"""Closures: functions that remember the scope they were born in.

Concepts learned:
 The outer function returns the inner function, which can access the variables
 of the outer function.
 Because it returns the inner functions its called a closure.

"""

from collections.abc import Callable


# output formatting constants
TITLE: str = "Closures: Functions That Remember Their Scope"
NOT_FOUND: str = "Memory not found"
COUNTER_HEADER: str = "Testing mage counter..."
ACCUMULATOR_HEADER: str = "Testing spell accumulator..."
ENCHANTMENT_HEADER: str = "Testing enchantment factory..."
VAULT_HEADER: str = "Testing memory vault..."


# test data
test_items: list[str] = ["Sword", "Shield", "Staff", "Wand"]
test_powers: list[int] = [12, 25, 8]
test_enchantments: list[str] = ["Flaming", "Frozen", "Shocking"]


def mage_counter() -> Callable[[], int]:
    # Every call to mage_counter creates a fresh count
    count: int = 0

    def counter() -> int:
        nonlocal count
        count += 1
        return count

    return counter


def spell_accumulator(initial_power: int) -> Callable[[int], int]:
    # Every call to spell_accumulator creates a fresh total
    total: int = initial_power

    def accumulate(amount: int) -> int:
        nonlocal total
        total += amount
        return total

    return accumulate


def enchantment_factory(enchantment_type: str) -> Callable[[str], str]:
    # Every call to enchantment_factory creates a fresh enchantment
    def enchant(item: str) -> str:
        return f"{enchantment_type} {item}"

    return enchant


# The oposite case of closures, when functions share a mutable object
def memory_vault() -> dict[str, Callable[..., object]]:
    memories: dict[str, object] = {}

    def store(key: str, value: object) -> None:
        memories[key] = value

    def recall(key: str) -> object:
        return memories.get(key, NOT_FOUND)

    # a dict whose values are functions:
    return {"store": store, "recall": recall}


# test functions, which print their results
def test_mage_counter() -> None:
    print(f"\n{COUNTER_HEADER}")
    counter_a: Callable[[], int] = mage_counter()
    counter_b: Callable[[], int] = mage_counter()
    for i in range(1, 3):
        print(f"counter_a call {i}: {counter_a()}")
    print(f"counter_b call 1: {counter_b()}")


def test_spell_accumulator() -> None:
    print(f"\n{ACCUMULATOR_HEADER}")
    accumulator: Callable[[int], int] = spell_accumulator(100)
    for amount in test_powers:
        print(f"Base 100, add {amount}: {accumulator(amount)}")


def test_enchantment_factory() -> None:
    print(f"\n{ENCHANTMENT_HEADER}")
    for enchantment in test_enchantments:
        factory: Callable[[str], str] = enchantment_factory(enchantment)
        for item in test_items:
            print(factory(item))


def test_memory_vault() -> None:
    print(f"\n{VAULT_HEADER}")
    vault: dict[str, Callable[..., object]] = memory_vault()
    store: Callable[..., object] = vault["store"]
    recall: Callable[..., object] = vault["recall"]

    store("secret", 42)
	store("job", 21)
	store("hut", 33)
    print("Store 'secret' = 42")
	print("")
    print(f"Recall 'secret': {recall('secret')}")
    print(f"Recall 'unknown': {recall('unknown')}")


def main() -> None:
    print(f"\n{TITLE}")
    print("=" * len(TITLE))
    test_mage_counter()
    test_spell_accumulator()
    test_enchantment_factory()
    test_memory_vault()
    print()


if __name__ == "__main__":
    main()
