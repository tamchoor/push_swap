/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_sort_seq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:33:06 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/09 11:42:01 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_sort_enum(t_stck **a, int indx)
{
	int		count_sort;
	t_stck	*tmp;
	t_stck	*head;

	tmp = *a;
	head = *a;
	count_sort = 0;
	if (tmp)
	{
		tmp->keep = YES;
		tmp = tmp->next;
		while (tmp != head)
		{
			if (tmp->indx == indx + 1)
			{
				count_sort++;
				indx++;
				tmp->keep = YES;
			}
			else
				tmp->keep = NO;
			tmp = tmp->next;
		}
	}
	return (count_sort);
}

int	count_sort_almost(t_stck **a, int indx)
{
	int		count_sort;
	t_stck	*tmp;
	t_stck	*head;

	tmp = *a;
	head = *a;
	count_sort = 0;
	if (tmp)
	{
		tmp->keep = YES;
		tmp = tmp->next;
		while (tmp != head)
		{
			if (tmp->indx > indx)
			{
				count_sort++;
				indx = tmp->indx;
				tmp->keep = YES;
			}
			else
				tmp->keep = NO;
			tmp = tmp->next;
		}
	}
	return (count_sort);
}

int	max_sorted_seq(t_ps *stck,
	int (*count_s_el)(t_stck **, int))
{
	int		i;
	int		count_sort;
	t_stck	*tmp;

	count_sort = 0;
	stck->count_sort = 0;
	i = 0;
	tmp = stck->a;
	while (i < stck->count_a)
	{
		count_sort = count_s_el(&tmp, tmp->indx);
		if (count_sort > stck->count_sort)
		{
			stck->head_max_sort = tmp;
			stck->count_sort = count_sort;
		}
		else if (count_sort == stck->count_sort
			&& tmp->nbr < stck->head_max_sort->nbr)
			stck->head_max_sort = tmp;
		i++;
		tmp = tmp->next;
	}
	return (count_sort);
}
