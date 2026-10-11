#!/usr/bin/env python3

import typing
import random

players = [
    "alice", "bob", "charlie", "dylan"
]

actions = [
    "run", "eat", "sleep", "grab", "move", "climb", "swim", "release", "use"
]


def gen_event() -> typing.Generator[tuple[str, str], None, None]:
    while True:
        yield (random.choice(players), random.choice(actions))


def consume_event(
    events: list[tuple[str, str]]
) -> typing.Generator[tuple[str, str], None, None]:
    while events:
        to_remove = random.randint(0, len(events) - 1)
        yield events.pop(to_remove)


def main() -> None:
    print("=== Game Data Stream Processor ===")
    event = gen_event()
    for i in range(1000):
        name, action = next(event)
        print(f"Event {i}: Player {name} did action {action}")
    events: list[tuple[str, str]] = []
    for i in range(10):
        # events += [next(event)]
        events.append(next(event))
    print("Built list of 10 events:", events)
    removed = consume_event(events)
    for r in removed:
        print(f"Got event from list: {r}")
        print(f"Remains in list: {events}")


if __name__ == "__main__":
    main()
