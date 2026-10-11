# import math


# def get_player_pos() -> tuple[float, float, float]:
#     while True:
#         position = input("Enter new coordinates as floats in format 'x,y,z': ")
#         try:
#             x_str, y_str, z_str = position.split(",")
#             try:
#                 here = x_str
#                 x = float(x_str)
#                 here = y_str
#                 y = float(y_str)
#                 here = z_str
#                 z = float(z_str)
#                 return (x, y, z)
#             except ValueError as e:
#                 print(f"Error on parameter '{here}':", e)
#         except ValueError:
#             print("Invalid syntax")


# def main() -> None:
#     print("=== Game Coordinate System ===")
#     print("\nGet a first set of coordinates")
#     x, y, z = get_player_pos()
#     print(
#         f"Got a first tuple: ({x}, {y}, {z})",
#         f"\nIt includes: X={x}, Y={y}, Z={z}",
#         "\nDistance to center:",
#         round(math.sqrt((x) ** 2 + (y) ** 2 + (z) ** 2), 4),
#     )
#     print("\nGet a second set of coordinates")
#     x1, y1, z1 = get_player_pos()
#     print(
#         "Distance between the 2 sets of coordinates:",
#         round(math.sqrt((x - x1) ** 2 + (y - y1) ** 2 + (z - z1) ** 2), 4),
#     )


# if __name__ == "__main__":
#     main()