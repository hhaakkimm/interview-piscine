/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 01:36:33 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/30 02:13:31 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

typedef struct s_node t_node;

t_node		*newNode(int value) {
	t_node	*new = calloc(1, sizeof(t_node));
	new->value = value;
	return (new);
}

t_node		*createBSTRec(int arr[], int l, int r) {
	int		m = (l + r) / 2;
	t_node	*root;

	if (l > r) 
        return (NULL);
	root = newNode(arr[m]);
	root->left = createBSTRec(arr, l, m - 1);
	root->right = createBSTRec(arr, m + 1, r);
	return (root);
}

struct s_node *createBST(int *arr, int n)
{
    t_node  *node;

    node = createBSTRec(arr, 0, n - 1);
    return (node);
}