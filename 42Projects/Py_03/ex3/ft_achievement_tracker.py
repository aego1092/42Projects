# import random


# """
# Ex. on sets
# """


# achievements = [
#     "Crafting Genius",
#     "Strategist",
#     "World Savior",
#     "Speed Runner",
#     "Survivor",
#     "Master Explorer",
#     "Treasure Hunter",
#     "Unstoppable",
#     "First Steps",
#     "Collector Supreme",
#     "Untouchable",
#     "Sharp Mind",
#     "Boss Slayer",
#     "Hidden Path Finder",
# ]


# def gen_player_achievements() -> set[str]:
#     n = random.randint(5, 15)
#     player_set: set[str] = set()
#     while n:
#         player_set = set.union(player_set, {random.choice(achievements)})
#         n -= 1
#     return player_set


# def main() -> None:
#     print("=== Achievement Tracker System ===\n")
#     players = ["Alice", "Bob", "Charlie", "Dylan"]
#     # Creating a dict = { player: achievements of the player }
#     players_achiev = {player: gen_player_achievements() for player in players}
#     all_achiev: set[str] = set()
#     for p in players:
#         print(f"Player {p}: {players_achiev[p]}")
#         all_achiev = set.union(all_achiev, players_achiev[p])
#     print(f"\nAll distinct achievements: {all_achiev}")
#     common_achiev = all_achiev
#     for p in players:
#         common_achiev = set.intersection(common_achiev, players_achiev[p])
#     print(f"\nCommon achievements: {common_achiev}\n")
#     for p in players:
#         only_p = players_achiev[p]
#         for other in players:
#             if not other == p:
#                 only_p = set.difference(only_p, players_achiev[other])
#         print(f"Only {p} has: {only_p}")
#     print()
#     achievements_set: set[str] = {a for a in achievements}
#     for p in players:
#         print(
#                 p,
#                 "is missing:",
#                 set.difference(achievements_set, players_achiev[p])
#                 )


# if __name__ == "__main__":
#     main()
