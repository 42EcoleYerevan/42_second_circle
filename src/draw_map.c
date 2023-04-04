#include "../fdf.h"

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
				ft_draw_line(fdf, ft_new_point(col, row, fdf),
						ft_new_point(col + 1, row, fdf),
						fdf->map->colors[row][col]);			
			if (row < fdf->map->height - 1)
				ft_draw_line(fdf, ft_new_point(col, row, fdf),
					   ft_new_point(col, row + 1, fdf),
					   fdf->map->colors[row][col]);			
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
	usleep(100000);
	mlx_destroy_image(fdf->mlx, fdf->image);
	return (0);
}
