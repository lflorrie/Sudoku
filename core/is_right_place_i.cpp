int		check_square(int **map, int row, int col, int num)
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
			if (map[i + y_offset][j + x_offset] == num &&
					i + y_offset != row && j + x_offset != col)
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

int		check_v_line(int **map, int row, int col, int num)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (map[i][col] == num && i != row)
			return (0);
		++i;
	}
	return (1);
}

int		check_h_line(int **map, int row, int col, int num)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (map[row][i] == num && i != col)
			return (0);
		++i;
	}
	return (1);
}

int		is_right_place_i(int **map, int row, int col, int num)
{
	return (check_h_line(map, row, col, num) * check_v_line(map, row, col, num)
			* check_square(map, row, col, num));
}
