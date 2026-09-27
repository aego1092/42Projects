import sys


"""
Use a dict to store an inventory from command line arg
"""


def main() -> None:
    print("=== Inventory System Analysis ===")
    inventory: dict[str, int] = dict()
    inventory_parserer(inventory)
    print(
        "Got inventory:",
        inventory,
        "\nItem list:",
        list(inventory.keys()),
        f"\nTotal quantity of the {len(inventory.keys())} items:",
        sum(inventory.values()),
    )
    total = sum(inventory.values())
    if not total == 0:
        for key in inventory:
            value = inventory[key]
            print(
                    f"Item {key} represents",
                    f"{round(100 * value / total, 1)}%"
                    )
        dict_show_maxmin(inventory)
    inventory.update({"magic_item": 1})
    print("Updated inventory:", inventory)


def inventory_parserer(inventory: dict[str, int]) -> None:
    for arg in sys.argv[1:]:
        try:
            key, value_str = arg.split(":")
            if key == "":
                raise ValueError
            try:
                value = int(value_str)
                if key in inventory.keys():
                    print(f"Redundant item '{key}' - discarding")
                else:
                    if value > 0:
                        inventory[key] = value
                    else:
                        print(f"Impossible value {value} - discarding")
            except ValueError as e:
                print(f"Quantity error for '{key}':", e)
        except ValueError:
            print(f"Error - invalid parameter '{arg}'")


def dict_show_maxmin(inventory: dict[str, int]) -> None:
    max_key: str = ""
    min_key: str = ""
    for key in inventory:
        if not max_key or inventory[max_key] < inventory[key]:
            max_key = key
        if not min_key or inventory[min_key] > inventory[key]:
            min_key = key
    print(f"Item most abundant: {max_key} with quantity", inventory[max_key])
    print(f"Item least abundant: {min_key} with quantity", inventory[min_key])


if __name__ == "__main__":
    main()
