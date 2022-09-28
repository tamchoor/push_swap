/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:32:03 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 17:35:05 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	minmax(t_stck **a, int *min, int *max)
{
	t_stck	*tmp;

	tmp = *a;
	*min = tmp->nbr;
	*max = tmp->nbr;
	tmp = tmp->next;
	while (tmp != (*a))
	{
		if (*min > tmp->nbr)
			*min = tmp->nbr;
		if (*max < tmp->nbr)
			*max = tmp->nbr;
		tmp = tmp->next;
	}
}

int	find_next_min(t_stck **a, int prev, int max)
{
	int		min;
	t_stck	*tmp;

	tmp = *a;
	min = max;
	tmp = tmp->next;
	while (tmp != (*a))
	{
		if (min > tmp->nbr && prev < tmp->nbr)
		{
			min = tmp->nbr;
		}
		tmp = tmp->next;
	}
	if (min > tmp->nbr && prev < tmp->nbr)
		min = tmp->nbr;
	return (min);
}

void	index_a(t_ps *stck)
{
	t_stck	*tmp;
	int		next_min;
	int		indx;

	indx = 0;
	minmax(&stck->a, &stck->min, &stck->max);
	next_min = stck->min;
	tmp = stck->a;
	while (indx != stck->count_a)
	{
		if (tmp->nbr == next_min)
		{
			tmp->indx = indx;
			next_min = find_next_min(&stck->a, next_min, stck->max);
			tmp = stck->a;
			indx = indx + 1;
			continue ;
		}
		tmp = tmp->next;
	}
}
