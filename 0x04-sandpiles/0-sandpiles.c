#include "sandpiles.h"

/**
 * sum_grids - adds two grids
 * @grid1: first grid
 * @grid2: second grid
 */
static void sum_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

}

/**
 * stable - checks if a sandpile is stable
 * @grid: grid
 * Return: 0 if it's not stable, 1 otherwise
 */
static int stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * topple - it topples
 * @grid: grid to topple
 */
static void topple(int grid[3][3])
{
	int i, j;
	int gc[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			gc[i][j] = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] >= 4)
			{
				grid[i][j] -= 4;
				if ((i - 1 >= 0) && (i - 1 < 3))
					gc[i - 1][j] += 1;
				if ((j - 1 >= 0) && (j - 1 < 3))
					gc[i][j - 1] += 1;
				if ((i + 1 >= 0) && (i + 1 < 3))
					gc[i + 1][j] += 1;
				if ((j + 1 >= 0) && (j + 1 < 3))
					gc[i][j + 1] += 1;
			}
		}
	}
	sum_grids(grid, gc);
}

/**
 * print_grid - prints a grid
 * @grid: grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: First grid
 * @grid2: Second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grids(grid1, grid2);

	while (!stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
