/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveTheSequoia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 05:43:21 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/30 05:44:09 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

typedef struct s_node t_node;

void pop(struct s_node **parent, struct s_node **child)
{
	t_node *temp = *parent;
	t_node *childLeft = (*child)->left;
	t_node *childRight = (*child)->right;
	*parent = *child;
	if (temp->left == *child)
	{
		(*child)->left = temp;
		(*child)->right = temp->right;
	}
	else
	{
		(*child)->right = temp;
		(*child)->left = temp->left;
	}
	temp->left = childLeft;
	temp->right = childRight;
}

int heap(struct s_node **node)
{
	if (!*node)
		return 0;

	int num = 1;

	if ((*node)->right && (*node)->value < (*node)->right->value)
		pop(node, &(*node)->right);
	if ((*node)->left && (*node)->value < (*node)->left->value)
		pop(node, &(*node)->left);
	num += heap(&(*node)->right);
	num += heap(&(*node)->left);

	return num;
}


void saveTheSequoia(struct s_node **root)
{
	if (!root)
		return;

	int n = heap(root);
	for (int i=0;i<n-1;i++) {
		heap(root);
	}
}