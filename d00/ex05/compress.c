/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 08:32:25 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/26 20:38:32 by aabdrakh         ###   ########.fr       */
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

int	dictInsert(struct s_dict *dict, char *key, int value)
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

int				dictSearch(struct s_dict *dict, char *key)
{
    int x = dict->capacity;
	int k = hash(key) % x;
	struct s_item *tmp;

	tmp = dict->items[k];
	while (tmp)
	{
		if (!strcmp(key, tmp->key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (-1);
}

char	**getListFromDict(struct s_dict *dict, int *dict_count, int *dict_len)
{
	char	**list;
	int		i;
	struct s_item	*item;
	int	count;
	int	len;

	count = 0;
	len = 0;
	list = NULL;
	for (i = 0; i < dict->capacity; i++)
	{
		item = dict->items[i];
		while (item)
		{
			len += (strlen(item->key) + 1);
			count++;
			item = item->next;
		}
	}
	if (!(list = (char**)malloc(sizeof(char*) * count)))
		return (NULL);
	for (i = 0; i < dict->capacity; i++)
	{
		item = dict->items[i];
		while (item)
		{
			list[item->value] = strdup(item->key);
			item = item->next;
		}
	}
	*dict_count = count;
	*dict_len = len;
	return (list);
}

char	*getHeaderString(struct s_dict *dict, int *dict_len)
{
	char	**list;
	int		count;
	int		len;
	char	*header;
	int		i;
	int		j;

	list = getListFromDict(dict, &count, &len);
	header = (char*)calloc(1, sizeof(char) * (len + 1));
	header[0] = '<';
	j = 1;
	for (i = 0; i < count; i++)
	{
		strcpy(&header[j], list[i]);
		j += strlen(list[i]);
		header[j++] = ',';
		free(list[i]);
	}
	header[--j] = '>';
	*dict_len = len + 1;
	free(list);
	return (header);
}

char    *compress(char *book, struct s_dict *dict)
{
	char	*header;
	char	*dest;
	char	*word;
	int		len;
	int		i;
	int		l;
	int		value;

	i = 0;
	header = getHeaderString(dict, &len);
	if (!(dest = (char*)calloc(1, strlen(book) + len + 1)))
		return (NULL);
	strcpy(dest, header);
	while (book[i])
	{
		while (book[i] && !isalnum(book[i]))
			dest[len++] = book[i++];
		l = i;
		while (book[i] && isalnum(book[i]))
			i++;
		if (l < i)
		{
			word = strndup(&book[l], i - l);
			if ((value = dictSearch(dict, word)) != -1)
			{
				dest[len++] = '@';
				dest[len++] = value + 1;
			}
			else
				while (l < i)
					dest[len++] = book[l++];
			free(word);
		}
	}
	free(header);
	return (dest);
}