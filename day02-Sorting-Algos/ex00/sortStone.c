/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:01:21 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/28 18:24:54 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

typedef struct s_stone t_stone;
typedef struct s_group {
	int					sz;
	struct s_group		*next;
	t_stone				*first;
	t_stone				*last;
}						t_group;

t_group     *createGroup(t_stone *stone)
{
	t_group     *group;

	group = (t_group *)calloc(1, sizeof(t_group));
	group->first = stone;
	group->last = stone;
	group->sz = stone->size;
	return (group);
}

void		insertStone(t_group **g, t_stone *s) {
	t_group		*tmp;

	if (*g == NULL)
		*g = createGroup(s);
	else {
		tmp = *g;
		while (tmp->next) {
			if (tmp->sz == s->size) {
				tmp->last->next = s;
				tmp->last = s;
				return ;
			}
			tmp = tmp->next;
		}
		tmp->next = createGroup(s);
	}
}

t_group		*getGroups(t_stone *stones) {
	t_group		*res = NULL;

	while (stones) {
		insertStone(&res, stones);
		stones = stones->next;
	}
	return (res);
}

void		swapGroups(t_group *g1, t_group *g2) {
	int			temp_s;
	t_stone		*temp_f, *temp_l;

	temp_f = g1->first; 
	temp_l = g1->last; 
	temp_s = g1->sz;
	
	g1->first = g2->first; 
	g1->last = g2->last; 
	g1->sz = g2->sz;

	g2->first = temp_f; 
	g2->last = temp_l; 
	g2->sz = temp_s;
}

t_stone		*mergeGroups(t_group *g) {
	t_stone		*res = NULL, *tmp;

	while (g) {
		if (!res)
			res = g->first;
		else
			tmp->next = g->first;
		tmp = g->last;
		g = g->next;
	}
	tmp->next = NULL;
	return (res);
}

void		sortStones(struct s_stone **stone) {
	int			swap;
	t_group		*p1, *p2 = NULL;
	t_group		*groups = getGroups(*stone);

	swap = 1;
	while (swap) {
		swap = 0;
		p1 = groups;
		while (p1->next != p2) {
			if (p1->sz > p1->next->sz) {
				swapGroups(p1, p1->next);
				swap = 1;
			}
			p1 = p1->next;
		}
		p2 = p1;
	}
	*stone = mergeGroups(groups);
}
