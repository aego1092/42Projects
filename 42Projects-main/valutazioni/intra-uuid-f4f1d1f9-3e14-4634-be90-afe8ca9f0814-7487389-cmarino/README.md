*This project has been created as part of the 42 curriculum by <cmarino>, <mtyhach>.*

# push_swap

Progetto 42 — algoritmo di ordinamento di uno stack usando un numero minimo
di operazioni, con due stack (`a` e `b`) e un set ristretto di istruzioni.

##  Description

`push_swap` riceve in argomento una lista di interi e stampa sullo standard
output la sequenza di operazioni necessarie per ordinare quegli interi in
ordine crescente, usando solo due stack (`a` e `b`) e senza accesso diretto
agli elementi se non tramite le operazioni consentite.

L'obiettivo non è solo ordinare correttamente, ma farlo con **il minor
numero possibile di operazioni**, specialmente per input di grandi
dimensioni (100 e 500 elemenancorati sono i benchmark standard di valutazione).

## Regole del gioco

- Due stack: `a` (contiene inizialmente tutti i numeri) e `b` (vuoto
  all'inizio).
- Solo le operazioni elencate sotto possono spostare/modificare gli
  elementi.
- Numeri duplicati non sono ammessi.
- Se lo stack `a` è già ordinato, non deve essere stampato nulla.
- Ogni operazione va stampata su una riga separata (`\n` alla fine).

## Operazioni consentite

| Operazione | Effetto |
|---|---|
| `sa` | swap dei primi 2 elementi di `a` |
| `sb` | swap dei primi 2 elementi di `b` |
| `ss` | `sa` e `sb` insieme |
| `pa` | push dalla cima di `b` alla cima di `a` |
| `pb` | push dalla cima di `a` alla cima di `b` |
| `ra` | rotate `a`: il primo elemento diventa l'ultimo |
| `rb` | rotate `b`: il primo elemento diventa l'ultimo |
| `rr` | `ra` e `rb` insieme |
| `rra` | reverse rotate `a`: l'ultimo elemento diventa il primo |
| `rrb` | reverse rotate `b`: l'ultimo elemento diventa il primo |
| `rrr` | `rra` e `rrb` insieme |

## Build

```bash
make          # compila push_swap
make clean    # rimuove gli object file
make fclean   # rimuove anche l'eseguibile
make re       # fclean + make
```

## Instruction

```bash
./push_swap 5 1 4 2 3
```

Stampa la sequenza di operazioni sullo standard output.

Test su input casuali di grandi dimensioni:

```bash
ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
./push_swap $ARG
```

Conteggio delle operazioni generate:

```bash
./push_swap $ARG | wc -l
```

## Resources

### Documentation / references consulted

- 42 push_swap subject PDF (project specification)
- Classic sorting algorithm references for Selection Sort and Radix Sort
  (CLRS, *Introduction to Algorithms*)
- General discussions on stack-sorting and pancake-sort-style problems as
  background for choosing rotation strategies

## Architettura del progetto

```
push_swap.h                  prototipi condivisi, struct t_stack / t_bench
main.c                        entry point
parsing.c                     validazione e parsing degli argomenti
stack.c                       costruzione/gestione della struttura stack
normalize.c                   normalizza i valori di input in indici 0..n-1
compute_disorder.c            calcola il grado di disordine dello stack
operations_swap.c             sa / sb / ss
operations_push.c             pa / pb
operations_rotate.c           ra / rb / rr
operations_rev_rotate.c       rra / rrb / rrr
sort_tiny.c                   casi base: stack di 2, 3, 4, 5 elementi
sort_adaptive.c               dispatcher: sceglie la strategia in base al disorder
sort_simple.c                 Selection Sort (basso disordine)
sort_medium.c                 Chunk Sort (disordine medio)
sort_complex.c                Radix Sort (alto disordine)
benchmark.c                   misura operazioni/tempo
printf_fd.c                   printf minimale (output su file descriptor)
printf_fd_putfloat.c          gestione %f per printf_fd
printf_fd_utils.c             funzioni di supporto per printf_fd
utils.c                       funzioni di utilità generiche
args.txt                      set di argomenti di test
```

## Strategia di ordinamento

Il progetto implementa una **strategia adattiva**: `compute_disorder.c`
misura il grado di disordine dello stack, poi `sort_adaptive` sceglie
l'algoritmo interno più adatto, così da restare sempre entro un bound di
complessità coerente con quanto è effettivamente disordinato l'input.

| Disordine | Algoritmo | Complessità |
|---|---|---|
| `< 0.2` | Selection Sort (`sort_simple.c`) | O(n²) |
| `0.2 – 0.5` | Chunk Sort (`sort_medium.c`, bucket √n) | O(n√n) |
| `≥ 0.5` | Radix Sort (`sort_complex.c`) | O(n log n) |

Per stack con `size ≤ 5` si usa invece `sort_tiny.c`, che gestisce i casi
piccoli con sequenze di operazioni dirette — essendo `n` limitato a una
costante, il costo è O(1) e non influisce sul bound generale.

La documentazione completa (giustificazione delle soglie, tecniche interne
e argomento di complessità per ciascun regime) è in
[`ADAPTIVE_SORT.md`](./ADAPTIVE_SORT.md).

## Benchmark

`benchmark.c` esegue `push_swap` su input generati automaticamente (varie
dimensioni, vari livelli di disordine) e riporta numero di operazioni e
tempo di esecuzione, usando `printf_fd` per l'output formattato.

```bash
./benchmark
```

## Norminette

Il codice rispetta le norme di stile 42:

- indentazione a tab
- funzioni max 25 righe
- max 5 variabili per funzione
- **max 5 funzioni per file** (`.c`) — per questo le operazioni sono
  divise su più file (`operations_swap.c`, `operations_push.c`,
  `operations_rotate.c`, `operations_rev_rotate.c`) e `printf_fd` è
  spezzato in `printf_fd.c`, `printf_fd_putfloat.c`, `printf_fd_utils.c`
- header standard 42 in ogni file

## Testing

```bash
# stack piccoli
./push_swap 2 1
./push_swap 5 1 4 2 3

# stack grandi, input casuale
ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l

# nessun output se già ordinato
./push_swap 1 2 3 4 5

# controllo di righe non valide nell'output
./push_swap $ARG > ops.txt
grep -vE '^(sa|sb|ss|pa|pb|ra|rb|rr|rra|rrb|rrr)$' ops.txt
```

