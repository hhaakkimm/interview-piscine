/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probaDistance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:24:19 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/04 20:43:49 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ft_abs(int x)
{
    if (x < 0)  x = -x;
    return (x);
}

double probaDistance(int dist, int *locations, int n)
{
    double ans;
    int q = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ft_abs(locations[i] - locations[j]) > dist)
                q++;
        }
    }
    // printf("%d\n", q);
    ans = (2.0 * q) / (n * 1.0 * (n - 1.0));
    return (ans);
}

// n * (n - 1)    1
// q              x

// 10 15
// 10 20
// 15 20

// 3 * 2 = 6