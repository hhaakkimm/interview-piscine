/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:31:52 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/29 21:54:06 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

typedef struct s_node t_node;
typedef struct s_info t_info;

int     ft_max(int a, int b)
{
    return ((a > b) ? a : b);
}

void    setVal(t_node *node, t_info *info)
{
    if (!node)
		return ;
	info->elements++;
	if (node->value < info->min) info->min = node->value;
	if (node->value > info->max) info->max = node->value;
	setVal(node->left, info);
	setVal(node->right, info);
}

int getHeight(t_node *node)
{
    if (!node || (!node->left && !node->right)) 
        return (0);
    return (ft_max(getHeight(node->left), getHeight(node->right)) + 1);
}

int			getDepth(t_node *node) {
	if (!node)
        return (0);
	return (ft_max(getDepth(node->left), getDepth(node->right)) + 1);
}


int isBst(t_node *node, int min, int max)
{
    if (!node) return (1);
	if (node->value < min || node->value > max) return (0);
	return (isBst(node->left, min, node->value)
		&& isBst(node->right, node->value, max));
}

int			checkIfBalanced(t_node *node) {
	if (!node)
        return (1);
	if (abs(getDepth(node->left) - getDepth(node->right)) <= 1 &&
		checkIfBalanced(node->left) && checkIfBalanced(node->right))
			return (1);
	return (0);
}

struct s_info   getInfo(struct s_node *root)
{
    t_info  info;
    if (root)
    {
        info.max = root->value;
        info.min = root->value;
    }
    setVal(root, &info);
    info.height = getHeight(root);
    info.isBalanced = checkIfBalanced(root);
    info.isBST = isBst(root, info.min, info.max);
    return (info);       
}