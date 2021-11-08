#include "micro_paint.h"

int	parsing(t_info *info)
{
	char	space0;
	char	space1;
	char	end;

	fscanf(info->ptr, "%d%c%d%c%c%c", &info->width, &space0, &info->height, &space1, &info->back, &end);
	printf("%d\n", info->width);
	printf("%d\n", (int)space0);
	printf("%d\n", info->height);
	printf("%d\n", (int)space1);
	printf("%c\n", info->back);
	printf("%d\n", (int)end);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac == 2)
	{
		if(!(info.ptr = fopen(av[1], "r")))
		{
			write(1, "Error: Operation file corrupted\n", 32);
			return(1);
		}
		parsing(&info);
		fclose(info.ptr);
	}
	else
		write(1, "Error: argument\n", 16);
	return (0);
}
