#include "fdf.h"

int	main(void)
{
	t_fdf *fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (2);
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "(: Hello world fdf :)");
	fdf->map = ft_create_map("./test_maps/t2.fdf");
	fdf->map->scale = WIDTH / MAX(fdf->map->height, fdf->map->width) / 2;
	fdf->map->sx = 300;
	/* fdf->map->sy = fdf->map->height * fdf->map->scale / 4; */
	fdf->map->sy = 0;
	mlx_loop_hook(fdf->mlx, ft_draw_map, fdf);
	mlx_loop(fdf->mlx);

	/* t_fdf *fdf; */

	/* fdf = malloc(sizeof(t_fdf)); */
	/* if (!fdf) */
	/* 	return (2); */
	/* fdf->map = ft_create_map("./test_maps/t2.fdf"); */
	/* /1* for (int row = 0; row < fdf->map->height; row++) *1/ */
	/* /1* { *1/ */
	/* /1* 	for (int col = 0; col < fdf->map->width; col++) *1/ */
	/* /1* 	{ *1/ */
	/* /1* 		printf("%2d ", fdf->map->colors[row][col]); *1/ */
	/* /1* 	} *1/ */
	/* /1* 	puts(""); *1/ */
	/* /1* } *1/ */
	/* printf("%d\n", fdf->map->z_scale); */

	return (0);
}
