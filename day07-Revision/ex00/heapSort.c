/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:44:56 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/05 22:24:17 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

typedef struct s_art t_art;

void ft_swap(struct s_art *a, struct s_art *b)
{
    int tmp;
    char *temp;

    tmp = a->price;
    a->price = b->price;
    b->price = tmp;

    temp = a->name;
    a->name = b->name;
    b->name = temp;
}

void heap(struct s_art **masterpiece, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && strcmp(masterpiece[l]->name, masterpiece[largest]->name) > 0)
        largest = l;
    if (r < n && strcmp(masterpiece[r]->name, masterpiece[largest]->name) > 0)
        largest = r;
    if (largest != i)
    {
        ft_swap(masterpiece[i], masterpiece[largest]);
        heap(masterpiece, n, largest);
    }
}

void heapSort(struct s_art **masterpiece, int n)
{
    if (!masterpiece && !*masterpiece)
        return ;
    for (int i = n / 2; i >= 0; i--)
        heap(masterpiece, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        ft_swap(masterpiece[0], masterpiece[i]);
        heap(masterpiece, i, 0);
    }
}