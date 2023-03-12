/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:52:19 by agladkov          #+#    #+#             */
/*   Updated: 2023/03/12 20:54:27 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx/mlx.h"

int main()
{
	t_fdf *fdf;

	fdf = (void *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (1);
	fdf->map = ft_create_map("./test_maps/10-2.fdf");
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "mlx window");

	mlx_loop(fdf->mlx);

	return (0);
}
