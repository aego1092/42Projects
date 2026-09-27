# import typing
# import random

# """
# Ex. on Generators
# """

# players = [
#     "alice",
#     "bob",
#     "charlie",
#     "dilan",
# ]

# actions = [
#     "run",
#     "eat",
#     "sleep",
#     "grab",
#     "move",
#     "climb",
#     "swim",
#     "release",
#     "use",
#     "swim",
#     "move",
# ]


# def gen_event() -> typing.Generator[tuple[str, str], None, None]:
#     while True:
#         yield (random.choice(players), random.choice(actions))


# def consume_event(
#     events: list[tuple[str, str]]
# ) -> typing.Generator[tuple[str, str], None, None]:
#     while events:
#         to_remove = random.randint(0, len(events) - 1)
#         event = events[to_remove]
#         # The start index is included, the end index is not
#         events[:] = events[:to_remove] + events[to_remove + 1:]
#         yield event


# def main() -> None:
#     print("=== Game Data Stream Processor ===")
#     event = gen_event()
#     for i in range(1000):
#         name, action = next(event)
#         print(f"Event {i}: Player {name} did the action {action}")
#     events: list[tuple[str, str]] = []
#     for i in range(10):
#         events += [next(event)]
#     print("Built list of 10 events:", events)
#     removed = consume_event(events)
#     for r in removed:
#         print(
#             "Got event from list:",
#             r,
#             "\nRemains in list:",
#             events,
#         )


# if __name__ == "__main__":
#     main()
