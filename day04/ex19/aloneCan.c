/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aloneCan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:57:47 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/02 21:01:30 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void aloneCan(int *arr, int n)
{
	int ans = 0;

	for (int i = 0; i < n; i++)
		ans ^= arr[i];
	printf("%d\n", ans);
}