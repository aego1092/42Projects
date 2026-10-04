#!/usr/bin/env python3
import sys
from typing import Dict, List


def ft_inventory_system() -> None:
    arg: List[str] = sys.argv[1:]
    dict_data: Dict[str, int] = {}
    for a in arg:
        x: List[str] = a.split(sep=":")
        if len(x) != 2:
            print(f"Error - invalid parameter '{a}'")
            continue
        try:
            if x[0] not in dict_data.keys():
                dict_data[x[0]] = int(x[1])
            else:
                print(f"Redundant item '{x[0]}' - discarding")
        except ValueError as e:
            print(f"Quantity error for 'key': {e}")
    l_key = dict_data.keys()
    l_value = dict_data.values()
    print(f"Got inventory: {dict_data}")
    print(f"Item list: {list(l_key)}")

    if not dict_data:
        print("Asshole! You have no inventory.")
        print("Come back with something to process.")
        return

    # tot: int = 0
    # for value in l_value:
    #     tot += value
    tot = sum(dict_data.values())
    print(f"Total quantity of the {len(dict_data)} items: {tot}")
    for key, value in dict_data.items():
        # print(f"Item {key} represents {value/tot*100:.1f}%")
        print(f"Item {key} represents {round(value/tot*100,1)}%")
    # print(
    #     f"Item most abundant: {max(dict_data, key=dict_data.get)}"
    #     f" with quantity {max(l_value)}"
    # )
    print(
        f"Item most abundant: "
        f"{max(dict_data, key=lambda k: dict_data.get(k, 0))}"
        f" with quantity {max(l_value)}"
    )
    # print(
    #     f"Item least abundant: {min(dict_data, key=dict_data.get)}"
    #     f" with quantity {min(l_value)}"
    # )
    print(
        f"Item least abundant: "
        f"{min(dict_data, key=lambda k: dict_data.get(k, 0))}"
        f" with quantity {min(l_value)}"
    )

    # dict_data['magic_item'] = 1
    dict_data.update({'magic_item': 1})
    print(f"Updated inventory: {dict_data}")
    return


if __name__ == "__main__":
    ft_inventory_system()
