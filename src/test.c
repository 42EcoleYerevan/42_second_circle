#include "../fdf.h"

typedef struct s_camera
{
    t_point pos;
    t_point target;
    t_point up;
    int fov;
	int np;
	int fp;
} t_camera;

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

int draw(t_fdf *fdf)
{
	ft_draw_map(fdf);
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

		fdf->map = ft_create_map(argv[1]);
		fdf->map->scale = WIDTH / MAX(fdf->map->width, fdf->map->height) / 2;
		fdf->map->sx = (WIDTH - fdf->map->width * fdf->map->scale) / 2;
		fdf->map->sy = (HEIGHT - fdf->map->height * fdf->map->scale) / 2;
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
