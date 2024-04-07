#include "fdf.h"

void	free_matrix(t_matrix **matrix, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
