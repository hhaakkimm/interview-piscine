/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:41:31 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/02 20:15:12 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

int carPosition(unsigned int parkingRow)
{
    if (parkingRow && !(parkingRow & (parkingRow - 1))) {
        return log2(parkingRow);
    }
    return (-1);   
}

//more http://graphics.stanford.edu/~seander/bithacks.html