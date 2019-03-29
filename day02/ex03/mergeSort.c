/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:09:29 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/28 20:36:16 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

typedef struct s_player t_player;

void ft_mergesort(t_player **player, int l, int r) {
    if (l >= r)
        return;

    int m = (l + r) / 2;

    ft_mergesort(player, l, m);
    ft_mergesort(player, m + 1, r);

    int			i, j, k;
	int			n1 = m - l + 1;
	int			n2 = r - m;
	t_player	*left[n1];
	t_player	*right[n2];

	for (i = 0; i < n1; i++) left[i] = player[l + i];
	for (j = 0; j < n2; j++) right[j] = player[m + 1 + j];

	i = 0; j = 0; k = l;
	while (i < n1 && j < n2)
		if (left[i]->score >= right[j]->score)
			player[k++] = left[i++];
		else
			player[k++] = right[j++];

	while (i < n1) player[k++] = left[i++];
	while (j < n2) player[k++] = right[j++];
}

int		getSize(t_player **players) {
	int		len = -1;

	while (players[++len]) ;
	return (len);
}

struct s_player **mergeSort(struct s_player **players)
{
    int n = getSize(players);
    ft_mergesort(players, 0, n - 1);
    return (players); 
}
