#!/usr/bin/env python3

def input_temperature(temp_str: str) -> int:
    return (int(temp_str))

def test_temperature() -> str:
    """ data validation layer must filter out bad data before it corrupts your
    agricultural analytics"""
    print("=== Garden Temperature ===")

    try:
        t = input("Input data is ")
        if int(t) > -274 and int(t) < 1.4e32:
            print(f"\033[A\rInput data is '{t}'")
            # \033[A sposta il cursore in alto di una riga
            # \r riporta il cursore all'inizio della riga per sovrascriverla
            print(f"Temperature is now {t}{chr(176)}C")
        else:
            raise ValueError(f'Caught input_temperature error: {t}')
    
    except TypeError as e:
        print(f"Caught input_temperature error: invalid literal for int() with base 10: '{t}'")
    

# try:
    
#     risultato = 10 / numero
#     print(f"Risultato: {risultato}")

# except ZeroDivisionError:
#     # Si attiva se l'utente inserisce 0
#     print("Errore: Impossibile dividere per zero!")

# except ValueError:
#     # Si attiva se l'utente inserisce testo al posto di un numero (es. "ciao")
#     print("Errore: Devi inserire un numero valido.")

# except Exception as e:
#     # Cattura qualsiasi altro errore non previsto e salva il messaggio di errore nella variabile 'e'
#     print(f"Si è verificato un errore inaspettato: {e}")



if __name__ == '__main__':
    test_temperature()
    