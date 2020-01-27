/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerrell <gmerrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:15:10 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/01/15 16:16:04 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static t_etra	*the_file(char *file)
{
	char	buf[546];
	int		fd;
	int		res;
	t_etra	*test;

	fd = open(file, O_RDONLY);
	res = (int)read(fd, buf, 546);
	if (res == -1 || res > 545 || res < 20)
		return (NULL);
	close(fd);
	buf[res] = '\0';
	if (!(is_valid(buf, res)))
		return (NULL);
	test = create_lst(buf, res);
	return (test);
}

static void		free_list(t_etra *lst)
{
	t_etra *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

int				main(int argc, char **argv)
{
	t_etra *start;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit sourse_file");
		ft_putchar('\n');
		return (0);
	}
	start = the_file(argv[1]);
	if (!(start))
	{
		ft_putstr("error");
		ft_putchar('\n');
		return (0);
	}
	solve(start);
	free_list(start);
	return (0);
}
