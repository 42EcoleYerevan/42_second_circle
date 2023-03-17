#include "fdf.h"

void	ft_put_map(t_fdf *fdf)
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
				ft_draw_line(fdf, col, row, col + 1, row, 0x00FFFF);
			if (row < fdf->map->height - 1)
				ft_draw_line(fdf, col, row, col, row + 1, 0x00FFFF);
			col++;
		}
		row++;
	}
}

int	ft_draw_map(t_fdf *fdf)
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
	usleep(10000);
	mlx_destroy_image(fdf->mlx, fdf->image);
	return (0);
}

int	main(void)
{
	t_fdf *fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (2);
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "(: Hello world fdf :)");
	fdf->map = ft_create_map("./test_maps/42.fdf");
	fdf->map->scale = 30;
	fdf->map->sx = 500;
	fdf->map->sy = 100;
	mlx_loop_hook(fdf->mlx, ft_draw_map, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
