# Compendio ft_printf — ripasso pre-valutazione

## 1. Sintassi `<stdarg.h>` (a memoria, con i tipi)

```c
void  va_start(va_list ap, last_arg);   // last_arg = ultimo parametro NOMINATO prima di ...
type  va_arg(va_list ap, type);          // macro: il tipo di ritorno è "parametrico"
void  va_end(va_list ap);
```

- Sono **macro**, non funzioni: solo per questo `va_arg` può avere un tipo di ritorno scelto a runtime/testualmente dal preprocessore.
- `va_start` deve ricevere l'ultimo parametro **nominato** della funzione variadica (quello subito prima di `...`). Sbagliarlo è undefined behavior.
- Nel progetto: `va_list *args` passato per **puntatore** tra le funzioni interne, perché `va_arg` muta lo stato interno della lista e passarla per valore non garantisce la propagazione al chiamante in modo portabile.

## 2. Default argument promotions (il concetto più insidioso)

- Avvengono **al momento della chiamata** (call site), fatte dal compilatore — NON dentro `va_arg`, NON dentro `<stdarg.h>`.
- Regola: `char`, `short` (con o senza segno) passati come argomenti variadici diventano sempre `int`. `float` diventa `double`.
- Conseguenza pratica: `va_arg(*args, char)` è undefined behavior. Serve sempre `va_arg(*args, int)` + cast a `char` **dopo** la lettura.
- `unsigned int` non ha questo problema: è già il tipo "finale", si legge direttamente.

## 3. Le funzioni di conversione — a memoria

### `%c`
```c
int ft_print_char(va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);      // int, non char! poi cast
	return (write(1, &c, 1));
}
```

### `%s`
```c
int ft_print_str(va_list *args)
{
	char	*str;
	int		len;

	str = va_arg(*args, char *);
	if (!str)
		return (write(1, "(null)", 6));  // NULL check sul VALORE dell'arg, non su stampa!
	len = 0;
	while (str[len])
	{
		if (write(1, &str[len], 1) < 0)
			return (-1);
		len++;
	}
	return (len);
}
```
⚠️ Non confondere: `if (!stampa)` in `ft_printf.c` controlla la **format string**. `if (!str)` qui controlla **l'argomento passato a `%s`**. Due NULL check indipendenti, su puntatori diversi.

### `%p`
```c
int ft_print_ptr(va_list *args)
{
	unsigned long	ptr;

	ptr = (unsigned long)va_arg(*args, void *);
	if (!ptr)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) == -1)
		return (-1);
	return (2 + ft_putnbr_base(ptr, "0123456789abcdef"));
}
```

### `%d` / `%i`
```c
int ft_print_nbr(va_list *args)
{
	int		n;
	int		count;
	long	nbr;                       // long, non int! evita overflow su INT_MIN

	n = va_arg(*args, int);
	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count++;
		nbr = -nbr;                    // sicuro solo perché nbr è long
	}
	return (count + ft_putnbr_base((unsigned long)nbr, "0123456789"));
}
```
⚠️ **Perché `long`**: `-INT_MIN` non è rappresentabile in `int` (overflow, UB). In `long` (64 bit) sì.

### `%u`, `%x`, `%X`, `%o` (bonus)
```c
int ft_print_unsigned(va_list *args)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	return (ft_putnbr_base((unsigned long)n, "0123456789"));
}
// %x  → base "0123456789abcdef"
// %X  → base "0123456789ABCDEF"
// %o  → base "01234567"
```

### `%%`
```c
int ft_print_percent(va_list *args)
{
	(void)args;                        // evita warning -Wunused-parameter
	return (write(1, "%", 1));
}
```

## 4. `ft_putnbr_base` — la funzione ricorsiva chiave

```c
int	ft_putnbr_base(unsigned long nbr, const char *base)
{
	unsigned long	base_len;
	int				count;
	int				ret;

	base_len = ft_strlen(base);
	count = 0;
	if (nbr >= base_len)
	{
		ret = ft_putnbr_base(nbr / base_len, base);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (write(1, &base[nbr % base_len], 1) == -1)
		return (-1);
	return (count + 1);
}
```

**Traccia mentale con `nbr=4000, base="0123456789"` (base_len=10):**
```
4000 → ricorsione su 400
  400 → ricorsione su 40
    40 → ricorsione su 4
      4 < 10 → caso base, NESSUNA ricorsione
      write('4')   ← PRIMA write eseguita
    write('0')      ← seconda (400 % 10)... aspetta, ricontrolla: 40%10=0
  write('0')         (400 % 10 = 0)
write('0')            (4000 % 10 = 0)
→ output: "4000"
```
**Concetto chiave**: la ricorsione SCENDE dividendo (calcola cifra più significativa per ultima), ma la write della cifra più significativa è la PRIMA a essere fisicamente eseguita (al fondo della ricorsione). Le write successive avvengono durante l'unwinding (risalita dello stack) — ecco perché l'ordine di stampa è corretto senza bisogno di un buffer temporaneo. Lo stack delle chiamate fa da "inversore" implicito.

## 5. Dispatcher — tabella di funzioni

```c
int	ft_print_dispatcher(const char *stampa, size_t *i, va_list *args)
{
	static const t_ptr_funct	conversion_list[256] = {
	['c'] = ft_print_char,
	['s'] = ft_print_str,
	['d'] = ft_print_nbr,
	['i'] = ft_print_nbr,
	['u'] = ft_print_unsigned,
	['x'] = ft_print_hex_low,
	['X'] = ft_print_hex_up,
	['p'] = ft_print_ptr,
	['%'] = ft_print_percent
	};

	if (conversion_list[(unsigned char)stampa[(*i)]] != NULL)
		return (conversion_list[(unsigned char)stampa[(*i)]](args));
	return (0);
}
```
- `static const`: tabella costruita **una sola volta** in tutto il programma, non ad ogni chiamata.
- Designated initializers (`['c'] = ...`): C99, inizializzano solo le posizioni citate; il resto è `NULL` automaticamente.
- Cast a `(unsigned char)`: **fondamentale** — su piattaforme dove `char` è signed, un carattere con bit alto a 1 diventerebbe un indice negativo → accesso fuori dai limiti dell'array. Il cast forza l'indice in range `[0,255]`.

## 6. Edge case da saper spiegare a voce

| Caso | Comportamento | Perché |
|---|---|---|
| `stampa == NULL` | ritorna `-1` subito | check esplicito in `ft_printf` |
| stringa senza `%` | un solo `write()` di tutta la stringa | fast path, meno syscall |
| `%` a fine stringa (`"abc%"`) | `%` ignorato, loop termina | check `if (stampa[i]=='\0') break;` **prima** del dispatcher — evita out-of-bounds read |
| conversione sconosciuta (`%z`) | dispatcher ritorna `0`, nulla stampato (versione base) | `conversion_list['z'] == NULL` |
| `%s` con arg `NULL` | stampa `"(null)"` | check interno a `ft_print_str`, NON collegato al check di `stampa` in `ft_printf.c` |
| `%p` con arg `NULL` | stampa `"(nil)"` | check interno a `ft_print_ptr` |
| `%d` con `INT_MIN` | funziona senza UB | copia in `long` prima di negare |
| write() fallisce | propagazione di `-1` a cascata fino a `ft_printf` | ogni funzione controlla il valore di ritorno di `write` |

## 7. Perché va_list per puntatore (`va_list *args`)

`va_arg` muta lo stato interno della `va_list` (fa avanzare il cursore). Passare `va_list` **per valore** tra funzioni non garantisce, in modo portabile, che l'avanzamento fatto dalla funzione chiamata sia visibile al chiamante dopo il return — dipende dall'implementazione della piattaforma (su alcune è un array che decade a puntatore, su altre è una struct scalare copiata per intero). Passare `&args` esplicitamente elimina l'ambiguità.

## 8. Norm / cose stilistiche da controllare prima della difesa

- Nessun `static` su funzioni chiamate da altri file (rompe il link).
- `(void)args;` dove un parametro non è usato, per evitare `-Wunused-parameter` con `-Werror`.
- Include coerenti: sempre `"ft_printf.h"` con virgolette, non `<ft_printf.h>`.
- Cast espliciti su indici di array da `char` (`(unsigned char)`).
