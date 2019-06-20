/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 04:51:50 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/26 19:39:16 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"


size_t hash(char *input)
{
    size_t res = 0, p_pow = 1;
    int p = 31;
    for (size_t i = 0; input[i]; ++i)
    {
		res = ((res % MOD) + ((input[i]) * p_pow) % MOD) % MOD;
    	p_pow *= p;
		p_pow %= MOD;
    }
    return (res);
}

// size_t hash(char *input)
// {
//     size_t res = 0;
//     //int p = 31;
//     for (size_t i = 0; input[i]; ++i)
//     {
// 		res += (size_t)input[i];
//     }
//     return (res);
// }

int	dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
    int x = dict->capacity;
    size_t el = hash(key) % x;

	if (!dict->items[el])
	{
		if (!(dict->items[el] = (struct s_item *)malloc(sizeof(struct s_item))))
			return (0);
		dict->items[el]->key = key;
		dict->items[el]->value = value;
		dict->items[el]->next = NULL;
	}
	else
	{
		struct s_item *tmp = dict->items[el];
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (struct s_item *)malloc(sizeof(struct s_item));
		tmp->next->key = key;
		if (!tmp->next || !tmp->next->key)
			return (0);
		tmp->next->value = value;
		tmp->next->next = NULL;
	}
	return (1);
}

struct s_dict *dictInit(int capacity)
{
    struct s_dict *dict = (struct s_dict *)malloc(sizeof(struct s_dict));
	dict->capacity = capacity;
	dict->items = (struct s_item **)malloc(capacity * sizeof(struct s_item *));
    memset(dict->items, 0, capacity);
	return (dict);
}

struct s_art *dictSearch(struct s_dict *dict, char *key)
{
    int x = dict->capacity;
	int k = hash(key) % x;
	struct s_item *tmp;

	tmp = dict->items[k];
	while (tmp)
	{
		if (!strcmp(key, tmp->value->name))
			return (tmp->value);
		tmp = tmp->next;
	}
	return(NULL);
}

int searchPrice(struct s_dict *dict, char *name)
{
    struct	s_art *test = dictSearch(dict, name);
	if (test)
		return (test->price);
	return (-1);
}