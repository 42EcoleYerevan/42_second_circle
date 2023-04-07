#include "../fdf.h"


int ft_key_hook(int keycode, t_fdf *fdf)
{
	printf("hello form key_hook %d\n", keycode);
	if (keycode == ARROW_RIGHT)
		fdf->map->sx += 10;
	else if (keycode == ARROW_LEFT)
		fdf->map->sx -= 10;
	else if (keycode == ARROW_UP)
		fdf->map->sy -= 10;
	else if (keycode == ARROW_DOWN)
		fdf->map->sy += 10;
	else if (keycode == PLUS)
		fdf->map->scale += 1;
	else if (keycode == MINUS)
		fdf->map->scale -= 1;
	else if (keycode == KW)
		fdf->map->xfi += 0.05;
	else if (keycode == KQ)
		fdf->map->xfi -= 0.05;
	else if (keycode == KA)
		fdf->map->yfi -= 0.05;
	else if (keycode == KS)
		fdf->map->yfi += 0.05;
	else if (keycode == KZ)
		fdf->zfi += 0.05;
	else if (keycode == KX)
		fdf->xfi += 0.05;
	else if (keycode == KY)
		fdf->yfi += 0.05;
	fdf->endian = 0;
	return (0);
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

static void ft_put_line(t_fdf *fdf, int *p1, int *p2, int color)
{
	int		dx;
	int		dy;
	int		max;
	int		i;
	float	xstep;
	float	ystep;

	dx = (p2[0] - p1[0]);
	dy = (p2[1] - p1[1]);
	max = MAX(ABS(dx), ABS(dy));
	xstep = (float)dx / max;
	ystep = (float)dy / max;
	i = 0;
	while (i < max)
	{
		ft_put_pixel(
				fdf,
			   	(p1[0] + xstep * i),
			   	(p1[1] + ystep * i),
			   	color
				);
		i++;
	}
}

static void	ft_dot(int *vec, float arr[4][4])
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

void	ft_test_draw_line(t_fdf *fdf, int *p1, int *p2, int color)
{
	/* float xrotate[4][4] = { */
	/* 	{1, 0, 0, 0}, */
	/* 	{0, cos(fdf->xfi), -sin(fdf->xfi), 0}, */
	/* 	{0, sin(fdf->xfi), cos(fdf->xfi), 0}, */
	/* 	{0, 0, 0, 1} */
	/* }; */
	/* float yrotate[4][4] = { */
	/* 	{cos(fdf->yfi), 0, -sin(fdf->yfi), 0}, */
	/* 	{0, 1, 0, 0}, */
	/* 	{sin(fdf->yfi), 0, cos(fdf->yfi), 0}, */
	/* 	{0, 0, 0, 1} */

	/* }; */
	/* float zrotate[4][4] = { */
	/* 	{cos(fdf->zfi), sin(fdf->zfi), 0, 0}, */
	/* 	{-sin(fdf->zfi), cos(fdf->zfi), 0, 0}, */
	/* 	{0, 0, 1, 0}, */
	/* 	{0, 0, 0, 1} */
	/* }; */
	float scale[4][4] = {
		{fdf->map->scale, 0, 0, 0},
		{0, fdf->map->scale, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	float offset[4][4] = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{fdf->map->sx, fdf->map->sy, 0, 1}
	};
	float center[4][4] = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{-((float)fdf->map->width / 2),
		 -((float)fdf->map->height / 2), 0, 1}
	};
	float result[4][4] = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	/* ft_matmul(result, xrotate); */
	/* ft_matmul(result, yrotate); */
	/* ft_matmul(result, zrotate); */

	//change color
	if (color == 0 && (p1[2] <= 0 || p2[2] <= 0))
		color = 0xFFFFFF;
	else if (color == 0 && (p1[2] > 0 || p2[2] > 0))
		color = 0xFF0000;

	ft_matmul(result, center);
	ft_matmul(result, scale);
	ft_matmul(result, offset);

	ft_dot(p1, result);
	ft_dot(p2, result);

	ft_put_line(fdf, p1, p2, color);
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
	fdf->camera->z = 400;
}

int draw(t_fdf *fdf)
{
	ft_test_draw_map(fdf);
	return (0);
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

		fdf->map = ft_create_map(argv[1]);
		fdf->map->scale = WIDTH / MAX(fdf->map->width, fdf->map->height) / 2;
		/* fdf->map->sx = WIDTH / 2; */
		/* fdf->map->sy = HEIGHT / 2; */
		fdf->map->sx = 0;
		fdf->map->sy = 0;
		fdf->map->xfi = 0.5235;
		fdf->map->yfi = 0.5235;
		fdf->xfi = 0.2;
		fdf->yfi = 0.2;
		fdf->zfi = 0.2;

		mlx_loop_hook(fdf->mlx, draw, fdf);
		mlx_key_hook(fdf->window, ft_key_hook, fdf);
		mlx_loop(fdf->mlx);
	}
	return 0;
}
