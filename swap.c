/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:32:29 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 17:32:36 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_or_b(t_stck **stk)
{
	t_elem	one;
	t_elem	two;

	if ((*stk)->next != NULL)
	{
		one.nbr = (*stk)->nbr;
		one.keep = (*stk)->keep;
		one.indx = (*stk)->indx;
		two.nbr = (*stk)->next->nbr;
		two.keep = (*stk)->next->keep;
		two.indx = (*stk)->next->indx;
		(*stk)->next->nbr = one.nbr;
		(*stk)->next->keep = one.keep;
		(*stk)->next->indx = one.indx;
		(*stk)->nbr = two.nbr;
		(*stk)->keep = two.keep;
		(*stk)->indx = two.indx;
	}
}

void	swap(int flag, t_ps *stck, t_command_list *cmd_list, int cmd)
{
	if (flag == A && stck->a && stck->a->next)
	{
		swap_a_or_b(&stck->a);
		if (cmd == YES)
			add_cmd("sa\n", cmd_list);
	}
	else if (flag == B && stck->b && stck->b->next)
	{
		swap_a_or_b(&stck->b);
		if (cmd == YES)
			add_cmd("sb\n", cmd_list);
	}
}

void	sswap(t_ps *stck, t_command_list *cmd_list, int cmd)
{
	if (stck->b && stck->b->next && stck->a && stck->a->next)
	{
		swap_a_or_b(&stck->a);
		swap_a_or_b(&stck->b);
		if (cmd == YES)
			add_cmd("ss\n", cmd_list);
	}
}
