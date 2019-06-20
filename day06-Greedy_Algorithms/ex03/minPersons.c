/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minPersons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:19:43 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/04 21:31:24 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int binpow(double a, int n)
{
    double res = 1.0;

    while (n)
    {
        if (n & 1)
            res *= a;
        a *= a;
        n /= 2;
    }
    return (res);
}

int		minPersons(int elements, int minPercentage)
{
    int count = 2;
	double percent = 0.0;

	while (percent * 100 < minPercentage) {
		percent = 1.0 - (double)(binpow((double)(elements - 1) / elements,
			(count * (count - 1)) / 2));
		count++;
	}
	return (count - 1);    
}