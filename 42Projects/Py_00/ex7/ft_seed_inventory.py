def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    if unit not in ("packets", "grams", "area"):
        print("Unknown unit type")
        return
    else:
        seed_type_formatted: str = seed_type.capitalize()
        if unit == "packets":
            qty_units: str = f"{quantity} packets available"
        elif unit == "grams":
            qty_units = f"{quantity} grams total"
        elif unit == "area":
            qty_units = f"covers {quantity} square meters"
        print(f"{seed_type_formatted} seeds: {qty_units}")
