/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:29:18 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/27 20:56:26 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

typedef struct s_node t_node;

t_node  *newNode(char c)
{
    t_node *node;

    node = (t_node *)malloc(sizeof(t_node));
    node->c = c;
    node->next = node;
    node->prev = node;

    return (node);
} 

void    dllInsert(t_node **list, char c)
{
    t_node  *new;

    new = newNode(c);
    if (!*list)
    {
        *list = new;
    }
    else
    {
        new->next = (*list)->prev->next;
        new->prev = (*list)->prev;
        (*list)->prev->next = new;
        (*list)->prev = new;
    }
}

t_node    *build()
{
    t_node *list;

    list = NULL;
    for (size_t i = 0; i < strlen(CS); i++)
        dllInsert(&list, CS[i]);
    return (list);
}

char *precious(int *text, int size)
{
    char *ans;
    t_node  *list;

    list = build();
    if (!(ans = (char *)malloc(sizeof(char) * (size + 1))))
        return (NULL);
    for (int i = 0; i < size; i++)
    {
        if (text[i] < 0)
            while(text[i]++)
                list = list->prev;
        else
            while(text[i]--)
                list = list->next;
        ans[i] = list->c;
    }
    return (ans);
}
