/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:26:47 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/26 16:50:18 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

		ft_init_fdf(fdf, argv);

		ft_draw_map(fdf);
		mlx_hook(fdf->window, 2, 0, ft_key_hook, fdf);
		mlx_hook(fdf->window, 4, 0, ft_mousedown_hook, fdf);
		mlx_hook(fdf->window, 5, 0, ft_mouseup_hook, fdf);
		mlx_hook(fdf->window, 6, 0, ft_mousemove_hook, fdf);
		mlx_hook(fdf->window, 17, 0, ft_close_hook, fdf);
		mlx_loop(fdf->mlx);
	}
	return 0;
}
