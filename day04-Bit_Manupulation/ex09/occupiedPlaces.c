/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occupiedPlaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:08:05 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/02 19:34:42 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int occupiedPlaces(unsigned int parkingRow)
{
    int ans = 0;
    while (parkingRow)
    {
        ans += (parkingRow % 2);
        parkingRow /= 2;
    }
    // return (__builtin_popcount(parkingRow));
    return (ans);
}