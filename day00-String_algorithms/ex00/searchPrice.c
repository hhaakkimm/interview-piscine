/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 06:00:11 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/25 06:10:35 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		check(char *s1, char *s2)
{
	int		i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int		searchPrice(struct s_art **arts, char *name)
{
	int		i;

	i = 0;
	if (!*arts || !name)
		return (-1);
	while (arts[i])
	{
		if (check(arts[i]->name, name))
			return (arts[i]->price);
		i++;
	}
	return (-1);
}
