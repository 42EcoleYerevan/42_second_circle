/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:26:47 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/29 17:27:55 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	ft_abs(float a)
{
	if (a >= 0)
		return (a);
	return (-a);
}

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc == 2)
	{
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		if (!fdf)
			return (1);
		ft_init_fdf(fdf, argv);
		ft_draw_map(fdf);
		mlx_loop(fdf->mlx);
	}
	return (0);
}
