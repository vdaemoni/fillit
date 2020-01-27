/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 02:38:02 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/15 00:29:27 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_revcpy(char *dest, char *src, int i)
{
	int zero;

	zero = 0;
	dest[i--] = '\0';
	while (i > -1)
		dest[zero++] = src[i--];
	return (dest);
}

static char	*ft_minint(char *str)
{
	char *copy;

	copy = ft_memalloc(12);
	return (ft_strncpy(copy, str, 11));
}

char		*ft_itoa(int nb)
{
	char	res[11];
	char	*copy;
	int		sign;
	int		i;

	if (nb == -2147483648)
		return (ft_minint("-2147483648"));
	i = 0;
	sign = nb < 0 ? -1 : 1;
	while (nb * sign > 9)
	{
		res[i] = sign * (nb % 10) + '0';
		i++;
		nb = nb / 10;
	}
	res[i++] = sign * nb + '0';
	if (sign < 0)
		res[i++] = '-';
	copy = (char*)malloc(sizeof(char) * i + 1);
	if (copy == NULL)
		return (NULL);
	return (ft_revcpy(copy, res, i));
}
