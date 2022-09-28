/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:32:15 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/09 13:00:03 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_front(t_stck **lst, t_stck *new1)
{
	t_stck	*head;
	t_stck	*last;

	head = *lst;
	if (!new1)
		return ;
	if (head == NULL)
	{
		head = new1;
		head->next = head;
		head->prev = head;
	}
	else
	{
		last = head->prev;
		new1->prev = last;
		last->next = new1;
		new1->next = head;
		head->prev = new1;
		head = head->prev;
	}
	*lst = head;
}

void	push_to_stack(t_stck **s_from, t_stck **s_to, int count_from)
{
	t_stck	*temp;

	temp = (t_stck *) ft_calloc(1, sizeof(t_stck));
	if (!temp)
		ft_error_print("Error\n");
	temp->nbr = (*s_from)->nbr;
	temp->keep = (*s_from)->keep;
	temp->indx = (*s_from)->indx;
	ft_add_front(s_to, temp);
	temp = *s_from;
	if ((*s_from)->next)
	{
		(*s_from) = (*s_from)->next;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	free(temp);
	if ((count_from - 1) == 0)
		(*s_from) = NULL;
}

void	push_to(int flag, t_ps *stck, t_command_list *cmd_list, int cmd)
{
	if (flag == A && stck->count_b != 0)
	{
		push_to_stack(&stck->b, &stck->a, stck->count_b);
		stck->count_a = stck->count_a + 1;
		stck->count_b = stck->count_b - 1;
		if (cmd == YES)
			add_cmd("pa\n", cmd_list);
	}
	else if (flag == B && stck->count_a != 0)
	{
		push_to_stack(&stck->a, &stck->b, stck->count_a);
		stck->count_a = stck->count_a - 1;
		stck->count_b = stck->count_b + 1;
		if (cmd == YES)
			add_cmd("pb\n", cmd_list);
	}
}
