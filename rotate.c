/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:32:18 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 17:32:20 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int flag, t_ps *stck, t_command_list *cmd_list, int cmd)
{
	if (flag == A && stck->a && stck->a->next)
	{
		stck->a = stck->a->next;
		if (cmd == YES)
			add_cmd("ra\n", cmd_list);
	}
	else if (flag == B && stck->b && stck->b->next)
	{
		stck->b = stck->b->next;
		if (cmd == YES)
			add_cmd("rb\n", cmd_list);
	}
}

void	rrotate(int flag, t_ps *stck, t_command_list *cmd_list, int cmd)
{
	if (flag == A && stck->a && stck->a->next)
	{
		stck->a = stck->a->prev;
		if (cmd == YES)
			add_cmd("rra\n", cmd_list);
	}
	else if (flag == B && stck->b && stck->b->next)
	{
		stck->b = stck->b->prev;
		if (cmd == YES)
			add_cmd("rrb\n", cmd_list);
	}
}

void	rotate_rotate(t_ps *stck, t_command_list *cmd_list, int cmd)
{
	if (stck->b && stck->b->next && stck->a && stck->a->next)
	{
		stck->a = stck->a->next;
		stck->b = stck->b->next;
		if (cmd == YES)
			add_cmd("rr\n", cmd_list);
	}
}

void	rrotate_rrotate(t_ps *stck, t_command_list *cmd_list, int cmd)
{
	if (stck->b && stck->b->next && stck->a && stck->a->next)
	{
		stck->a = stck->a->prev;
		stck->b = stck->b->prev;
		if (cmd == YES)
			add_cmd("rrr\n", cmd_list);
	}
}
