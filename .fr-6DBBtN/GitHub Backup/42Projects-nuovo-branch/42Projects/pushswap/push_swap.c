#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//SINGOLI ELEMENTI TABELLE
typedef struct s_node
{
	int             value;
	int             index;
	struct s_node   *next;
	struct s_node   *prev;
}   t_node;

//CONTENITORE TABELLE
typedef struct s_data
{
	t_node  *a;       // top della stack a
	int     size_a;
	t_node  *b;       // top della stack b
	int     size_b;
	// qui dopo aggiungeremo i contatori per --bench
}   t_data;

//FUNZIONE PER CREARE NUOVO NODO
t_node *new_node(int value)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	node->value = value;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

//FUNZIONE PER INIZIALIZZARE TUTTO A 0 / NULL
void init_data(t_data *d)
{
	d->a = NULL;
	d->size_a = 0;
	d->b = NULL;
	d->size_b = 0;
}

//FUNZIONE PER AGGIUNGERE "X" davanti ad "A B C"---> X A B C
void stack_add_front(t_node **top, t_node *new)
{
	if (*top == NULL)
	{
		new->next = new;
		new->prev = new;
		*top = new;
		return;
	}
	else
	{
		t_node *old_last;

		old_last = (*top)->prev;
		new->next = *top;
		new->prev = old_last;
		old_last->next = new;
		(*top)->prev = new;
		*top = new;
	}
}

//FUNZIONE PER AGGIUNGERE "X" dopo ad "A B C"---> A B C X
void stack_add_back(t_node **top, t_node *new)
{
	if (*top == NULL)
	{
		new->next = new;
		new->prev = new;
		*top = new;
		return;
	}
	else
	{
		t_node *old_last;

		old_last = (*top)->prev;
		new->prev = old_last;
		new->next = *top;
		old_last->next = new;
		(*top)->prev = new;
	}
}


//RIMUOVE IL PRIMO, RICOLLEGANDO IL NUOVO PRIMO 
//CON L' ULTIMO (CHE NON CAMBIA)
t_node *stack_remove_front(t_node **top)
{
	if (*top == NULL)
		return (NULL);
	else
	{
		t_node *da_rimuovere;
		t_node *prossimo;
		t_node *ultimo;

		da_rimuovere = *top;
		prossimo = (*top)->next;
		ultimo = (*top)->prev;

		if (prossimo == da_rimuovere)
			*top = NULL;
		else
		{
			ultimo->next = prossimo;
			prossimo->prev = ultimo;
			*top = prossimo;
		}
		da_rimuovere->next = NULL;
		da_rimuovere->prev = NULL;
		return (da_rimuovere);
	}
}



//FUNZIONE DI CONTROLLO VALIDITÀ NUMERI
int is_valid_number(char *str)
{
	int i;

	i = 0;

	//SALTO IL SEGNO
	if (str[0] == '-' || str[0] == '+')
		i++;

	//CONTROLLO SE ESISTONO ALTRE COSE
	if (str[i] == '\0')
		return (0);

	//CONTROLLO CHE OGNI CARATTERE RESTANTE SIA UNA CIFRA
	while (str[i] != 0)
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return(0);
	}
	return (1);
}

//ATOI MODIFICATA IN LONG PER POI POTER CONTROLLARE LIMITI INT DOPO
long ft_atol(char *str)
{
	int i;
	int neg;
	long result;

	i = 0;
	neg = 0;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (neg)
		return (-result);
	return (result);
}

//CONTROLLA SE VAR LONG È NEI LIMITI DI INT
int check_int_limits (long value)
{
	return (value > 2147483647 || value < -2147483648);
}

//SCORRE TUTTA LA LISTA CONTROLLANDO DUPLICATI, NON AVENDO INIZIO E FINE FA IL PRIMO GIRO FUORI DAL WHILE
int is_duplicate(t_data *d, int value)
{
	t_node	*current;
	int		i;

	if (d->a == NULL)
		return (0);
	current = d->a;
	i = 0;
	while (i < d->size_a)
	{
		if (current->value == value)
			return (1);
		current = current->next;
		i++;
	}
	return (0);
}

//FUNZIONE HELPER PER SA E SB, PRENDE TABELLA E SIZE TABELLA
//FATTA SEPARATA PER FARE SS SENZA RISCRIVERE 3 VOLTE IN OUTPUT IL COMANDO (COME DA SUBJECT)
int swap_top_two(t_node *top, int size)
{
	int temp_value;
	int temp_index;

	if (size < 2)
		return (0);
	
	temp_value = top->value;
	top->value = top->next->value;
	top->next->value = temp_value;

	temp_index = top->index;
	top->index = top->next->index;
	top->next->index = temp_index;

	return (1);
}

void sa(t_data *d)
{
	if (swap_top_two(d->a, d->size_a))
		write(1, "sa\n", 3);
}

void sb(t_data *d)
{
	if (swap_top_two(d->b, d->size_b))
		write(1, "sb\n", 3);
}


// void ss(t_data *d)
// {
// 	int did_a;
// 	int did_b;

// 	did_a = swap_top_two(d->a, d->size_a);
// 	did_b = swap_top_two(d->b, d->size_b);
// 	if (did_a || did_b)
// 		write(1, "ss\n", 3);
// }

void ss(t_data *d)
{
    int did_a;
    int did_b;

    // Esegue lo swap su entrambe le pile e salva i risultati
    did_a = swap_top_two(d->a, d->size_a);
    did_b = swap_top_two(d->b, d->size_b);
    
    // Entra nell'if SOLO se ENTRAMBI gli swap sono andati a buon fine
    if (did_a && did_b)
    {
        write(1, "ss\n", 3);
    }
    else
    {
        // SE SEI QUI, significa che uno dei due (o entrambi) ha fallito.
        // Dobbiamo rimediare stampando la mossa singola di chi si è mosso davvero,
        // altrimenti avremmo una mossa "fantasma" in memoria senza stampa!
        if (did_a)
            write(1, "sa\n", 3);
        if (did_b)
            write(1, "sb\n", 3);
    }
}

//CONTROLLA DI NON COPIARE DATI VUOTI IN A, AGGIUNGE ALL INIZIO DI A
//L'ELEMENTO RIMOSSO DA B IN LINEA, AUMENTA LEN A DI 1 E DIMINUISCE B
void pa(t_data *d)
{
	if (d->b == NULL)
		return;
	stack_add_front(&d->a, stack_remove_front(&d->b));
	d->size_a++;
	d->size_b--;
	write(1, "pa\n", 3);
}

//CONTROLLA DI NON COPIARE DATI VUOTI IN B, AGGIUNGE ALL INIZIO DI B
//L'ELEMENTO RIMOSSO DA A IN LINEA, AUMENTA LEN B DI 1 E DIMINUISCE A
void pb(t_data *d)
{
	if (d->a == NULL)
		return;
	stack_add_front(&d->b, stack_remove_front(&d->a));
	d->size_b++;
	d->size_a--;
	write(1, "pb\n", 3);
}

void ra(t_data *d)
{
	// Protezione: se la stack ha meno di 2 elementi, non si può ruotare
	if (d->size_a < 2)
		return;

	// Il secondo elemento diventa la nuova testa
	d->a = d->a->next;

	// Stampa il comando richiesto
	write(1, "ra\n", 3);
}

void rb(t_data *d)
{
	// Protezione speculare per la stack b
	if (d->size_b < 2)
		return;

	// Il secondo elemento diventa la nuova testa
	d->b = d->b->next;

	// Stampa il comando richiesto
	write(1, "rb\n", 3);
}


void rr(t_data *d)
{
	int ruotato_a;
	int ruotato_b;

	ruotato_a = 0;
	ruotato_b = 0;

	// Ruota A solo se ha abbastanza elementi
	if (d->size_a >= 2)
	{
		d->a = d->a->next;
		ruotato_a = 1;
	}

	// Ruota B solo se ha abbastanza elementi
	if (d->size_b >= 2)
	{
		d->b = d->b->next;
		ruotato_b = 1;
	}

	// Stampa 'rr' solo se si sono mosse effettivamente entrambe!
	if (ruotato_a && ruotato_b)
		write(1, "rr\n", 3);
}


void rra(t_data *d)
{
	// Protezione: se la stack ha meno di 2 elementi, non si può ruotare
	if (d->size_a < 2)
		return;

	// L'ultimo elemento diventa la nuova testa
	d->a = d->a->prev;

	// Stampa il comando richiesto
	write(1, "rra\n", 4);
}

void rrb(t_data *d)
{
	// Protezione speculare per la stack b
	if (d->size_b < 2)
		return;

	// L'ultimo elemento diventa la nuova testa
	d->b = d->b->prev;

	// Stampa il comando richiesto
	write(1, "rrb\n", 4);
}

void rrr(t_data *d)
{
	
	int ruotato_b;


	int ruotato_a = 0;
	ruotato_b = 0;

	// Ruota A solo se ha abbastanza elementi
	if (d->size_a >= 2)
	{
		d->a = d->a->prev;
		ruotato_a = 1;
	}

	// Ruota B solo se ha abbastanza elementi
	if (d->size_b >= 2)
	{
		d->b = d->b->prev;
		ruotato_b = 1;
	}

	// Stampa 'rrr' solo se si sono mosse effettivamente entrambe!
	if (ruotato_a && ruotato_b)
		write(1, "rrr\n", 4);
}

double compute_disorder(t_data *d)
{
	int	mistakes;
	t_node	*outer;
	t_node	*inner;
	int	i;
	int	j;
	double	disorder;
	int	total_pairs;

	if (d->size_a <= 1)
		return (0.0);
	mistakes = 0;
	outer = d->a;
	i = 0;
	while (i < d->size_a)
	{
		inner = outer->next;
		j = i + 1;
		while (j < d->size_a)
		{
			if (outer->value > inner->value)
				mistakes++;
			inner = inner->next;
			j++;
		}
		outer = outer->next;
		i++;
	}
	total_pairs = d->size_a * (d->size_a - 1) / 2;
	disorder = (double) mistakes / total_pairs;
	return (disorder);
}

void bubble_sort_ps(t_data *d)
{
	int i;
	int swapped;
	int full_checks;

	swapped = 1;
	full_checks = 1;
	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (i < d->size_a - full_checks)
		{
			if (d->a->value > d->a->next->value)
			{
				sa(d);
				swapped = 1;
			}
			i++;
			ra(d);
		}
		while (i--)
		{
			rra(d);
		}
		full_checks++;
	}
}


int    int_sqrt(int number)
{
	int    i;

	i = 1;
	while (i * i <= number)
		i++;
	return (i - 1);
}

void chunk_based_sort(t_data *d)
{
	int n_chunks;
	int chunk_size;
	int limite_massimo;

	if (!d || d->size_a <= 0)
		return;

	n_chunks = int_sqrt(d->size_a);
	chunk_size = d->size_a / n_chunks;
	limite_massimo = chunk_size;

	// FASE 1: Spingiamo in B a blocchi
	while (d->size_a > 0)
	{
		if (d->a->index < limite_massimo)
		{
			pb(d);
			// Se l'indice è nella metà inferiore del chunk corrente, lo mandiamo sotto
			if (d->size_b > 1 && d->b->index < (limite_massimo - (chunk_size / 2)))
				rb(d);
		}
		else
			ra(d);
		
		// Quando B ha accumulato tutto il chunk, alziamo il limite
		if (d->size_b == limite_massimo && limite_massimo < d->size_a + d->size_b)
			limite_massimo += chunk_size;
	}

	// FASE 2: Riportiamo in A (Resta invariata, è già perfetta!)
	while (d->size_b > 0)
	{
		int     target_index;
		t_node  *curr;
		int     pos;

		target_index = d->size_b - 1;
		curr = d->b;
		pos = 0;
		
		while (curr->index != target_index)
		{
			pos++;
			curr = curr->next;
		}

		if (pos <= d->size_b / 2)
		{
			while (d->b->index != target_index)
				rb(d);
		}
		else
		{
			while (d->b->index != target_index)
				rrb(d);
		}
		pa(d); 
	}
}
 

int count_bits_to_represent(int n)
{
	int bits;
	int power;

	bits = 0;
	power = 1;
	while(power < n)
	{
		power = power * 2;
		bits++;
	}
}

void assign_index(t_data *d)
{
	t_node  *current;
	t_node  *check;
	int     i;
	int     j;
	int     count;

	if (!d || !d->a || d->size_a <= 0)
		return;

	current = d->a;
	i = 0;
	while (i < d->size_a)
	{
		count = 0;
		check = d->a;
		j = 0;
		
		while (j < d->size_a)
		{
			if (check->value < current->value)
			{
				count++;
			}
			check = check->next;
			j++;
		}
		
		current->index = count;
		current = current->next;
		i++;
	}
}

void print_stack(t_node *stack, int size, char *message)
{
	printf("%s: ", message);
	if (!stack || size <= 0)
	{
		printf("(vuoto)\n");
		return;
	}
	
	while (size > 0)
	{
		// Stampa nel formato richiesto: valore[index]
		printf("%d[%d] ", stack->value, stack->index);
		stack = stack->next;
		size--;
	}
	printf("\n");
}

void duplicate_data(t_data *src, t_data *dest)
{
	t_node  *curr;
	t_node  *new_n;
	int     i;

	init_data(dest);
	if (!src || src->size_a <= 0)
		return;
	
	curr = src->a;
	i = 0;
	while (i < src->size_a)
	{
		new_n = new_node(curr->value);
		new_n->index = curr->index; // Copiamo anche l'indice calcolato
		stack_add_back(&dest->a, new_n);
		dest->size_a++;
		curr = curr->next;
		i++;
	}
}
int conta_mosse_da_file(char *filename)
{
	FILE *file = fopen(filename, "r");
	int ch;
	int mosse = 0;

	if (!file)
		return (0);
	while ((ch = fgetc(file)) != EOF)
	{
		if (ch == '\n')
			mosse++;
	}
	fclose(file);
	return (mosse);
}

void print_stack_senza_messaggio(t_node *stack, int size)
{
	if (!stack || size <= 0)
	{
		printf("(vuoto)\n");
		return;
	}
	while (size > 0)
	{
		printf("%d[%d] ", stack->value, stack->index);
		stack = stack->next;
		size--;
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	t_data  d_original;
	t_data  d_bubble;
	t_data  d_chunk;
	int     i;
	long    arg;
	t_node *node;
	int     mosse_bubble = 0;
	int     mosse_chunk = 0;

	i = 1;
	init_data(&d_original);
	while (i <= argc - 1)
	{
		if (is_valid_number(argv[i]) == 0)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		arg = ft_atol(argv[i]);
		if (check_int_limits(arg) == 1 || is_duplicate(&d_original, (int)arg) == 1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		node = new_node((int)arg);
		stack_add_back(&d_original.a, node);
		d_original.size_a++;
		i++;
	}

	assign_index(&d_original);

	// Salviamo un puntatore alla console reale per poterci tornare dopo
	FILE *console = fdopen(dup(fileno(stdout)), "w");

	// ================= BUBBLE SORT =================
	duplicate_data(&d_original, &d_bubble);
	
	// Deviamo tutti i print di sa, ra, ecc. dentro un file temporaneo invisibile
	freopen("bubble_test.tmp", "w", stdout);
	bubble_sort_ps(&d_bubble);
	fflush(stdout); // Forza la scrittura su file
	
	// Contiamo quante righe ha stampato
	mosse_bubble = conta_mosse_da_file("bubble_test.tmp");


	// ================= CHUNK SORT =================
	duplicate_data(&d_original, &d_chunk);
	
	// Deviamo i print del chunk dentro un altro file temporaneo
	freopen("chunk_test.tmp", "w", stdout);
	chunk_based_sort(&d_chunk);
	fflush(stdout);
	
	// Contiamo quante righe ha stampato
	mosse_chunk = conta_mosse_da_file("chunk_test.tmp");


	// ================= VERDETTO FINALE =================
	// Rimettiamo l'output sulla console normale così i printf funzionano di nuovo
	dup2(fileno(console), fileno(stdout));
	fclose(console);

	// Stampiamo nel formato esatto che hai chiesto!
	printf("Array finale Bubble [%d]: ", mosse_bubble);
	print_stack_senza_messaggio(d_bubble.a, d_bubble.size_a);

	printf("Array finale Chunk [%d]: ", mosse_chunk);
	print_stack_senza_messaggio(d_chunk.a, d_chunk.size_a);

	// Pulizia dei file temporanei creandosi durante il test
	remove("bubble_test.tmp");
	remove("chunk_test.tmp");

	return (0);
}