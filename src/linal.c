/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:26:43 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/29 17:22:17 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_dot(float *vec, float arr[4][4])
{
	int		i;
	int		j;
	float	out[4];

	i = 0;
	while (i < 4)
	{
		out[i] = 0;
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
	int	i;
	int	j;

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

void	ft_matmul(float arr1[4][4], float arr2[4][4])
{
	float	out[4][4];
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			out[i][j] = 0;
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

void	ft_set_diagonal(float result[4][4])
{
	int		row;
	int		col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (row == col)
				result[row][col] = 1.0f;
			else
				result[row][col] = 0.0f;
			col++;
		}
		row++;
	}
}
