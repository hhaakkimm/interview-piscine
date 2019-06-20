/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 07:00:24 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/26 08:25:56 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

 int howManyJesus(char *bible, char *jesus)
 {
    if (!jesus || !bible)
        return (0);
    int ans = 0;
    int x = (int)strlen(jesus);
    int y = (int)strlen(bible);
    long long   p_pow[x];
    memset(p_pow, 0, x);
    p_pow[0] = 1;
    for (int i = 1; i < x; ++i)
    {
	    p_pow[i] = p_pow[i - 1] * 31;
        p_pow[i] %= MOD;
    }
    long long h_s = 0;
    for (int i = 0; i < x; i++)
        h_s = ((h_s % MOD) + ((int)jesus[i] * p_pow[i] % MOD)) % MOD;
    for (int i = 0; i + x - 1 < y; i++)
    {
        long long cur = 0;
        for (int j = i; j < i + x; j++)
            cur = ((cur % MOD) + ((int)bible[j] * p_pow[j - i] % MOD)) % MOD;
        if (cur == h_s)
            ans++;    
    }
    return (ans);
 }