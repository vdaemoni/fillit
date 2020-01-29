/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:36:00 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/01/29 17:21:07 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			to_left(t_etra *mine)
{
	int i;

	i = 0;
	while (i <= 6)
	{
		mine->coords[i] -= 1;
		i += 2;
	}
}

static void			to_up(t_etra *mine)
{
	int j;

	j = 1;
	while (j <= 7)
	{
		mine->coords[j] -= 1;
		j += 2;
	}
}

static void			zero_zero(t_etra *mine)
{
	while (mine->coords[0] != 0 &&
			mine->coords[2] != 0 &&
			mine->coords[4] != 0 &&
			mine->coords[6] != 0)
		to_left(mine);
	while (mine->coords[1] != 0 &&
			mine->coords[3] != 0 &&
			mine->coords[5] != 0 &&
			mine->coords[7] != 0)
		to_up(mine);
}

static t_etra		*make_tetra(char *buf, char littera)
{
	t_etra	*ptr;
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	y = 1;
	if (!(ptr = (t_etra *)malloc(sizeof(t_etra))))
		return (0);
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			ptr->coords[x] = i % 5;
			ptr->coords[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	ptr->littera = littera;
	zero_zero(ptr);
	return (ptr);
}

t_etra				*create_lst(char *buf, int size)
{
	t_etra	*curr;
	t_etra	*head;
	int		i;
	char	littera;

	i = 0;
	littera = 'A';
	while (i < size)
	{
		if (littera == 'A')
		{
			head = make_tetra(buf, littera++);
			curr = head;
		}
		else
		{
			curr->next = make_tetra(buf + i, littera++);
			if (!curr->next)
				return (NULL);
			curr = curr->next;
		}
		i += 21;
	}
	curr->next = NULL;
	return (head);
}
