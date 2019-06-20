/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSW.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:25:04 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/05 22:28:43 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <limits.h>
#include <stdlib.h>

typedef struct s_deque t_deque;
typedef struct s_dequeNode t_dequeNode;

struct s_deque *dequeInit(void)
{
	t_deque *q = malloc(sizeof(t_deque));

	q->first = NULL;
	q->last = NULL;
	return (q);
}

struct s_dequeNode *nodeInit(int value)
{
	t_dequeNode *tmp = malloc(sizeof(struct s_dequeNode));

	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void pushFront(struct s_deque *deque, int value)
{
	t_dequeNode *new = nodeInit(value);

	new->next = deque->first;
	if (deque->first)
		deque->first->prev = new;
	deque->first = new;
	if (!deque->last)
		deque->last = new;
}

void pushBack(struct s_deque *deque, int value)
{
	t_dequeNode *new = nodeInit(value);

	new->prev = deque->last;
	if (deque->last)
		deque->last->next = new;
	deque->last = new;
	if (!deque->first)
		deque->first = new;
}
int popFront(struct s_deque *deque)
{
	t_dequeNode	*tmp = deque->first;
	int					value = tmp->value;

	if (!tmp)
		return (INT_MIN);
	deque->first = tmp->next;
	if (!deque->first)
		deque->last = NULL;
	else
		deque->first->prev = NULL;
	free(tmp);
	return (value);
}

int popBack(struct s_deque *deque)
{
	t_dequeNode	*tmp = deque->last;
	int					value = tmp->value;

	if (!tmp)
		return (INT_MIN);
	deque->last = tmp->prev;
	if (!deque->last)
		deque->first = NULL;
	else
		deque->last->next = NULL;
	free(tmp);
	return (value);
}

int				empty(struct s_deque *q)
{
	return (!(q->first && q->last));
}

struct s_max	*maxSlidingWindow(int *arr, int n, int k)
{
	t_deque	*dq = dequeInit();
	struct s_max	*res = malloc(sizeof(struct s_max));
	int				len = n - k + 1;
	int				i;

	res->max = calloc(len, sizeof(int));
	res->length = len;
	for (i = 0; i < k; i++)
	{
		while (!empty(dq) && arr[dq->last->value] < arr[i])
			popBack(dq);
		pushBack(dq, i);
	}
	for ( ; i < n; i++)
	{
		res->max[i - k] = arr[dq->first->value];
		while (dq->first && dq->first->value <= i - k)
			popFront(dq);
		while (dq->last && arr[dq->last->value] < arr[i])
			popBack(dq);
		pushBack(dq, i);
	}
	res->max[n - k] = arr[popFront(dq)];
	return (res);
}