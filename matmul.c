#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_point
{
	int x;
	int y;
	int z;
	int w;
} t_point;

typedef struct s_camera
{
    int pos[4];
    int target[4];
    int up[4];
    int fov;
	int np;
	int fp;
} t_camera;

float *ft_dot(int vec[4], float arr[4][4])
{
	int i;
	int j;
	float *out;

	out = (float *)calloc(sizeof(float), 4);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			out[i] += arr[j][i] * vec[j];
			j++;
		}
		i++;
	}
	return (out);
}

void	ft_arrcpy(float **arr1, float arr2[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			arr1[i][j] = arr2[i][j];
			j++;
		}
		i++;
	}
}

void matmul(float **arr1, float arr2[4][4])
{
	float out[4][4] = { 0 };
	int i;
	int j;
	int k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				out[i][j] += arr1[i][k] * arr2[k][j]; 
				k++;
			}
			j++;
		}
		i++;
	}
	ft_arrcpy(arr1, out);
}

void ft_free_2d_arr(float **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i]);
	free(arr);
}

float **ft_init_float_diagonal_matrix(int rows, int cols)
{
	int i;
	float **out;

	i = 0;
	out = (float **)malloc(sizeof(float *) * 4);
	while (i < rows)
	{
		out[i] = (float *)malloc(sizeof(float) * cols);
		if (!out[i])
		{
			ft_free_2d_arr(out);
			return (NULL);
		}
		out[i][i] = 1.0f;
		i++;
	}
	return (out);
}

int main(int argc, char **argv)
{
	float arr[4][4] = {
		{2, 0, 0, 0},
		{0, 2, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	float arr1[4][4] = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{2, 2, 2, 1}
	};
	float arr2[4][4] = {
		{1, 0, 0, 2},
		{0, 1, 0, 2},
		{0, 0, 1, 2},
		{0, 0, 0, 1}
	};

	float **result;
	result = ft_init_float_diagonal_matrix(4, 4);

	matmul(result, arr);
	matmul(result, arr1);
	matmul(result, arr2);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%.2f\t", result[i][j]);
		printf("\n");
	}
	return (0);
}
