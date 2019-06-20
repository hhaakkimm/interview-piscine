/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:34:54 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/02 14:51:25 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

char *getSum(char *a, char *b)
{
    char *ans;

    ans = (char *)malloc(sizeof(char) * 7);
    int f = 0;
    for (int i = 5; i >= 0; i--)
    {
        f += a[i] - '0' + b[i] - '0';
        ans[i] = (f % 2) + '0';
        f /= 2;
    }
    return (ans);
}

int			toInt(char *bits)
{
	int		res;

	res = 0;
	while (*bits)
	{
		res = res * 2 + (*bits - '0');
		bits++;
	}
	return (res);
}