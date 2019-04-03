/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftMostCar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:21:09 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/02 20:25:46 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

int leftmostCar(unsigned int parkingRow)
{
    if (parkingRow < 1)
        return (-1);
    return ((int)log2(parkingRow));    
}