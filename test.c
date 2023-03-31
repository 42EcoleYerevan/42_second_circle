#include "minilibx/mlx.h"
#include <stdio.h>

#define WIDTH 1000
#define HEIGHT 600

typedef struct s_point
{
    float x;
    float y;
    float z;
} t_point;

typedef struct s_camera
{
    t_point pos;
    t_point target;
    t_point up;
    float fov;
	float np;
	float fp;
} t_camera;

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 640, 480, "3D Scene");

    t_camera camera = {
        .pos = {0, 0, 5},
        .target = {0, 0, 0},
        .up = {0, 1, 0},
        .fov = 45,
		.np = 1.0f,
		.fp = 20.0f
    };

	t_point t1 = {
		.x = 10,
		.y = 10,
		.z = 5
	};
	t_point t2 = {
		.x = 10,
		.y = 20,
		.z = 5
	};
	t_point t3 = {
		.x = 20,
		.y = 20,
		.z = 5
	};

	float projection_matrix[4][4] = {
		{2*camera.np/WIDTH, 0, 0, 0},
		{0, 2*camera.np/HEIGHT, 0, 0},
		{0, 0, -(camera.fp + camera.np)/(camera.fp - camera.np), -1},
		{0, 0, -2 * (camera.fp * camera.np)/(camera.fp - camera.np), 0},
	};

    return 0;
}
