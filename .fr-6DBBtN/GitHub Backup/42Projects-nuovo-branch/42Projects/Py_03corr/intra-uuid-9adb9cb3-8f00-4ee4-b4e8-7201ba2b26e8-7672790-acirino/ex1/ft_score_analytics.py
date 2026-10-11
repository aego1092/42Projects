import sys

"""
Some analytics for numbers given via command line
"""


def main() -> None:
    print("=== Player Score Analytics ===")
    scores: list[int] = []
    for arg in sys.argv[1:]:
        try:
            scores += [int(arg)]
        except ValueError:
            print(f"Invalid parameter: '{arg}'")
    if len(scores) == 0:
        print(
            "No scores provided.",
            "Usage: python3 ft_score_analytics.py <score1> <score2> ...",
        )
    else:
        print(
            "Scores processed",
            scores,
            "\nTotal players:",
            len(scores),
            "\nTotal score:",
            sum(scores),
            "\nAverage score:",
            sum(scores) / len(scores),
            "\nHigh score:",
            max(scores),
            "\nLow score:",
            min(scores),
            "\nScore range:",
            max(scores) - min(scores),
        )


if __name__ == "__main__":
    main()
