/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:32:21 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 17:40:01 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	elem_in_stack_a(t_ps *stck, int indx_b_el)
{
	t_stck	*tmp;
	t_elem	elem;

	minmax(&stck->a, &stck->min, &stck->max);
	tmp = stck->a;
	while (tmp->nbr != stck->min)
		tmp = tmp->next;
	if (tmp->indx < indx_b_el)
	{
		while (tmp->nbr != stck->max)
			tmp = tmp->prev;
		if (tmp->indx < indx_b_el)
			tmp = tmp->next;
		else
		{
			tmp = tmp->next;
			while (indx_b_el > tmp->indx)
				tmp = tmp->next;
		}
	}
	elem.nbr = tmp->nbr;
	elem.keep = tmp->keep;
	elem.indx = tmp->indx;
	return (elem);
}

void	count_r(t_stck **a, int *r, int indx)
{
	t_stck	*tmp;

	tmp = *a;
	while (tmp->indx != indx)
	{
		(*r)++;
		tmp = tmp->next;
	}
}

void	count_r_rr(t_ps *stck, int indx_a, int indx_b, t_r_rr *rot)
{
	t_stck	*head;

	count_r(&stck->a, &rot->ra, indx_a);
	count_r(&stck->b, &rot->rb, indx_b);
	head = stck->a;
	while (head->indx != indx_a)
	{
		rot->rra++;
		head = head->prev;
	}
	head = stck->b;
	while (head->indx != indx_b)
	{
		rot->rrb++;
		head = head->prev;
	}
}

void	set_rotations(int count,
	t_rotations *tmp_rotations, t_rotations *rotations)
{
	if (rotations->is_set == NO || count < rotations->size)
	{
		rotations->a_direction = tmp_rotations->a_direction;
		rotations->b_direction = tmp_rotations->b_direction;
		rotations->a_elem = tmp_rotations->a_elem;
		rotations->b_elem = tmp_rotations->b_elem ;
		rotations->size = count;
		rotations->is_set = YES;
	}
}

void	check_rotation(t_ps *stck, t_rotations *rotations, t_stck *elem_in_b)
{
	t_rotations	tmp_rotations;
	t_r_rr		rot;

	rot.ra = 0;
	rot.rra = 0;
	rot.rb = 0;
	rot.rrb = 0;
	tmp_rotations.a_elem = elem_in_stack_a(stck, elem_in_b->indx);
	tmp_rotations.b_elem.nbr = elem_in_b->nbr;
	tmp_rotations.b_elem.keep = elem_in_b->keep;
	tmp_rotations.b_elem.indx = elem_in_b->indx;
	count_r_rr(stck, tmp_rotations.a_elem.indx,
		tmp_rotations.b_elem.indx, &rot);
	tmp_rotations.a_direction = R;
	tmp_rotations.b_direction = R;
	set_rotations(ft_max(rot.ra, rot.rb), &tmp_rotations, rotations);
	tmp_rotations.a_direction = RR;
	set_rotations((rot.rra + rot.rb), &tmp_rotations, rotations);
	tmp_rotations.b_direction = RR;
	set_rotations(ft_max(rot.rra, rot.rrb), &tmp_rotations, rotations);
	tmp_rotations.a_direction = R;
	set_rotations((rot.ra + rot.rrb), &tmp_rotations, rotations);
}
