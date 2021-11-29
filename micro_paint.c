#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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

int	first_pars(void *ptr)
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

char	**fill_first(void *ptr)
{
	char	**str;
	int	width;
	int	height;
	char	c;

	fscanf(ptr, " %d", &width);
	fscanf(ptr, " %d", &height);
	fscanf(ptr, " %c", &c);
	str = malloc(sizeof(char *) * (height + 1));
	for (int i = 0; i < height; i++)
	{
		str[i] = malloc(sizeof(char) * (width + 1));
		for (int j = 0; j < width; j++)
		{
			str[i][j] = c;
		}
		str[i][j] = '\n';
	}
	str[i] = NULL;
	return (str);
}

void	fill_all(void *ptr)
{
	char	r;
	float	x;
	float	y;
	float	width;
	float	height;
	char	c;

	if (fscanf(ptr, " %c", &r) == EOF)
		return ;
	fscanf(ptr, " %f", &x);
	fscanf(ptr, " %f", &y);
	fscanf(ptr, " %f", &width);
	fscanf(ptr, " %f", &height);
	fscanf(ptr, " %c", &c);
	for (int i = 0; i < height; i++)
	{
		for (int i = 0; i < width; i++)
		{
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}
	print_all(ptr);
}

void	print_free(char **str)
{
	for (int i = 0; str[i] != NULL; i++)
	{
		for (int j = 0; str[i][j]; j++)
		{
			write(1, 
		} 
	} 
}

int	main(int ac, char **av)
{
	void	*ptr;
	char	**str;

	if (ac == 2)
	{
		if (!(ptr = fopen(av[1], "r")))
		{
			write(1, "Error: Operation file corrupted\n", 32);
			return(1);
		}
		if (first_pars(ptr))
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
		ptr = fopen(av[1], "r");
		fill_first(ptr);
	//	fill_all(ptr);
		fclose(ptr);
	}
	else
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	return (0);
}
