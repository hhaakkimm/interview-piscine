/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getPlace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:58:45 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/02 21:13:09 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

// int getPlace(unsigned int parkingRow, int pos)
// {
//     char *str;
//     str = (char *)malloc(sizeof(char) * 21);
//     for (int i = 19; i >= 0; i--)
//     {
//         str[i] = (parkingRow % 2) + '0';
//         parkingRow /= 2;
//     }
//     pos %= 20;
//     pos = 19 - pos;
//     if (str[pos] != '1')
//         return (0);
//     return (1);
// }

int getPlace(unsigned int parkingRow, int pos)
{
	return (parkingRow >> pos) & 1;
}