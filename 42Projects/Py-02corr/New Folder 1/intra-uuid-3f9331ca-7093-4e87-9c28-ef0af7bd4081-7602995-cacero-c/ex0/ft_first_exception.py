#!/usr/bin/env python3

def input_temperature(temp_str: str) -> int:
    return int(temp_str)


def test_temperature() -> None:
    print('=== Garden Temperature ===')

    test_1: str = '25'
    print(f"Input data is '{test_1}'")
    try:
        temp_1: int = input_temperature(test_1)
        print(f'Temperature is now {temp_1}°C')
    except ValueError as e:
        print(f'Caught input_temperature error: {e}')

    test_2: str = 'abc'
    print(f"Input data is '{test_2}'")
    try:
        temp_2: int = input_temperature(test_2)
        print(f'Temperature is now {temp_2}°C')
    except ValueError as e:
        print(f'Caught input_temperature error: {e}')

    print('All tests completed - program didn\'t crash!')


if __name__ == '__main__':
    test_temperature()
