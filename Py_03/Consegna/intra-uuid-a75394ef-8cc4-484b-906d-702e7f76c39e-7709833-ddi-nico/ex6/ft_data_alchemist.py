#!/usr/bin/env python3

import random


def main() -> None:
    print("=== Game Data Alchemist ===")
    players = [
        "Alice", "bob", "Charlie", "dylan", "Emma", "Gregory", "john",
        "kevin", "Liam"
    ]
    print("\nInitial list of players:", players)
    full_cap = [player.capitalize() for player in players]
    only_cap = [player for player in players if player == player.capitalize()]
    print("New list with all names capitalized:", full_cap)
    print("New list of capitalized names only:", only_cap)

    score_dict = {p: random.randint(0, 1000) for p in full_cap}
    avg = sum(score_dict[p] for p in score_dict) / len(score_dict)
    high_scores = {p: score_dict[p] for p in score_dict if score_dict[p] > avg}
    print("\nScore dict:", score_dict)
    print("Score average is ", round(avg, 2),)
    print("High scores:", high_scores)


if __name__ == "__main__":
    main()
