/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aloneCans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:02:35 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/02 21:11:03 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void aloneCans(int *arr, int n)
{
    int xor = 0;
	int v1 = 0;
	int v2 = 0;
	for (int i = 0; i < n; i++)
		xor ^= arr[i];
	xor = xor & ~(xor - 1);
	for (int i = 0; i < n; i++)
	{
		if (arr[i] & xor)
			v1 = v1 ^ arr[i];
		else
			v2 = v2 ^ arr[i];
		i++;
	}
	printf("%d\n", v1);
	printf("%d\n", v2);
}