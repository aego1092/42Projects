#!/usr/bin/env python3

import math


def get_player_pos() -> tuple[float, float, float]:
    while True:
        new_player_str_coordinate = input("Enter new coordinates as floats "
                                          "in format 'x,y,z': ")
        try:
            x_in, y_in, z_in = new_player_str_coordinate.split(sep=",")
            try:
                bad_coordinate = x_in
                x = float(x_in)
                # float() rimuove automaticamente tutti gli spazi bianchi
                # (spazi,tabulazioni \t, caratteri di a capo \n) presenti
                # a inizio e fine stringa prima di convertirla in numero.
                bad_coordinate = y_in
                y = float(y_in)
                bad_coordinate = z_in
                z = float(z_in)
                new_player_float_coordinates: tuple[float, float, float] = \
                    (x, y, z)
                return new_player_float_coordinates
            except ValueError as e:
                print(f"Error on parameter '{bad_coordinate}':", e)
        except ValueError:
            print("Invalid syntax")


def ft_coordinate_system() -> None:
    print("=== Game Coordinate System ===\n")
    print("Get a first set of coordinates")
    x_1, y_1, z_1 = get_player_pos()
    dist_to_center = round(math.sqrt((x_1) ** 2 + (y_1) ** 2 + (z_1) ** 2), 4)
    print(f"Got a first tuple: ({x_1}, {y_1}, {z_1})\n"
          f"It includes: X={x_1}, Y={y_1}, Z={z_1}\n"
          f"Distance to center: {dist_to_center}\n")
    print("Get a second set of coordinates")
    x_2, y_2, z_2 = get_player_pos()
    module = ((x_2 - x_1) ** 2 + (y_2 - y_1) ** 2 + (z_2 - z_1) ** 2) ** 0.5
    print(f"Distance between the 2 sets of coordinates: "
          f"{module:.4f}")


if __name__ == "__main__":
    ft_coordinate_system()
