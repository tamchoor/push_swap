/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:33:16 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/09 15:16:42 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_cmd(t_command **alst, t_command *new1)
{
	t_command	*ptr;

	if (*alst != NULL)
	{
		ptr = *alst;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new1;
	}
	else
	{
		*alst = new1;
	}
}

void	add_cmd(char *name, t_command_list *cmd_list)
{
	t_command	*cmd;

	cmd = (t_command *)ft_calloc (1, sizeof(t_command));
	if (!cmd)
		ft_error_print("Error\n");
	cmd->name = name;
	ft_add_cmd(&cmd_list->head, cmd);
	cmd_list->size++;
}

void	free_list_cmd(t_command_list *list)
{
	t_command	*current;
	t_command	*for_free;

	current = list->head;
	while (current)
	{
		for_free = current;
		current = current->next;
		free(for_free);
	}
	free(list);
}
