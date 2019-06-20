/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPotentialCriminels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 21:56:44 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/28 23:30:42 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

typedef struct s_info t_info;
typedef struct s_criminal t_criminal;

// int getDescription(struct s_info *info)
// {
//     int k = (int)(1e6);
//     int sum = 0;
//     sum += info->gender * k;    k/=10;
//     sum += info->height * k;    k/=10;
//     sum += info->hairColor * k;    k/=10;
//     sum += info->eyeColor * k;    k/=10;
//     sum += info->glasses * k;    k/=10;
//     sum += info->tattoo * k;    k/=10;
//     sum += info->piercing * k;    k/=10;

//     return (sum);
// }

int					getDescription(struct s_info *info)
{
	int	res;

	if (!info)
		return (0);
	res = (info->gender * 1000000 + info->height * 100000 + info->hairColor * 10000
			+ info->eyeColor * 1000 + info->glasses * 100 + info->tattoo * 10 + info->piercing * 1);
	if (info->gender <= 1)
		return (res);
	return (res / 10);

}

int getMax(t_criminal **arr, int n) 
{ 
    int mx = arr[0]->description; 
    for (int i = 1; i < n; i++) 
        if (arr[i]->description > mx) 
            mx = arr[i]->description; 
    return mx; 
} 



// void countSort(t_criminal **arr, int n, int exp) 
// { 
//     t_criminal *output[n + 1]; 
//     int i, count[10] = {0}; 
  
//     for (i = 0; i < n; i++) 
//         count[ (arr[i]->description/exp)%10 ]++; 
  
//     for (i = 1; i < 10; i++) 
//         count[i] += count[i - 1]; 
  
//     for (i = n - 1; i >= 0; i--) 
//     { 
//         output[count[ (arr[i]->description/exp)%10 ] - 1]->description = arr[i]->description; 
//         output[count[ (arr[i]->description/exp)%10 ] - 1]->name = arr[i]->name; 
//         count[ (arr[i]->description/exp)%10 ]--; 
//     } 
//     for (i = 0; i < n; i++) 
//     {
//         arr[i]->description = output[i]->description;
//         arr[i]->name = output[i]->name; 
//     }
// } 

void				countSort(struct s_criminal **c, int n, int exp)
{
	struct s_criminal	*output[n];
	int					i;
	int					count[10] = {0};

	for (i = 0; i < n; i++)
		count[(c[i]->description / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(c[i]->description / exp) % 10] - 1] = c[i];
		count[(c[i]->description / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		c[i] = output[i];
}

int getSize(t_criminal **criminals)
{
    int i;
    for (i = 0; criminals[i]; )
        i++;
    return (i);
}

void sortCriminals(struct s_criminal **criminals)
{
    int n = getSize(criminals);    
    int m = getMax(criminals, n); 
  
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(criminals, n, exp); 
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info)
{
    t_criminal      **ans = NULL;
    int n = getSize(criminals);
    int d = getDescription(info);
    int i;
    
    sortCriminals(criminals);
    int l = 0, r = n - 1;
    while (l < r)
    {
        int m = (l + r) >> 1;

        if (criminals[m]->description < d)
            l = m + 1;
        else
            r = m;
    }
    int k = r - 1;
    while (k >= 0 && criminals[k]->description == d)
        k--;
    l = k + 1;
    k = r;
    while (k < n && criminals[k]->description == d)
        k++;
    r = k - 1;
    ans = (t_criminal **)malloc((r - l + 2) * sizeof(t_criminal *));
    for (i = 0; i <= (r - l); i++)
    {
        ans[i] = criminals[i + l];
    }
    ans[i] = NULL;
    return (ans);
}