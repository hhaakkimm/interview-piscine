/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:32:52 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/28 18:58:17 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

typedef struct s_player t_player;

void    insertionSort(struct s_player **players)
{
    t_player    *player;
    int         j;

    for (int i = 1; players[i]; i++)
    {
        player = players[i];
        j = i - 1;

        while (j >= 0 && players[j]->score < player->score)
        {
            players[j + 1] = players[j];
            j--;
        }
        players[j + 1] = player;
    }
}
