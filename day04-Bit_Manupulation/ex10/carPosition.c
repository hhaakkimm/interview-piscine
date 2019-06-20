/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:38:26 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/02 19:40:36 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int carPosition(unsigned int parkingRow)
{
    int ans;

    for (int i = 0; i < 64; i++)
    {
        if ((1 << i) == parkingRow)
            return (i);
        if ((1 << i) > parkingRow)
            return (-1);
    }
    return (-1);
}