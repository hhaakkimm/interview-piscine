/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isFilled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:02:42 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/02 21:12:17 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// int isFilled(unsigned int parkingRow)
// {
//     int flag = 0;
//     while (parkingRow)
//     {
//         if ((parkingRow % 2) == 0)
//             flag = 1;
//         else if (flag && (parkingRow % 2) == 1)
//             return (0);
//         parkingRow /= 2;
//     }
//     return (1);
// }

int isFilled(unsigned int parkingRow)
{
	return parkingRow && (parkingRow & (-(~parkingRow))) == 0;
}