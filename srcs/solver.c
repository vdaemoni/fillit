/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 21:50:32 by gmerrell          #+#    #+#             */
/*   Updated: 2020/01/29 17:21:01 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	print_dash(char **dashboard, int size)
{
	while (size--)
	{
		ft_putstr(*dashboard++);
		ft_putchar('\n');
	}
}

static char	**da_dash(int size)
{
	char	**dash;
	int		i;

	i = 0;
	if (!(dash = (char **)ft_memalloc(sizeof(char *) * size)))
		return (NULL);
	while (i < size)
	{
		dash[i] = ft_strnew(size);
		ft_memset(dash[i], '.', size);
		i++;
	}
	return (dash);
}

static int	sum_of_tetriminos(t_etra *start)
{
	int i;
	int size;

	i = 0;
	size = 2;
	while (start)
	{
		i++;
		start = start->next;
	}
	while (i * 4 > size * size)
		size++;
	return (size);
}

static void	free_dash(char **dash, int map_size)
{
	while (map_size--)
		free(*dash++);
}

void		solve(t_etra *start)
{
	int		size;
	char	**dash;

	size = sum_of_tetriminos(start);
	dash = da_dash(size);
	while (!solving_map(dash, start, size))
	{
		free_dash(dash, size);
		size = size + 1;
		dash = da_dash(size);
	}
	print_dash(dash, size);
	free_dash(dash, size);
}
