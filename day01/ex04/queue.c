/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:46:08 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/27 22:35:34 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

typedef struct s_node t_item;
typedef struct s_queue t_queue;

t_item		*newItem(char *message) {
	t_item	*new;

	new = (t_item *)malloc(sizeof(t_item));
	new->message = message;
	new->next = NULL;
	return (new);
}

struct s_queue *queueInit(void)
{
    t_queue *queue;

    queue = (t_queue *)calloc(1, sizeof(t_queue));
    queue->first = NULL;
    queue->last = NULL;
    return (queue);
}

char *dequeue(struct s_queue *queue)
{
    char	*msg;
	
	if (isEmpty(queue)) return (NULL);
	msg = queue->first->message;
	queue->first = queue->first->next;
	if (!queue->first) queue->last = NULL;
	return (msg);
}

void enqueue(struct s_queue *queue, char *message)
{
    t_item	*new = newItem(message);

	if (isEmpty(queue)) {
		queue->first = new;
		queue->last = new;
		return ;
	}
	queue->last->next = new;
	queue->last = new;
}

char *peek(struct s_queue *queue)
{
    t_item  *item;

    if (isEmpty(queue))
        return (NULL);
    return (queue->first->message);
}

int isEmpty(struct s_queue *queue)
{
    if (queue && queue->first)
        return (1);
    return (0);
}