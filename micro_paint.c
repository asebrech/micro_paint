#include <math.h>
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
	if (c != 'c' && c != 'C')
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
	int		i = 0;
	int		j = 0;

	fscanf(ptr, " %d", &width);
	fscanf(ptr, " %d", &height);
	fscanf(ptr, " %c", &c);
	str = malloc(sizeof(char *) * (height + 1));
	while (i < height)
	{
		j = 0;
		str[i] = malloc(sizeof(char) * (width + 1));
		while (j < width)
		{
			str[i][j] = c;
			j++;
		}
		str[i][j] = '\0';
		i++;
	}
	str[i] = NULL;
	return (str);
}

void	fill_all(void *ptr, char **str)
{
	char	r;
	float	x;
	float	y;
	float	radius;
	char	c;
	int		i = 0;
	int		j = 0;

	if (fscanf(ptr, " %c", &r) == EOF)
		return ;
	fscanf(ptr, " %f", &x);
	fscanf(ptr, " %f", &y);
	fscanf(ptr, " %f", &radius);
	fscanf(ptr, " %c", &c);
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j])
		{
			if ((sqrt((x - j) * (x - j) + (y - i) * (y - i))) < radius)
			{
				if (c == 'C' || (sqrt((x - (j - 1)) * (x - (j - 1)) + (y - i) * (y - i))) > radius
						|| (sqrt((x - (j + 1)) * (x - (j + 1)) + (y - i) * (y - i))) > radius
						|| (sqrt((x - j) * (x - j) + (y - (i - 1)) * (y - (i - 1)))) > radius
						|| (sqrt((x - j) * (x - j) + (y - (i + 1) * (y - (i + 1))) > radius)
					str[i][j] = c;
			}
			j++;
		}
		i++;
	}
	fill_all(ptr, str);
}

void	print_free(char **str)
{
	int	i = 0;
	int j = 0;

	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j])
		{
			write(1, &str[i][j], 1);
			j++;
		} 
		write(1, "\n", 1);
		i++;
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
		str = fill_first(ptr);
		fill_all(ptr, str);
		print_free(str);
		fclose(ptr);
	}
	else
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	return (0);
}
