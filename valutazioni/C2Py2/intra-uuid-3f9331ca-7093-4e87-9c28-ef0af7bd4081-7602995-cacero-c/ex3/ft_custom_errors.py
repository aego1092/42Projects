#!/usr/bin/env python3

class GardenError(Exception):

    def __init__(self, message: str = 'Unknown garden error') -> None:
        super().__init__(message)


class PlantError(GardenError):

    def __init__(self, message: str = 'Unknown plant error') -> None:
        super().__init__(message)


class WaterError(GardenError):

    def __init__(self, message: str = 'Unknown water error') -> None:
        super().__init__(message)


def simulate_garden(scenario: int) -> None:
    if scenario == 1:
        raise PlantError('The tomato plant is wilting!')
    if scenario == 2:
        raise WaterError('Not enough water in the tank!')


def test_custom_errors() -> None:
    print('=== Custom Garden Errors Demo ===')

    print('Testing PlantError...')
    try:
        simulate_garden(1)
    except PlantError as e:
        print(f'Caught PlantError: {e}')

    print('Testing WaterError...')
    try:
        simulate_garden(2)
    except WaterError as e:
        print(f'Caught WaterError: {e}')

    print('Testing catching all garden errors...')
    for scenario_num in [1, 2]:
        try:
            simulate_garden(scenario_num)
        except GardenError as e:
            print(f'Caught GardenError: {e}')

    print('All custom error types work correctly!')


if __name__ == '__main__':
    test_custom_errors()
