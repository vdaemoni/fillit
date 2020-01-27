/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerrell <gmerrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:07:12 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/01/15 17:21:38 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/includes/libft.h"
# include <fcntl.h>

typedef struct		s_etra
{
	int				coords[10];
	char			littera;
	struct s_etra	*next;
}					t_etra;

int					is_valid(char *buf, int size);
t_etra				*create_lst(char *buf, int size);
void				solve(t_etra *start);
int					solving_map(char **dashboard, t_etra *start, int size);

#endif
