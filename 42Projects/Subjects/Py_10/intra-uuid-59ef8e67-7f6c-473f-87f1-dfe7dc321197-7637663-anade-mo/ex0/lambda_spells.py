#! /usr/bin/env python3

"""Lambda mastery: sorting, filtering, mapping and reducing artifacts.

Concepts learned:
 Lambda expressions are anonymous, one line funcions.
 Tehr can be defined inside a function call:
 lambda argument, argument: expression
 'lambda' -> The keyword that signifies the start of a lambda function.
 'arguments' -> A comma-separated list of parameters the function takes.
 ':' The colon separates the arguments from the expression.
 'expression' -> A single expression that is evaluated and its result
 is returned.
 sorted(), filter(), map(), min() and max().
 key= is a parameter from sorted(), filter(), map(), min() and max()
 that takes a function to extract the value by which to sort, filter,
 map or reduce the data.


"""

from collections.abc import Callable
from typing import Any


# output formatting constants
TITLE: str = "Lambda Mastery: Sorting, Filtering, Mapping and Reducing"

# short keys so they double as labels in the output.
HEADERS: dict[str, str] = {
    "sort": "Testing artifact sorter...",
    "filter": "Testing power filter...",
    "map": "Testing spell transformer...",
    "stats": "Testing mage stats...",
}

# labels for the stats dictionary returned by mage_stats()
STAT_LABELS: dict[str, str] = {
    "max_power": "Max Power",
    "min_power": "Min Power",
    "avg_power": "Avg Power",
}

# appling lambda expressions to format the output of the test functions.
FORMATTERS: dict[str, Callable[[Any], str]] = {
    "named": lambda item: f"{item['name']} ({item['power']} power)",
    "spell": lambda item: str(item),
    "power": lambda item: f"Spell power: {item}",
    "stat": lambda item: f"{STAT_LABELS[item[0]]}: {item[1]}",
}

# test data for artifacts
test_artifacts: list[dict[str, Any]] = [
    {"name": "Crystal Orb", "power": 72, "type": "focus"},
    {"name": "Shadow Blade", "power": 118, "type": "weapon"},
    {"name": "Earth Shield", "power": 95, "type": "armor"},
    {"name": "Storm Crown", "power": 84, "type": "relic"},
]

# test data for mages
test_mages: list[dict[str, Any]] = [
    {"name": "Luna", "power": 91, "element": "ice"},
    {"name": "Kai", "power": 67, "element": "lightning"},
    {"name": "Ember", "power": 84, "element": "fire"},
    {"name": "Rowan", "power": 58, "element": "earth"},
]

# test data for spells
test_spells: list[str] = ["fireball", "heal", "blizzard", "shield"]


def artifact_sorter(artifacts: list[dict[str, Any]]) -> list[dict[str, Any]]:
    # sorted() builds a NEW sorted list, key= is a lambda function
    # that returns the value to sort by.
    return sorted(
        artifacts,
        key=lambda artifact: artifact["power"],
        reverse=False,
    )


def power_filter(
    mages: list[dict[str, Any]], min_power: int
) -> list[dict[str, Any]]:
    # filter() keeps the rows for which the lambda returns True;
    # list() converts the iterator to a list.
    return (list(filter(lambda mage: mage["power"] >= min_power, mages)))


def spell_transformer(spells: list[str]) -> list[str]:
    # map() builds a NEW list transforming each spell name.
    # list() converts the iterator to a list.
    return list(map(lambda spell: f"@@{spell}@@", spells))


def mage_stats(mages: list[dict[str, Any]]) -> dict[str, Any]:
    try:
        max_mage = max(mages, key=lambda m: m["power"])
        min_mage = min(mages, key=lambda m: m["power"])
        avg_power = round(
            sum(map(lambda m: m["power"], mages)) / len(mages), 2
        )
    except ValueError as error:
        # max() min() raises on an empty list, before the division can run.
        print(f"Error calculating mage stats: {error}")
        return {"max_power": 0, "min_power": 0, "avg_power": 0.0}
    return {
        "max_power": max_mage["power"],
        "min_power": min_mage["power"],
        "avg_power": avg_power,
    }


# I wanted to apply the lambda expressions to format the output of the
# test functions, so I created a show() function that takes a list of
# elements and a string_maker function that formats each element for
# printing in a str.

def show(elements: list[Any], string_maker: Callable[[Any], str]) -> None:
    # a lambda function that takes an element and creates a string.
    for element in elements:
        print(string_maker(element))


# Here is a wrapper function for a case where lambda was not appropriate,
# because the test functions are multi-statement.
def run_tests(functions: list[Callable[[], None]]) -> None:
    for test_function in functions:
        test_function()
        print()


def test_artifact_sorter() -> None:
    print(HEADERS["sort"])
    print("Artifacts List:")
    show(test_artifacts, FORMATTERS["named"])
    print("Sorting artifacts by power (descending):")
    sorted_artifacts = artifact_sorter(test_artifacts)
    print("Sorted Artifacts:")
    show(sorted_artifacts, FORMATTERS["named"])


def test_power_filter() -> None:
    print(HEADERS["filter"])
    print()
    print("Mages List:")
    show(test_mages, FORMATTERS["named"])
    min_power = 80
    print(f"Filtering mages with power >= {min_power}")
    print()
    filtered_mages = power_filter(test_mages, min_power)
    print("Filtered Mages:")
    show(filtered_mages, FORMATTERS["named"])


def test_spell_transformer() -> None:
    print(HEADERS["map"])
    print()
    print("Original Spells:")
    show(test_spells, FORMATTERS["spell"])
    print()
    transformed_spells = spell_transformer(test_spells)
    print("Transformed Spells:")
    show(transformed_spells, FORMATTERS["spell"])


def test_mage_stats() -> None:
    print(HEADERS["stats"])
    print()
    print("Mages List:")
    show(test_mages, FORMATTERS["named"])
    print()
    stats = mage_stats(test_mages)
    print("Mage Stats:")
    show(list(stats.items()), FORMATTERS["stat"])


test_functions: list[Callable[[], None]] = [
    test_artifact_sorter,
    test_power_filter,
    test_spell_transformer,
    test_mage_stats,
]


def main() -> None:
    print(TITLE)
    print("=" * len(TITLE))
    print()
    run_tests(test_functions)


if __name__ == "__main__":
    main()
