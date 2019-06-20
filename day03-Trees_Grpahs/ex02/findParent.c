/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 02:15:41 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/30 05:20:17 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>

typedef struct s_node t_node;

typedef struct s_item {
	int idx;
	struct s_item *next;
} t_item;

typedef struct s_stack {
	struct s_item *item;
} t_stack;

t_item		*newItem(int x) {
	t_item	*new;

	new = (t_item *)malloc(sizeof(t_item));
	new->idx = x;
	new->next = NULL;
	return (new);
}

struct s_stack *initStack(void)
{
    t_stack *stack;

    stack = (t_stack *)calloc(1, sizeof(t_stack));
    return (stack);
}

int     pop(struct s_stack *stack)
{
    int	idx;

	if (!stack->item) return (-1);
	idx = stack->item->idx;
	stack->item = stack->item->next;
	return (idx);
}

void push(struct s_stack *stack, int idx)
{
    t_item  *item;

    item = newItem(idx);
    if (!stack->item) {
		stack->item = item;
		return ;
	}

	item->next = stack->item;
	stack->item = item;
}

struct s_node *findLCA(struct s_node *root, char *firstSpecies, char *secondSpecies, int *first, int *second)
{
	t_node *child = NULL;
	int i;
	int count = 0;

	if (!root)
		return NULL;
	if (!strcmp(root->name, firstSpecies))
	{
		*first = 1;
		return root;
	}
	if (!strcmp(root->name, secondSpecies))
	{
		*second = 1;
		return root;
	}
	i = 0;

	while (root->children[i])
	{
		t_node *temp = findLCA(root->children[i], firstSpecies, secondSpecies, first, second);
		if (temp)
		{
			child = temp;
			count++;
		}
		i++;
	}
	if (count == 2)
		return root;
	return child;
}

int findNode(struct s_node *root, char *value)
{
	if (!root)
		return 0;
	if (!strcmp(root->name, value))
		return 1;
    for (int i = 0; root->children[i]; i++)
		if (findNode(root->children[i], value))
			return 1;
	return 0;
}

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	t_node *node = NULL;
	int first = 0;
	int second = 0;

	node = findLCA(root, firstSpecies, secondSpecies, &first, &second);
	if (first && second)
		return node;
	if (first && findNode(node, secondSpecies))
		return node;
	if (second && findNode(node, firstSpecies))
		return node;
	return NULL;
}