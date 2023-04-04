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

int main(int argc, char **argv)
{
	float arr[4][4] = {
		{2, 0, 0, 0},
		{0, 2, 0, 0},
		{0, 0, 2, 0},
		{0, 0, 0, 1}
	};
	int vec4[4] = {5, 2, 2, 1};
	t_camera camera = {
		.pos = {0, 0, 100, 1},
		.target = {0, 0, 0, 1},
		.up = {0, 1, 0, 1},
		.fov = 75,
		.np = 10,
		.fp = 500
	};
	float project[4][4] = {
		{cos(0.4) / 2, sin(0.4) / 2, 0, 0},
		{-cos(0.4) / 2, sin(0.4) / 2, 0, 0},
		{0, 0, 1.0f / 2.0f, 0},
		{0, 0, 0, 1},
	};

	float *out;
	out = ft_dot(vec4, project);
	for (int i = 0; i < 4; i++)
		printf("%f ", out[i]);
	puts("");
	return (0);
}
