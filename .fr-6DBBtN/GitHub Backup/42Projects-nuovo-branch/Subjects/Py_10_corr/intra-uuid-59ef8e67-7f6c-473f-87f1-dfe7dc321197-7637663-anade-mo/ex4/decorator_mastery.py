#! /usr/bin/env python3

"""Decorators: wrappers that change what a function does around it.

Concepts learned:
 All decorators add functionality to a function without changing its code.
 It`s usefull to create a decorator when you want to apply that feature
 multiple functions.


"""

import functools
import time
from collections.abc import Callable
from typing import Any

# A decorator takes any function at all and hands back a replacement,
# so `...` (any arguments) and Any are the honest annotation here -
# the wrapper cannot promise the shape of whatever it wraps.
AnyFunc = Callable[..., Any]


# constants for output formatting and test data
CASTING: str = "Casting {name}..."
COMPLETED: str = "Spell completed in {seconds:.3f} seconds"
NO_POWER: str = "Insufficient power for this spell"
RETRYING: str = "Spell failed, retrying... (attempt {n}/{total})"
ALL_FAILED: str = "Spell casting failed after {total} attempts"
SUCCESS: str = "Successfully cast {spell} with {power} power"

# inputs for the test functions
GUILD_MIN_POWER: int = 10
MIN_NAME_LENGTH: int = 3
test_powers: list[int] = [25, 14, 38, 9]
test_spells: list[str] = ["fireball", "heal", "shield", "blizzard"]
valid_names: list[str] = ["Alex", "Jordan", "Riley"]
invalid_names: list[str] = ["Jo", "A", "Alex123", "Test@Name"]


# output formatting constants
TITLE: str = "Decorator Mastery: Timing, Validation and Retries"
TIMER_HEADER: str = "Testing spell timer..."
VALIDATOR_HEADER: str = "Testing power validator..."
RETRY_HEADER: str = "Testing retrying spell..."
GUILD_HEADER: str = "Testing MageGuild..."


# common use for decorators: time how long a function takes to run.
def spell_timer(func: AnyFunc) -> AnyFunc:
    @functools.wraps(func)
    def wrapper(*args: Any, **kwargs: Any) -> Any:
        print(CASTING.format(name=func.__name__))
        start = time.perf_counter()
        result = func(*args, **kwargs)
        print(COMPLETED.format(seconds=time.perf_counter() - start))
        return result
    return wrapper


# common use for decorators: validate arguments before call.
def power_validator(min_power: int) -> Callable[[AnyFunc], AnyFunc]:
    # wrap a function to check its power argument against min_power
    def decorator(func: AnyFunc) -> AnyFunc:
        @functools.wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            power = kwargs["power"] if "power" in kwargs else args[-1]
            if power < min_power:
                return NO_POWER
            return func(*args, **kwargs)
        return wrapper
    return decorator


# common use for decorators: retry a function if it raises an exception.
def retry_spell(max_attempts: int) -> Callable[[AnyFunc], AnyFunc]:
    def decorator(func: AnyFunc) -> AnyFunc:
        @functools.wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            for attempt in range(1, max_attempts + 1):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    if attempt < max_attempts:
                        print(RETRYING.format(n=attempt, total=max_attempts))
            return ALL_FAILED.format(total=max_attempts)

        return wrapper
    return decorator


class MageGuild:

    # validate a value directly.
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        if len(name) < MIN_NAME_LENGTH:
            return False
        return all(char.isalpha() or char.isspace() for char in name)

    # validate the function call before it runs
    @power_validator(GUILD_MIN_POWER)
    def cast_spell(self, spell_name: str, power: int) -> str:
        return SUCCESS.format(spell=spell_name, power=power)


def slow_spell(target: str, power: int) -> str:
    time.sleep(0.1)  # stops the execution of this program for 0.1 seconds
    return f"Fireball hits {target} for {power} damage"


# the decorator can be used anywhere there is 'power'.
@power_validator(GUILD_MIN_POWER)
def guarded_spell(target: str, power: int) -> str:
    return f"Lightning strikes {target} for {power} damage"


def cursed_spell() -> str:
    raise ValueError("the spell backfires")


# a closure from the ex2 logic, to count the calls to test the retry decorator.
def make_flaky_spell() -> Callable[[], str]:
    attempts = 0

    def flaky_spell() -> str:
        nonlocal attempts
        attempts += 1
        if attempts < 2:
            raise ValueError("the spell wavers")
        return "Waaaaaaagh spelled !"

    return flaky_spell


def test_spell_timer() -> None:
    print(f"\n{TIMER_HEADER}")
    timed = spell_timer(slow_spell)
    print(f"Result: {timed('Dragon', test_powers[0])}")


def test_power_validator() -> None:
    print(f"\n{VALIDATOR_HEADER}")
    for power in (GUILD_MIN_POWER + 5, GUILD_MIN_POWER - 5):
        print(f"power {power}: {guarded_spell('Goblin', power)}")


def test_retry_spell() -> None:
    print(f"\n{RETRY_HEADER}")
    print(retry_spell(3)(cursed_spell)())
    print(retry_spell(3)(make_flaky_spell())())


def test_mage_guild() -> None:
    print(f"\n{GUILD_HEADER}")
    for name in valid_names + invalid_names:
        print(f"{name!r}: {MageGuild.validate_mage_name(name)}")
    guild = MageGuild()
    for power in (GUILD_MIN_POWER + 5, GUILD_MIN_POWER - 5):
        print(guild.cast_spell(test_spells[0], power))


def main() -> None:
    print(TITLE)
    print("=" * len(TITLE))
    test_spell_timer()
    test_power_validator()
    test_retry_spell()
    test_mage_guild()


if __name__ == "__main__":
    main()
