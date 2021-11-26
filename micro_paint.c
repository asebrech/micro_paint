#include "micro_paint.h"

int	ft_isspace(char c)
{
	if (c == '\n' || c == '\v' || c == '\t' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	check_s(void *ptr)
{
	char c;

	fscanf(ptr, "%c", &c);	
	printf("%c", c);
	if (!(ft_isspace(c)))
		return (1);
	else
		return (0);
}

int	first_line(void *ptr)
{
	char	c;
	int	n;

	fscanf(ptr, " %d", &n);
	if (n > 300 || n <= 0)
		return (1);	
	printf("%d", n);
	if (check_s(ptr))
		return (1);
	fscanf(ptr, " %d", &n);
	if (n > 300 || n <= 0)
		return (1);
	printf("%d", n);
	if (check_s(ptr))
		return (1);
	if (fscanf(ptr, " %c", &c) == EOF)
		return (1);
	printf("%c\n", c);
	return (0);
}

int	parsing(void *ptr)
{
	char	c;
	float	f;

	if (fscanf(ptr, " %c", &c) == EOF)
		return (0);
	if (c != 'r' && c != 'R')
		return (1);
	printf("%c", c);
	if (check_s(ptr))
		return (1);
	fscanf(ptr, " %f", &f);
	printf("%f", f);
	if (check_s(ptr))
		return (1);
	fscanf(ptr, " %f", &f);
	printf("%f", f);
	if (check_s(ptr))
		return (1);
	fscanf(ptr, " %f", &f);
	if (f <= 0)
		return (1);
	printf("%f", f);
	if (check_s(ptr))
		return (1);
	fscanf(ptr, " %f", &f);
	printf("%f", f);
	if (f <= 0)
		return (1);
	if (check_s(ptr))
		return (1);
	if (fscanf(ptr, " %c", &c) == EOF)
		return (1);
	printf("%c\n", c);
	return(parsing(ptr));
}


int	main(int ac, char **av)
{
	void	*ptr;
	int	i;

	if (ac == 2)
	{
		if(!(ptr = fopen(av[1], "r")))
		{
			write(1, "Error: Operation file corrupted\n", 32);
			return(1);
		}
		if (first_line(ptr))
		{
			write(1, "Error: Operation file corrupted\n", 32);
			return(1);
		}
		if (parsing(ptr))
		{
			write(1, "Error: Operation file corrupted\n", 32);
			return(1);
		}
		fclose(ptr);
	}
	else
		write(1, "Error: argument\n", 16);
	return (0);
}
