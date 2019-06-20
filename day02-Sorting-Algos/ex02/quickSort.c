/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:59:48 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/28 20:07:50 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>

typedef struct s_player t_player;

void	ft_swap(t_player	**player, int x, int y)
{
	t_player	*t;

	t = player[x];
	player[x] = player[y];
	player[y] = t;
}

void	ft_qsort(t_player	**player, int l, int r) {
    if (l >= r)
        return;

    int pivot = l + rand() % (r - l);
    int key;
	
	key = player[pivot]->score;

    int i = l, j = r;
    while (i <= j) {
        while (key - player[i]->score > 0)  
		    i++;
        while (key - player[j]->score < 0)
            j--;
        if (i <= j) {
            ft_swap(player, i, j);
            i++; j--;
        }
    }

    if (l < j)
        ft_qsort(player, l, j);
    if (i < r)
        ft_qsort(player, i, r);    
}

void	quickSort(struct s_player	**players)
{
	if (players)
	{
		int n = 0;
		while (players[n])
			n++;
		ft_qsort(players, 0, n - 1);
	}
}
