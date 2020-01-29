/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 18:24:55 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/01/29 17:21:28 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_form(char *buf)
{
	int i;
	int nmb;

	i = 0;
	nmb = 0;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			if (i + 1 <= 18 && buf[i + 1] == '#')
				nmb++;
			if (i - 1 >= 0 && buf[i - 1] == '#')
				nmb++;
			if (i + 5 <= 18 && buf[i + 5] == '#')
				nmb++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				nmb++;
		}
		i++;
	}
	return (nmb);
}

static int	only_four(char *buf)
{
	int i;
	int nmb;

	i = 0;
	nmb = 0;
	while (i < 19)
	{
		if (buf[i] != '\n' && buf[i] != '#' && buf[i] != '.')
			return (0);
		if (buf[i] == '\n' && ((i + 1) % 5 != 0))
			return (0);
		if (buf[i] == '#')
			nmb++;
		i++;
	}
	if (buf[i] != '\n')
		return (0);
	return (nmb);
}

int			is_valid(char *buf, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		if (only_four(buf + i) != 4)
			return (0);
		if (check_form(buf + i) != 6 && check_form(buf + i) != 8)
			return (0);
		i += 21;
	}
	return (1);
}
