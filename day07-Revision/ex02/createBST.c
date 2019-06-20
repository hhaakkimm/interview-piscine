/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:29:52 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/05 22:30:38 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

struct s_node	*createNode(int value)
{
	struct s_node *res;

	res = (struct s_node*)malloc(sizeof(struct s_node));
	res->value = value;
	res->left = NULL;
	res->right = NULL;
	return (res);
}

struct s_node *arrToBST(int *arr, int l, int r)
{
	int mid;
	struct s_node	*new;

	if (l <= r)
	{
		mid = l + (r - l) / 2;
		new = createNode(arr[mid]);
		new->left = arrToBST(arr, l, mid - 1);
		new->right = arrToBST(arr, mid + 1, r);
		return (new);
	}
	return (NULL);
}

struct s_node *createBST(int *arr, int n)
{
    int i;
    struct s_node   *root;

    if (n == 0)
        return (NULL);
    root = NULL;
    i = -1;
	root = arrToBST(arr, 0, n - 1);
    return (root);
}