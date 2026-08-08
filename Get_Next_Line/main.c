#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Errore apertura file");
		return (1);
	}

	// Tentativo di lettura
	line = get_next_line(fd);
	printf("Indirizzo restituito: %p\n", (void *)line);

	// Tenta di stampare la stringa: causerà quasi certamente un Segmentation Fault
	if (line)
		printf("Contenuto riga: %s\n", line);

	close(fd);
	return (0);
}