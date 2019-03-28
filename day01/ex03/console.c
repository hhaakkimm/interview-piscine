/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 20:07:32 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/27 21:40:59 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_item t_item;
typedef struct s_stack t_stack;

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

char *console(void)
{
    char *mess;
    char *ans;
    size_t len = 0;
    size_t i = 0;
    size_t size;
    t_stack     *st;

    if (!(ans = (char *)calloc(255, sizeof(char))))
        return (NULL);
    st = initStack();

    while(1)
    {
        printf("?: ");
        size = getline(&mess, &len, stdin);
        mess[--size] = '\0';
        //printf("%s", mess, strcmp(mess, "SEND"));
        if (!strcmp(mess, "SEND"))
            break;
        if (!strcmp(mess, "UNDO")) {
			i = pop(st);
			memset(ans + i, 0, 255 - i);
		} else if (i + size < 255) {
			push(st, i);
			if (i > 0) {
				strcat(ans, " ");
				i++;
			}
			strcat(ans, mess);
			i += strlen(mess);
		}
		printf("%s\n\n", ans);
    }
    return (ans);
}