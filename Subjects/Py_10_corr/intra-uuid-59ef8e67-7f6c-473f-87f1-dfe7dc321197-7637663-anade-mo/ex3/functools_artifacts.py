#! /usr/bin/env python3

"""functools treasures: reduce, partial, lru_cache and singledispatch.

Concepts learned:
 Functools is a standard library module that provides higher-order functions:

 reduce -> a function that takes a list and reduces it to a single value by
 applying a mathematical operation cumulatively to the items in the list.

 partial -> when you don't need to call a function with all its arguments
 but still want to use it as a callable, you then create a new function
 with some arguments already filled in.

 lru_cache -> a decorator that caches the results of a function, so that
 if the function is called again with the same arguments, the cached result
 is returned instead of recomputing it. caches needs to be handled with care.

 singledispatch -> a decorator that allows you to define a function that can
 have different implementations based on the type of the first argument.

"""

import operator
from collections.abc import Callable
from functools import lru_cache, partial, reduce, singledispatch
from typing import Any

# operations for spell_reducer
OPS: dict[str, Callable[[int, int], int]] = {
    "add": operator.add,            # an operator function
    "multiply": operator.mul,       # an operator function
    "max": max,                     # a built-in function
    "min": min,                     # a built-in function
}

# test data
ELEMENTS: list[str] = [
    "fire", "ice", "lightning", "earth",
    "wind", "water", "light", "shadow",
]
spell_powers: list[int] = [12, 45, 8, 30, 21, 17]
operations: list[str] = ["add", "multiply", "max", "min"]
fibonacci_tests: list[int] = [0, 1, 10, 15, 20]

# output formatting constants
TITLE: str = "functools Treasures: reduce, partial and singledispatch"
REDUCER_HEADER: str = "Testing spell reducer..."
PARTIAL_HEADER: str = "Testing partial enchanter..."
FIB_HEADER: str = "Testing memoized fibonacci..."
DISPATCH_HEADER: str = "Testing spell dispatcher..."


def spell_reducer(spells: list[int], operation: str) -> int:
    if not spells:
        return 0
    if operation not in OPS:
        raise ValueError(f"Unknown operation: {operation}")
    return reduce(OPS[operation], spells)


def enchant_str(power: int, element: str, target: str) -> str:
    return f"{target} is enriched with {element} at power {power}"


def partial_enchanter(base_enchantment: Callable[[int, str, str], str]
                      ) -> dict[str, Callable[[str], str]]:
    if not callable(base_enchantment):
        raise TypeError("base_enchantment must be callable")

    def partial_factory(element: str) -> Callable[[str], str]:
        return partial(base_enchantment, 50, element)

    return {element: partial_factory(element) for element in ELEMENTS[:3]}


# a decorator is a function that takes another function as an argument
# and returns a new function that adds some functionality to it.
@lru_cache(maxsize=512)
def memoized_fibonacci(n: int) -> int:
    if n < 2:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:
    # same function name, different type = different implementation.
    # type checking is at runtime.
    @singledispatch
    def cast(spell: Any) -> str:
        return "Unknown spell type"

    @cast.register
    def _(spell: int) -> str:
        return f"Damage spell: {spell} damage"

    @cast.register
    def _(spell: str) -> str:
        return f"Enchantment: {spell}"

    @cast.register(list)
    def _(spell: list[Any]) -> str:
        return f"Multi-cast: {len(spell)} spells"

    return cast


def test_spell_reducer(powers: list[int]) -> None:
    print(f"\n{REDUCER_HEADER}")
    print(f"Powers: {powers}")
    for operation in operations:
        print(f"{operation.capitalize()}: "
              f"{spell_reducer(powers, operation)}")
    print(f"Empty list: {spell_reducer([], 'add')}")
    try:
        spell_reducer(powers, "divide")
    except ValueError as error:
        print(f"{error}")


def test_spell_dispatcher(dispatcher: Callable[[Any], str]) -> None:
    print(f"\n{DISPATCH_HEADER}")
    test_spells: list[Any] = [42, "fireball", ["ice", "wind"], 3.14]
    for spell in test_spells:
        print(dispatcher(spell))


def test_partial_enchanter(enchanter: dict[str, Callable[[str], str]]
                           ) -> None:
    print(f"\n{PARTIAL_HEADER}")
    for element, func in enchanter.items():
        print(func("Dragon"))
    for element in ELEMENTS[:3]:
        print(enchant_str(75, element, "Phoenix"))


def test_memoized_fibonacci() -> None:
    print(f"\n{FIB_HEADER}")
    for n in fibonacci_tests:
        print(f"Fib({n}): {memoized_fibonacci(n)}")
    print(memoized_fibonacci.cache_info())


def main() -> None:
    print(TITLE)
    print("=" * len(TITLE))
    test_spell_reducer(spell_powers)
    test_partial_enchanter(partial_enchanter(enchant_str))
    test_memoized_fibonacci()
    test_spell_dispatcher(spell_dispatcher())


if __name__ == "__main__":
    main()
