/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyGameBoard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 23:29:36 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/27 23:36:02 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

typedef struct s_node t_node;

int get_size(t_node *node)
{
	int len = 0;
	while (node)
	{
		node = node->next;
		len++;
	}
	return len;
}

struct s_node *cloneGameBoard(struct s_node *node)
{
	t_node *tmp = node;
	t_node *new = NULL;
	t_node *res;
	t_node *prev = NULL;
	int len = get_size(node);
	t_node *table[len];

	while (tmp)
	{
		new = malloc(sizeof(struct s_node));
		new->value = tmp->value;
		new->random = NULL;
		if (prev)
			prev->next = new;
		else
			res = new;
		tmp = tmp->next;
		prev = new;
		table[new->value] = new;
	}
	tmp = node;
	while (tmp)
	{
		if (tmp->random)
			table[tmp->value]->random = table[tmp->random->value];
		tmp = tmp->next;
	};
	return res;
}