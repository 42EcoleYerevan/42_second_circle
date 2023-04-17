#include "../fdf.h"
#include <time.h>


static int ft_key_hook(int keycode, t_fdf *fdf)
{
	printf("hello form key_hook %d\n", keycode);
	if (keycode == ARROW_RIGHT)
		fdf->camera->position[0] += 1;
	else if (keycode == ARROW_LEFT)
		fdf->camera->position[0] -= 1;
	else if (keycode == ARROW_UP)
		fdf->camera->position[2] += 1;
	else if (keycode == ARROW_DOWN)
		fdf->camera->position[2] -= 1;

	else if (keycode == KT)
		fdf->istriangle += (fdf->istriangle == 0)? 1: -1;
	else if (keycode == PLUS)
		fdf->map->coef += 0.1f;
	else if (keycode == MINUS)
		fdf->map->coef -= 0.1f;
	else if (keycode == KW)
		fdf->xfi += 0.05f;
	else if (keycode == KQ)
		fdf->xfi -= 0.05f;
	else if (keycode == KA)
		fdf->yfi -= 0.05f;
	else if (keycode == KS)
		fdf->yfi += 0.05f;
	return (0);
}	

static float	*ft_new_point(int x, int y, t_fdf *fdf)
{
	float *point;

	point = (float*)malloc(sizeof(float) * 4);
	if (!point)
		return (NULL);
	point[0] = x;
	point[1] = y;
	point[2] = fdf->map->array[y][x];
	point[3] = 1;
	return (point);
}

static void	ft_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*tmp;

	if (x < WIDTH && y < HEIGHT && x >=0 && y >= 0)
	{
		tmp = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
		*(unsigned int *)tmp = color;
	}
}

static void ft_put_line(t_fdf *fdf, float *p1, float *p2, int color)
{
	float		dx;
	float		dy;
	int		max;
	int		i;
	float	xstep;
	float	ystep;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	max = MAX(ABS(dx), ABS(dy));
	xstep = dx / max;
	ystep = dy / max;
	i = 0;
	while (i < max)
	{
		ft_put_pixel(
				fdf,
			   	(int)(p1[0] + xstep * i),
			   	(int)(p1[1] + ystep * i),
			   	color
				);
		i++;
	}
}

static void	ft_dot(float *vec, float arr[4][4])
{
	int i;
	int j;
	float out[4] = {0, 0, 0, 0};

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
	i = 0;
	while (i < 4)
	{
		vec[i] = out[i];
		i++;
	}
}

static void	ft_arrcpy(float arr1[4][4], float arr2[4][4])
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

static void ft_matmul(float arr1[4][4], float arr2[4][4])
{
	float out[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
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

void ft_vect_mul(float vec1[3], float vec2[3], float result[3])
{
	result[0] = (vec1[1] * vec2[2]) - (vec1[2] * vec2[1]);
	result[1] = (vec1[2] * vec2[0]) - (vec1[0] * vec2[2]);
	result[2] = (vec1[0] * vec2[1]) - (vec1[1] * vec2[0]);
}

void ft_vect_sub(float vec1[3], float vec2[3], float result[3])
{
	result[0] = vec1[0] - vec2[0];
	result[1] = vec1[1] - vec2[1];
	result[2] = vec1[2] - vec2[2];
}

void ft_norm_point(t_fdf *fdf, float *p)
{
	p[0] -= fdf->map->hwidth;
	p[1] -= fdf->map->hheight;
	p[0] /= fdf->map->hwidth;
	p[1] /= fdf->map->hheight;
	p[2] /= (float)fdf->map->z_scale / fdf->map->coef;
}

void ft_offset(t_fdf *fdf, float result[4][4])
{
	float offset[4][4] = {
		{1.0f, 0.0f, 0.0f, 0.0f},
		{0.0f, 1.0f, 0.0f, 0.0f},
		{0.0f, 0.0f, 1.0f, 0.0f},
		{fdf->camera->position[0],
		 fdf->camera->position[1], 
		 fdf->camera->position[2], 1.0f}
	};
	ft_matmul(result, offset);
}

void ft_projection(t_fdf *fdf, float result[4][4])
{
	float projection[4][4] = {
		{fdf->camera->fovy / fdf->camera->aspect, 0.0f, 0.0f, 0.0f},
		{0.0f, fdf->camera->fovy, 0.0f, 0.0f},
		{0.0f, 0.0f, (fdf->camera->f+fdf->camera->n)/
				(fdf->camera->f-fdf->camera->n), 1.0f},
		{0.0f, 0.0f, -2.0f*(fdf->camera->f * fdf->camera->n)/
				(fdf->camera->f-fdf->camera->n), 0.0f}
	};
	ft_matmul(result, projection);
}

void ft_xrotate(t_fdf *fdf, float result[4][4])
{
	float xrotate[4][4] = {
		{1.0f, 0.0f, 0.0f, 0.0f},
		{0.0f, cos(fdf->xfi), sin(fdf->xfi), 0.0f},
		{0.0f, -sin(fdf->xfi), cos(fdf->xfi), 0.0f},
		{0.0f, 0.0f, 0.0f, 1.0f}
	};
	ft_matmul(result, xrotate);
}

void ft_yrotate(t_fdf *fdf, float result[4][4])
{
	float yrotate[4][4] = {
		{cos(fdf->yfi), 0.0f, -sin(fdf->yfi), 0.0f},
		{0.0f, 1.0f, 0.0f, 0.0f},
		{sin(fdf->yfi), 0.0f, cos(fdf->yfi), 0.0f},
		{0.0f, 0.0f, 0.0f, 1.0f}
	};
	ft_matmul(result, yrotate);
}

void ft_zrotate(t_fdf *fdf, float result[4][4])
{
	float zrotate[4][4] = {
		{cos(fdf->zfi), -sin(fdf->zfi), 0.0f, 0.0f},
		{sin(fdf->zfi), cos(fdf->zfi), 0.0f, 0.0f},
		{0.0f, 0.0f, 1.0f, 0.0f},
		{0.0f, 0.0f, 0.0f, 1.0f}
	};
	ft_matmul(result, zrotate);
}

void ft_point_scale(t_fdf *fdf, float *p)
{
	p[0] *= fdf->map->wscale;
	p[1] *= fdf->map->hscale;
	p[0] += fdf->map->sx;
	p[1] += fdf->map->sy;
}

void ft_to_coords(float *p)
{
	p[2] /= p[3];
	p[0] /= p[3] * p[2];
	p[1] /= p[3] * p[2];
}

void ft_proc(t_fdf *fdf, float result[4][4], float *p1, float *p2)
{
	ft_xrotate(fdf, result);
	ft_yrotate(fdf, result);
	ft_zrotate(fdf, result);
	ft_offset(fdf, result);
	ft_projection(fdf, result);

	ft_norm_point(fdf, p1);
	ft_norm_point(fdf, p2);

	ft_dot(p1, result);
	ft_dot(p2, result);

	ft_to_coords(p1);
	ft_to_coords(p2);

	ft_point_scale(fdf, p1);
	ft_point_scale(fdf, p2);
}

void	ft_test_draw_line(t_fdf *fdf, float *p1, float *p2, int color)
{
	//change color
	if (color == 0 && (p1[2] <= 0 || p2[2] <= 0))
		color = 0xFFFFFF;
	else if (color == 0 && (p1[2] > 0 || p2[2] > 0))
		color = 0xFF0000;

	float result[4][4] = {
		{1.0f, 0.0f, 0.0f, 0.0f},
		{0.0f, 1.0f, 0.0f, 0.0f},
		{0.0f, 0.0f, 1.0f, 0.0f},
		{0.0f, 0.0f, 0.0f, 1.0f}
	};

	clock_t begin_proc = clock();
	ft_proc(fdf, result, p1, p2);
	clock_t end_proc = clock();

	fdf->xfi += 0.000005;
	/* fdf->yfi += 0.000005; */
	fdf->zfi += 0.000005;
	clock_t begin_put = clock();
	ft_put_line(fdf, p1, p2, color);
	clock_t end_put = clock();
	printf("%lu %lu\n", end_put - begin_put, end_proc - begin_proc);
	/* printf("%f %f %f %f\n", p1[0], p1[1], p2[0], p2[1]); */
	free(p1);
	free(p2);
}

static void	ft_put_map(t_fdf *fdf)
{
	int row;
	int col;

	row = 0;
	while (row < fdf->map->height)
	{
		col = 0;
		while (col < fdf->map->width)
		{
			if (col < fdf->map->width - 1)
				ft_test_draw_line(fdf, ft_new_point(col, row, fdf),
						ft_new_point(col + 1, row, fdf),
						fdf->map->colors[row][col]);			
			if (row < fdf->map->height - 1)
				ft_test_draw_line(fdf, ft_new_point(col, row, fdf),
					   ft_new_point(col, row + 1, fdf),
					   fdf->map->colors[row][col]);			
			if (fdf->istriangle && row < fdf->map->height - 1 && col < fdf->map->width - 1)
				ft_test_draw_line(fdf, ft_new_point(col + 1, row, fdf),
					   ft_new_point(col, row + 1, fdf),
					   fdf->map->colors[row][col]);			
			col++;
		}
		row++;
	}
}

static int	ft_test_draw_map(t_fdf *fdf)
{
	fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->image,
		   	&fdf->bits_per_pixel,
		   	&fdf->line_length,
		   	&fdf->endian);
	ft_put_map(fdf);
	mlx_put_image_to_window(fdf->mlx,
		   	fdf->window,
		    fdf->image, 0, 0);
	usleep(1000);
	mlx_destroy_image(fdf->mlx, fdf->image);
	return (0);
}

void	ft_init_camera(t_fdf *fdf)
{
	fdf->camera = (t_camera *)malloc(sizeof(t_camera));
	fdf->camera->position[0] = 0.0f;
	fdf->camera->position[1] = 0.0f;
	fdf->camera->position[2] = 1.0f;
	fdf->camera->aspect = (float)WIDTH / (float)HEIGHT;
	fdf->camera->fov = 90.0f / 2.0f;
	fdf->camera->fovy = 1.0f / tanhf(M_PI / 180.0f * fdf->camera->fov);
	fdf->camera->n = 1.0f;
	fdf->camera->f = 100.0f;
}

int draw(t_fdf *fdf)
{
	ft_test_draw_map(fdf);
	return (0);
}

void ft_init_map(t_fdf *fdf, char *path)
{
	fdf->map = ft_create_map(path);
	fdf->map->scale = WIDTH / MAX(fdf->map->width, fdf->map->height) / 2;
	fdf->map->sx = WIDTH / 2.0f;
	fdf->map->sy = HEIGHT / 2.0f;
	fdf->map->coef = 0.2f;
	fdf->map->hwidth = (float)fdf->map->width / 2;
	fdf->map->hheight = (float)fdf->map->height / 2;
	fdf->map->hscale = fdf->map->hheight * fdf->map->scale;
	fdf->map->wscale = fdf->map->hwidth * fdf->map->scale;
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_fdf *fdf;
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		fdf->mlx = mlx_init();
		fdf->window = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "Test");
		fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
		fdf->addr = mlx_get_data_addr(fdf->image,  &fdf->bits_per_pixel, &fdf->line_length, &fdf->endian);

		ft_init_camera(fdf);
		ft_init_map(fdf, argv[1]);
		fdf->xfi = 0.2;
		fdf->yfi = 0.2;
		fdf->zfi = 0.2;
		fdf->istriangle = 0;

		mlx_loop_hook(fdf->mlx, draw, fdf);
		/* mlx_hook(fdf->window, 2, 0, ft_key_hook, fdf); */
		mlx_key_hook(fdf->window, ft_key_hook, fdf);
		mlx_loop(fdf->mlx);
	}
	return 0;
}
