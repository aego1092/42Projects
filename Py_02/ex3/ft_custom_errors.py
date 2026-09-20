#!/usr/bin/env python3

class GardenError(Exception):
    """Produce GardenError message"""
    
    def __init__(self, message: str = 'Unknown plant error') -> None:
        self.message = message
        super().__init__(self.message)


class PlantError(GardenError):
    """Produce PlantError message"""

class WaterError(GardenError):
    """Produce WaterError message"""


def ft_test_custom_errors() -> None:
    errors: list[Exception] = [PlantError(), WaterError()]

    for i in range(len(errors)):
        print(f"Testing {errors[i].__class__.__name__}...")
        try:
            custom_exceptions(i)
            print("Operation completed successfully!")
        except Exception as e:
            print(f'Caught {e.__class__.__name__}: {e}')

    print(f"Testing catching all garden errors")
    for i in range(len(errors)):
        try:
            custom_exceptions(i)
        except GardenError as e:
            print(f'Caught {errors.__class__.__name__}: {e}')


def custom_exceptions(exception_number: int) -> None:
    if exception_number == 0:
        raise PlantError("The tomato plant is wilting!")
    elif exception_number == 1:
        raise WaterError("Not enough water in the tank!")
    else:
        return


if __name__ == '__main__':
    ft_test_custom_errors()
