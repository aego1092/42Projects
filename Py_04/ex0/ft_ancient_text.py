#!/usr/bin/env python3

import sys
import typing


def ft_ancient_text() -> None:
    if len(sys.argv) == 1:
        print(f"Usage {sys.argv[0]} <filename>")
    elif len(sys.argv) == 2:
        print("=== Cyber Archives Recovery ===")
        print(f"Accessing file '{sys.argv[1]}'")
        file_object: typing.Optional[typing.IO[str]] = None
        try:
            file_object = open(sys.argv[1], "r")
            try:
                content: str = file_object.read()
                print("---\n")
                print(content)
                print("\n---")
            except Exception as e:
                print(f"Error reading file '{sys.argv[1]}': {e} ")
        except OSError as e:
            # OSError
            # FileNotFoundError
            # PermissionError
            # IsADirectoryError
            print(f"Error opening file '{sys.argv[1]}': {e}")

        finally:
            if file_object is not None:
                try:
                    file_object.close()
                    print(f"File '{sys.argv[1]}' closed")
                except Exception as e:
                    print(f"Error closing file '{sys.argv[1]}': {e} ")

    else:

        print("Retry getting the name of ONE file at a time")


if __name__ == "__main__":
    ft_ancient_text()
