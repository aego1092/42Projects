#!/usr/bin/env python3

import sys
import typing


def ft_ancient_text() -> None:
    if len(sys.argv) == 1:
        print(f"Usage: {sys.argv[0]} <filename>")
    elif len(sys.argv) == 2:
        print("=== Cyber Archives Recovery & Preservation ===")
        print(f"Accessing file '{sys.argv[1]}'")
        file_object: typing.IO[str] | None = None
        success: bool = False
        try:
            file_object = open(sys.argv[1], "r")
            try:
                content: str = file_object.read()
                success = True
                print("---\n")
                print(content)
                print("\n---")
            except Exception as e:
                print(f"Error reading file '{sys.argv[1]}': {e}")
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
                    print(f"File '{sys.argv[1]}' closed.\n")
                except Exception as e:
                    print(f"Error closing file '{sys.argv[1]}': {e}")
        if success:
            ft_archive_creation(content)

    else:

        print("Retry getting the name of ONE file at a time")


def ft_archive_creation(content: str) -> None:
    file_object: typing.IO[str] | None = None
    temp_content: str = content
    if temp_content and not temp_content.endswith("\n"):
        temp_content += "\n"
    new_content: str = temp_content.replace("\n", "#\n")

    print("Transform data:\n---\n")
    print(new_content)
    print("---")

    save_filename: str = input("Enter new file name (or empty): ").strip()
    if save_filename:
        print(f"Saving data to '{save_filename}'")
        try:
            file_object = open(save_filename, "w")
            try:
                file_object.write(new_content)
                print(f"Data saved in file '{save_filename}'.")
            except Exception as e:
                print(f"Error writing file '{save_filename}': {e}")
        except OSError as e:
            print(f"Error opening file '{save_filename}': {e}")

        finally:
            if file_object is not None:
                try:
                    file_object.close()
                except Exception as e:
                    print(f"Error closing file '{save_filename}': {e}")
    else:
        print("Not saving data.")


if __name__ == "__main__":
    ft_ancient_text()
