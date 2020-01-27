/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerrell <gmerrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 19:43:40 by gmerrell          #+#    #+#             */
/*   Updated: 2020/01/15 17:19:36 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int	is_inside(t_etra *mina, int size, char axis)
{
	if (axis == 'x')
		return (mina->coords[0] + mina->coords[8] < size &&
				mina->coords[2] + mina->coords[8] < size &&
				mina->coords[4] + mina->coords[8] < size &&
				mina->coords[6] + mina->coords[8] < size);
	else
		return (mina->coords[1] + mina->coords[9] < size &&
				mina->coords[3] + mina->coords[9] < size &&
				mina->coords[5] + mina->coords[9] < size &&
				mina->coords[7] + mina->coords[9] < size);
}

static int	overlap(char **dash, t_etra *mina)
{
	int x;
	int y;
	int i;
	int j;

	x = 0;
	y = 1;
	while (x <= 6)
	{
		j = mina->coords[x] + mina->coords[8];
		i = mina->coords[y] + mina->coords[9];
		if (dash[i][j] != '.')
		{
			return (1);
		}
		x += 2;
		y += 2;
	}
	return (0);
}

static void	place(char **dash, t_etra *mina, char c)
{
	int x;
	int y;
	int i;
	int j;

	x = 0;
	y = 1;
	while (x <= 6)
	{
		j = mina->coords[x] + mina->coords[8];
		i = mina->coords[y] + mina->coords[9];
		dash[i][j] = c;
		x += 2;
		y += 2;
	}
}

int			solving_map(char **dash, t_etra *mina, int size)
{
	if (!mina)
		return (1);
	mina->coords[8] = 0;
	mina->coords[9] = 0;
	while (is_inside(mina, size, 'y'))
	{
		while (is_inside(mina, size, 'x'))
		{
			if (!overlap(dash, mina))
			{
				place(dash, mina, mina->littera);
				if (solving_map(dash, mina->next, size))
					return (1);
				else
					place(dash, mina, '.');
			}
			(mina->coords[8])++;
		}
		mina->coords[8] = 0;
		(mina->coords[9])++;
	}
	return (0);
}
