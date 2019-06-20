/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:45:28 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/04 21:04:06 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

typedef struct s_hotspot t_hotspot;

int     ft_abs(int x)
{
    if (x < 0)  x = -x;
    return (x);
}

int selectHotspots(struct s_hotspot **hotspots)
{
    int ans = 1;
    int q = hotspots[0]->pos + hotspots[0]->radius;
    for (int i = 1; hotspots[i]; i++)
    {
        if (q <= ft_abs(hotspots[i]->pos - hotspots[i]->radius))
            q = hotspots[i]->pos + hotspots[i]->radius,
            ans++;
        if (hotspots[i]->pos + hotspots[i]->radius < q)
            q = hotspots[i]->pos + hotspots[i]->radius;
    }
    return (ans);
}