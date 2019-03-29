/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:38:41 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/28 20:53:06 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define MAXN 1000011

void countSort(unsigned char *utensils, int n)
{
    unsigned char p[MAXN] = {0};
    for (int i = 0; i < n; i++)
        p[utensils[i]]++;
    int j = -1;
    for (int i = 0; i <= MAXN; i++)
    {
        while (p[i]--)
            utensils[++j] = i;
    }
}