/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 23:10:10 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/27 23:24:47 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>

// char *NthLastCity(struct s_city *city, int n)
// {
//     printf("%s %d\n", city->name, n);
//     if (!city)
//         return (NULL);
//     if (n == -1)
//         return (city->name);
//     return (NthLastCity(city->next, n - 1));
// }

int     g_num;
char    *g_ans;

char *NthLastCity(struct s_city *city, int n)
{
	if (!city) {
		g_num = 0;
		g_ans = NULL;
	} else {
		NthLastCity(city->next, n);
		if (g_num == n) {
			g_ans = city->name;
		}
		g_num++;
	}
	return (g_ans);
}