/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:52:27 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/27 19:21:52 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_node t_node;

void    go(t_node *lst, int flag)
{
    if (!lst)   return;
    go(lst->next, 1);
    printf("%s", lst->word);
    if(flag)
        printf(" ");
}

void printReverse(struct s_node *lst)
{
    go(lst, 0);
}