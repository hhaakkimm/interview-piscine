/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 19:27:43 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/27 20:58:16 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_node t_node;
typedef struct s_item t_item;
typedef struct s_stack t_stack;

void printReverseV2(struct s_node *lst)
{
	t_stack		*st;

	st = stackInit();
	while (lst) {
		push(st, lst->word);
		lst = lst->next;
	}
	while (st->item)
    {
        char *word = (char *)pop(st);
		printf("%s", word);
        if (st->item)
            printf(" ");
    }
}

t_item		*newItem(char *word) {
	t_item	*new;

	new = (t_item *)malloc(sizeof(t_item));
	new->word = word;
	new->next = NULL;
	return (new);
}

struct s_stack *stackInit(void)
{
    t_stack *stack;

    stack = (t_stack *)calloc(1, sizeof(t_stack));
    return (stack);
}

void *pop(struct s_stack *stack)
{
    void	*st;

	if (!stack->item) return (NULL);
	st = stack->item->word;
	stack->item = stack->item->next;
	return (st);
}

void push(struct s_stack *stack, char *word)
{
    t_item  *item;

    item = newItem(word);
    if (!stack->item) {
		stack->item = item;
		return ;
	}

	item->next = stack->item;
	stack->item = item;
}