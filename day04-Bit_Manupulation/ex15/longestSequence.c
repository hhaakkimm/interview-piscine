/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestSequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:32:38 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/02 20:37:14 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int longestSequence(unsigned int parkingRow)
{
    int		count = 0;
	while (parkingRow != 0)
	{
		parkingRow &= (parkingRow << 1);
		count++;
	}   
    return (count); 
}