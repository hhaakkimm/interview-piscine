/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:38:06 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/02 15:40:55 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

char *getXor(char *a, char *b)
{
    char *ans;

    ans = (char *)malloc(sizeof(char) * 7);
    for (int i = 0; i < 6; i++)
        ans[i] = (a[i] != b[i]) + '0';
    return (ans);
}

int toInt(char *bits)
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