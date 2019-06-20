/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:14:51 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/02 15:37:12 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

char	*rightShift(char *bin, int k)
{
	int		i;
	int		j;

	for (i = 0; i < k; i++)
	{
		for (j = 5; j > 0; j--)
			bin[j] = bin[j - 1];
	}
	return (bin);
}

char *leftShift(char *bin, int k)
{
    char *ans;

    ans = (char *)malloc(sizeof(char) * 7);
    k %= 6;
    for (int i = k; i < 6; i++)
        ans[i - k] = bin[i];
    for (int i = 0; i < k; i++)
        ans[i + 6 - k] = bin[i];
    return (ans);
}

void	*getnegative(char *bits)
{
	int c;

	c = 1;
	for (int i = 5; i >= 0; i--)
	{
		bits[i] = (bits[i] == '1') ? '0' : '1';
		if (bits[i] - '0' + c == 1)
		{
			bits[i] = '1';
			c = 0;
		}
		else if (bits[i] - '0' + c == 2)
		{
			bits[i] = '0';
			c = 1;
		}
	}
	return (bits);
}

int		toInt(char *bits)
{
	int		i;
	int		k = 1;
	int		res = 0;
	int		sign = 1;
	char	*tmp = strdup(bits);

	if (*bits == '1')
	{
		sign = -1;
		tmp = getnegative(tmp);
	}
	for (i = 5; i >= 0; i--)
	{
		res += (tmp[i] - '0') * k;
		k *= 2;
	}
	return (res * sign);
}