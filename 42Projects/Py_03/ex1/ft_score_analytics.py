#!/usr/bin/env python3

import sys


def ft_score_analytics() -> None:
    print("=== Player Score Analytics ===")
    
    game_scores: list[str] = sys.argv[1:]
    invalid_scores: list[str] = []
    if not game_scores:
        print("No scores provided. Usage: python3"
            "ft_score_analytics.py <score1> <score2> ...")
        return
    tot_game_scores: int = 0
    try:
        for i in range(len(game_scores)):
            game_scores[i] = int(game_scores[i])
            tot_game_scores += game_scores[i]
    except ValueError:
        try:
            for i in range(len(game_scores)):
                game_scores[i] = float(game_scores[i])
                tot_game_scores += game_scores[i]
        except:
            invalid_scores.append()
            for i in range(len(game_scores)):
                print(f"Invalid parameter: '{game_scores[i]}'")
                print("No scores provided. Usage: python3"
                    "ft_score_analytics.py <score1> <score2> ...")
                return

    print(f"Total palyers: {len(game_scores)}")
    print(f"Total score: {tot_game_scores}")
    print(f"Average score: {tot_game_scores / len(game_scores)}")
    print(f"High score: {max(game_scores)}")
    print(f"Low score: {min(game_scores)}")
    print("Score range:", max(game_scores) - min(game_scores))


if __name__ == "__main__":
    ft_score_analytics()


# import sys

# """
# Some analytics for numbers given via command line
# """


# def main() -> None:
#     print("=== Player Score Analytics ===")
#     scores: list[int] = []
#     for arg in sys.argv[1:]:
#         try:
#             scores += [int(arg)]
#         except ValueError:
#             print(f"Invalid parameter: '{arg}'")
#     if len(scores) == 0:
#         print(
#             "No scores provided.",
#             "Usage: python3 ft_score_analytics.py <score1> <score2> ...",
#         )
#     else:
#         print(
#             "Scores processed",
#             scores,
#             "\nTotal players:",
#             len(scores),
#             "\nTotal score:",
#             sum(scores),
#             "\nAverage score:",
#             sum(scores) / len(scores),
#             "\nHigh score:",
#             max(scores),
#             "\nLow score:",
#             min(scores),
#             "\nScore range:",
#             max(scores) - min(scores),
#         )


# if __name__ == "__main__":
#     main()