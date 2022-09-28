/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:32:24 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/09 13:00:11 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotations(t_ps *stck, t_rotations *rotations,
		t_command_list *cmd_list)
{
	while (stck->a->nbr != rotations->a_elem.nbr
		|| stck->b->nbr != rotations->b_elem.nbr)
	{
		if (rotations->a_direction == R && rotations->b_direction == R
			&& stck->a->nbr != rotations->a_elem.nbr
			&& stck->b->nbr != rotations->b_elem.nbr)
			rotate_rotate(stck, cmd_list, YES);
		else if (rotations->a_direction == RR && rotations->b_direction == RR
			&& stck->a->nbr != rotations->a_elem.nbr
			&& stck->b->nbr != rotations->b_elem.nbr)
			rrotate_rrotate(stck, cmd_list, YES);
		else if (rotations->a_direction == R
			&& stck->a->nbr != rotations->a_elem.nbr)
			rotate(A, stck, cmd_list, YES);
		else if (rotations->a_direction == RR
			&& stck->a->nbr != rotations->a_elem.nbr)
			rrotate(A, stck, cmd_list, YES);
		else if (rotations->b_direction == R
			&& stck->b->nbr != rotations->b_elem.nbr)
			rotate(B, stck, cmd_list, YES);
		else if (rotations->b_direction == RR
			&& stck->b->nbr != rotations->b_elem.nbr)
			rrotate(B, stck, cmd_list, YES);
	}
}

void	count_rotations(t_ps *stck, t_rotations *rotations)
{
	t_stck	*elem;
	int		i;

	elem = stck->b;
	i = 0;
	if (elem)
	{
		while (i <= stck->count_b)
		{
			check_rotation(stck, rotations, elem);
			if (rotations->is_set == YES && rotations->size <= 1)
			{
				break ;
			}
			elem = elem->next;
			i++;
		}
	}
}

void	make_sort(t_ps *stck, t_command_list *cmd_list,
	int (*count_s_el)(t_stck **, int))
{
	t_rotations	rotations;

	push_to_b(stck, cmd_list, count_s_el);
	while (stck->count_b)
	{
		rotations.is_set = NO;
		count_rotations(stck, &rotations);
		do_rotations(stck, &rotations, cmd_list);
		push_to(A, stck, cmd_list, YES);
	}
}

void	sorting(t_ps *stck)
{
	index_a(stck);
	stck->cmd_indx = (t_command_list *)ft_calloc(1, sizeof(t_command_list));
	if (!stck->cmd_indx)
		ft_error_print("Error\n");
	if (stck->count_a == 3)
		sorting3(A, &stck->a, stck);
	else
	{
		stck->head_max_sort = stck->a;
		max_sorted_seq(stck, &count_sort_enum);
		count_sort_enum(&stck->head_max_sort, stck->head_max_sort->indx);
		make_sort(stck, stck->cmd_indx, &count_sort_enum);
	}
}

void	sorting_2(t_ps *stck)
{
	index_a(stck);
	stck->head_max_sort = stck->a;
	max_sorted_seq(stck, &count_sort_almost);
	count_sort_almost(&stck->head_max_sort, stck->head_max_sort->indx);
	stck->cmd_alm = (t_command_list *)ft_calloc(1, sizeof(t_command_list));
	if (!stck->cmd_alm)
		ft_error_print("Error\n");
	make_sort(stck, stck->cmd_alm, &count_sort_almost);
}
