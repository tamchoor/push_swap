/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:33:01 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/09 11:33:03 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_keep_in_stack(t_stck **a, int count)
{
	t_stck	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (i <= count)
	{
		if (tmp->keep == 0)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	check_swap(t_ps *stck, int (*count_s_el)(t_stck **, int))
{
	int	count_sort;

	if (stck->a && stck->a->next)
	{
		swap(A, stck, 0, 0);
		count_sort = count_s_el(&stck->head_max_sort,
				stck->head_max_sort->indx);
		swap(A, stck, 0, 0);
		stck->count_sort = count_s_el(&stck->head_max_sort,
				stck->head_max_sort->indx);
		if (count_sort > stck->count_sort)
			return (1);
	}
	return (0);
}

void	push_to_b(t_ps *stck, t_command_list *cmd_list,
		int (*count_s_el)(t_stck **, int))
{
	while (check_keep_in_stack(&stck->a, stck->count_a) == 0)
	{
		if (check_swap(stck, count_s_el) == 1)
		{
			swap(A, stck, cmd_list, YES);
			count_s_el(&stck->head_max_sort, stck->head_max_sort->indx);
		}
		else if (stck->a->keep == 1)
		{
			rotate(A, stck, cmd_list, YES);
		}
		else
		{
			push_to(B, stck, cmd_list, YES);
		}
	}
}
