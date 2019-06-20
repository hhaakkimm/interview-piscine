/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rightMostCar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:28:59 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/02 21:03:56 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

int rightmostCar(unsigned int parkingRow)
{
    if (parkingRow < 1)
        return (-1);
    return log2((parkingRow^(parkingRow-1)) & parkingRow);
}