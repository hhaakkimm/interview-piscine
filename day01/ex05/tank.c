/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:33:16 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/27 23:08:06 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

typedef struct s_elem t_item;
typedef struct s_stack t_stack;
typedef struct s_tank t_tank;

t_item		*newItem(int energy) {
	t_item	*new;

	new = (t_item *)malloc(sizeof(t_item));
	new->energy = energy;
	new->next = NULL;
	return (new);
}

struct s_tank *initTank(void)
{
	t_tank *tank;

	tank = (t_tank *)calloc(1,sizeof(t_tank));
	return (tank);
}

int			pop(t_stack *stack)
{
	int	st;

	if (!stack->elem) return (-1);
	st = stack->elem->energy;
	stack->elem = stack->elem->next;
	stack->sum = stack->sum - st;
	return (st);
}

void push(struct s_stack *stack, int energy)
{
    t_item  *item;

    item = newItem(energy);
	stack->sum += energy;
    if (!stack->elem) {
		stack->elem = item;
		return ;
	}

	item->next = stack->elem;
	stack->elem = item;
}

t_stack		*initStack(void) {
	t_stack		*st;

	st = (t_stack *)calloc(1, sizeof(t_stack));
	return (st);
}

void		addStack(t_tank *t) {
	t->n++;
	t->stacks = realloc(t->stacks, t->n * sizeof(t_stack));
	t->stacks[t->n - 1] = calloc(1, sizeof(t_stack));
	t->stacks[t->n - 1]->sum = 0;
}

void		removeStack(t_tank *t) {
	t->n--;
	free(t->stacks[t->n]);
	if (t->n == 0) {
		free(t->stacks);
		t->stacks = NULL;
	} else {
		t->stacks = realloc(t->stacks, t->n * sizeof(t_stack));
	}
}

t_stack		*currentStack(t_tank *t) {
	if (t->n == 0) return (NULL);
	return (t->stacks[t->n - 1]);
}

void		tankPush(struct s_tank *tank, int energy) {
	t_stack		*stack;

	if (!tank || !energy) return ;
	stack = currentStack(tank);
	if (!stack || stack->sum + energy > 1000) {
		addStack(tank);
	}
	push(currentStack(tank), energy);
}

int			tankPop(struct s_tank *tank) {
	t_stack		*stack;
	int		res = 0;

	if (tank  && (stack = currentStack(tank))) {
		res = pop(stack);
		if (stack->sum == 0) removeStack(tank);
	}
	return (res);
}