/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correctSong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:54:11 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/02 20:54:21 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void correctSong(struct s_bit *bit, int l, int row, int col, int dist)
{
	int i = row;
	if (row < bit->n && col < l)
	{
		while (dist && i < bit->n)
		{
			bit->arr[i] = 1 << col;
			i++;
			dist--;
		}
	}
}