/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:15:53 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 15:16:01 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_number_of_digits(int n)
{
	int					digits;
	unsigned long int	div;
	unsigned int		temp_n;

	div = 1;
	digits = 0;
	temp_n = (n < 0 ? -n : n);
	if (n <= 0)
		digits++;
	while (div <= temp_n)
	{
		div *= 10;
		digits++;
	}
	return (digits);
}

static char	*getnumber(char *ret, int n, int len)
{
	int				index;
	unsigned int	temp_n;

	index = len;
	temp_n = (n < 0 ? -n : n);
	while (index--)
	{
		if (index == 0 && n < 0)
			ret[index] = '-';
		else
			ret[index] = (temp_n % 10) + 48;
		temp_n /= 10;
	}
	return (ret);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		num;

	num = get_number_of_digits(n);
	ret = ft_strnew(num);
	if (ret == NULL)
		return (NULL);
	ret = getnumber(ret, n, num);
	return (ret);
}
