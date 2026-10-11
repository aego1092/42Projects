import random

"""
list and dictionary comprehensions
"""


def main() -> None:
    print("=== Game Data Alchemist ===")
    players = [
        "Alice",
        "bob",
        "Charlie",
        "dylan",
        "Emma",
        "Gregory",
        "john",
        "kevin",
        "Liam",
    ]
    print("\nInitial list of players:", players)
    full_cap = [player.capitalize() for player in players]
    only_cap = [player for player in players if player == player.capitalize()]
    print(
        "New list with all names capitalized:",
        full_cap,
        "\nNew list of capitalized names only:",
        only_cap,
    )
    score_dict = {player: random.randint(0, 1000) for player in players}
    avg = sum([score_dict[i] for i in score_dict]) / len(score_dict)
    high_scores = {p: score_dict[p] for p in score_dict if score_dict[p] > avg}
    print(
        "\nScore dict:",
        score_dict,
        "\nScore average is",
        round(avg, 2),
        "\nHigh scores:",
        high_scores,
    )


if __name__ == "__main__":
    main()
