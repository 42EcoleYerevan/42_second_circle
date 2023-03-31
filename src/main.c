#include "../fdf.h"

int key_hook(int keycode, t_fdf *fdf)
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
	fdf->endian = 0;
	return (0);
}	


int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_fdf *fdf;

		fdf = malloc(sizeof(t_fdf));
		if (!fdf)
			return (2);
		fdf->mlx = mlx_init();
		fdf->window = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "(: Hello world fdf :)");
		fdf->map = ft_create_map(argv[1]);
		fdf->map->scale = WIDTH / MAX(fdf->map->width, fdf->map->height) / 2;
		printf("%d\n", fdf->map->scale);
		fdf->map->sx = 300;
		fdf->map->sy = 0;
		mlx_key_hook(fdf->window, key_hook, fdf);
		mlx_loop_hook(fdf->mlx, ft_draw_map, fdf);
		mlx_loop(fdf->mlx);
	}

/* 	t_fdf *fdf; */
/* 	fdf = malloc(sizeof(t_fdf)); */
/* 	if (!fdf) */
/* 		return (2); */
/* 	fdf->mlx = mlx_init(); */
/* 	fdf->window = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "(: Hello world fdf :)"); */
/* 	mlx_key_hook(fdf->window, key_hook, fdf); */
/* 	mlx_loop(fdf->mlx); */

	return (0);
}
