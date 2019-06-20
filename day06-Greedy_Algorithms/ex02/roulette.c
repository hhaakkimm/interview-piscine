/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:05:24 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/04/04 21:18:26 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double probabilityWin(double firstDollarsBet, double dollarsWanted, int nbGame)
{
    if (firstDollarsBet == 0 || nbGame < 0)
        return (0.0);
    if (firstDollarsBet >= dollarsWanted)
        return (1.0);
    return ((18 * probabilityWin(firstDollarsBet * 2, dollarsWanted, nbGame - 1) + probabilityWin(firstDollarsBet / 2, dollarsWanted, nbGame - 1))/37);
}