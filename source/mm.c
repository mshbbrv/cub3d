#include <stdio.h>

void	sort_sprites(double *arr, int end)
{
	int		i;
	int		j;
	double	tmp_dist;

	i = 0;
	while (i < end - 1)
	{
		j = end - 1;
		while (j > i)
		{
			if (arr[j - 1] > arr[j])
			{
				tmp_dist = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp_dist;
			}
			j--;
		}
		i++;
	}
}

int main(void)
{
	int i;
	double array[10] = {7.6, 3.1, 3.6, 2.1, 1.5, 0.0, 0.5, 12.1, 1.1, 1.7};
	sort_sprites(array, 10);
	i = 0;
	while (i < 10)
	{
		printf("%d : %f\n", i, array[i]);
		i++;
	}
	return (0);
}
