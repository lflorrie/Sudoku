#include "is_right_place.h"

bool	check_square(int **map, int row, int col, int num)
{
	int x_offset;
	int y_offset;
	int i;
	int j;

	x_offset = col / 3 * 3;
	y_offset = row / 3 * 3;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (map[i + y_offset][j + x_offset] == num + '0' &&
					i + y_offset != row && j + x_offset != col)
				return (false);
			++j;
		}
		++i;
	}
	return (true);
}

int		check_v_line(int **map, int row, int col, int num)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (map[i][col] == num + '0' && i != row)
			return (0);
		++i;
	}
	return (1);
}

bool	check_h_line(int **map, int row, int col, int num)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (map[row][i] == num + '0' && i != col)
			return (0);
		++i;
	}
	return (1);
}

bool	is_right_place(int **map, int row, int col, int num)
{
	return (check_h_line(map, row, col, num) * check_v_line(map, row, col, num)
			* check_square(map, row, col, num));
}
