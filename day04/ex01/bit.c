/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:52:20 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/02 15:08:14 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

char *getAnd(char *a, char *b)
{
    char *ans;
    char aa[4], bb[4];

    ans = (char *)malloc(sizeof(char) * 5);
    if (a[0] == '~')
        for (int i = 1; i < 5; i++)
            aa[i - 1] = (1 + a[i] - '0') % 2 + '0';
    else
        for (int i = 0; i < 4; i++)
            aa[i] = a[i];
    if (b[0] == '~')
        for (int i = 1; i < 5; i++)
            bb[i - 1] = (1 + b[i] - '0') % 2 + '0';
    else
        for (int i = 0; i < 4; i++)
            bb[i] = b[i];
    for (int i = 0; i < 4; i++)
        ans[i] = (aa[i] + b[i] - '0' - '0' == 2) + '0';
    return (ans);
}

char *getOr(char *a, char *b)
{
    char *ans;
    char aa[4], bb[4];

    ans = (char *)malloc(sizeof(char) * 5);
    if (a[0] == '~')
        for (int i = 1; i < 5; i++)
            aa[i - 1] = (1 + a[i] - '0') % 2 + '0';
    else
        for (int i = 0; i < 4; i++)
            aa[i] = a[i];
    if (b[0] == '~')
        for (int i = 1; i < 5; i++)
            bb[i - 1] = (1 + b[i] - '0') % 2 + '0';
    else
        for (int i = 0; i < 4; i++)
            bb[i] = b[i];
    for (int i = 0; i < 4; i++)
        ans[i] = (aa[i] + b[i] - '0' - '0' != 0) + '0';
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