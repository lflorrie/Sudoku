#include "includes/get_map.h"
#include "includes/ceil.h"
bool		check_square(Ceils **map, int row, int col, int num)
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
			if (map[i + y_offset][j + x_offset].get_label() == num &&
					i + y_offset != row && j + x_offset != col)
				return (false);
			++j;
		}
		++i;
	}
	return (true);
}

bool		check_v_line(Ceils **map, int row, int col, int num)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (map[i][col].get_label() == num && i != row)
			return (false);
		++i;
	}
	return (true);
}

bool		check_h_line(Ceils **map, int row, int col, int num)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (map[row][i].get_label() == num && i != col)
			return (false);
		++i;
	}
	return (true);
}

bool	is_right_place(Ceils **map, int row, int col, int num)
{
	return (check_h_line(map, row, col, num) && check_v_line(map, row, col, num)
			&& check_square(map, row, col, num));
}
