/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearBits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:17:03 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/02 20:20:31 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int clearBits(unsigned int parkingRow, int n)
{
    return (parkingRow >> n) << n;   
}