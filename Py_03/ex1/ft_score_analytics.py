#!/usr/bin/env python3

import sys


def ft_score_analytics() -> None:
    print("=== Player Score Analytics ===")

    game_scores: list[str] = sys.argv[1:]
    valid_scores: list[float] = []
    invalid_scores: list[str] = []
    if not game_scores:
        print("No scores provided. Usage: python3 "
              "ft_score_analytics.py <score1> <score2> ...")
        return
    tot_valid_scores: int | float = 0
    for score in game_scores:
        try:
            valid_scores.append(int(score))
            tot_valid_scores += int(score)
        except ValueError:
            try:
                valid_scores.append(float(score))
                tot_valid_scores += float(score)
            except ValueError:
                invalid_scores.append(score)
    if invalid_scores:
        for i in range(len(invalid_scores)):
            print(f"Invalid parameter: '{invalid_scores[i]}'")
        print("No scores provided. Usage: python3"
              "ft_score_analytics.py <score1> <score2> ...")
        return

    print(f"Total palyers: {len(valid_scores)}")
    print(f"Total score: {tot_valid_scores}")
    print(f"Average score: {tot_valid_scores / len(valid_scores)}")
    print(f"High score: {max(valid_scores)}")
    print(f"Low score: {min(valid_scores)}")
    print("Score range:", max(valid_scores) - min(valid_scores))


if __name__ == "__main__":
    ft_score_analytics()
