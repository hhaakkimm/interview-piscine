/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 06:31:19 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/26 04:48:35 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int		searchPrice(struct s_art	**arts, int n, char *name)
{
	if (!name || n < 1)
		return (-1);
	int l = 0, r = n;
	while (l < r)
	{
		int m = (l + r) >> 1;
		if (strcmp(arts[m]->name, name) < 0)
			l = m + 1;
		else
			r = m;
	}
	if (!strcmp(arts[r]->name, name))
		return (arts[r]->price);
	return (-1);
}
