#include "../fdf.h"

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

		mlx_loop_hook(fdf->mlx, ft_draw_map, fdf);
		/* mlx_hook(fdf->window, 2, 0, ft_key_hook, fdf); */
		mlx_key_hook(fdf->window, ft_key_hook, fdf);
		mlx_loop(fdf->mlx);
	}
	return 0;
}
