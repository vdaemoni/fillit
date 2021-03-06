/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:38:50 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/15 22:23:03 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int i;
	int k;

	if (s)
	{
		k = ft_strlen(s);
		i = 0;
		while (i < k)
		{
			s[i] = '\0';
			i++;
		}
	}
}
