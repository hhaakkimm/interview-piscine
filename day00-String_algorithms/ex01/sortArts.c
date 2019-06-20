/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 06:26:02 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/26 04:42:29 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>

void	ft_swap(struct s_art	**arts, int x, int y)
{
	struct s_art	*t;

	t = arts[x];
	arts[x] = arts[y];
	arts[y] = t;
}

void	ft_qsort(struct s_art	**arts, int l, int r) {
    if (l >= r)
        return;

    int pivot = l + rand() % (r - l);
    char *key;
	
	key = arts[pivot]->name;

    int i = l, j = r;
    while (i <= j) {
        while (strcmp(key, arts[i]->name) > 0)  
		    i++;
        while (strcmp(key, arts[j]->name) < 0)
            j--;
        if (i <= j) {
            ft_swap(arts, i, j);
            i++; j--;
        }
    }

    if (l < j)
        ft_qsort(arts, l, j);
    if (i < r)
        ft_qsort(arts, i, r);    
}

void	sortArts(struct s_art	**arts)
{
	if (arts)
	{
		int n = 0;
		while (arts[n])
			n++;
		ft_qsort(arts, 0, n - 1);
	}
}
