/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piano.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:40:05 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/02 20:44:42 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

int **pianoDecompress(struct s_bit *bit, int l)
{
    int num;
	int j;

	int **arr = calloc(1, sizeof(int *) * bit->n);
	for (int i = 0; i < bit->n; i++)
	{
		arr[i] = calloc(1, sizeof(int) * l);
		num = bit->arr[i];
		j = 0;
		while (num)
		{
			j++;
			num >>= 1;
		}
		arr[i][j] = 1;
	}
	return arr;    
}