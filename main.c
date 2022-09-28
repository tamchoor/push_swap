/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:32:09 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/09 15:01:36 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_cmd_fd(t_command_list	*list, char *s, int fd)
{
	t_command	*f;

	if (!list->head)
		return ;
	f = list->head;
	if (s)
		ft_putstr_fd(s, fd);
	while (f->next)
	{
		ft_putstr_fd(f->name, fd);
		f = f->next;
	}
	ft_putstr_fd(f->name, fd);
}

void	last_rotate(t_ps *stack, t_command_list *cmd_list)
{
	t_stck	*tmp;
	int		count_r;

	tmp = stack->a;
	count_r = 0;
	while (tmp->nbr != stack->min)
	{
		count_r++;
		tmp = tmp->next;
	}
	if (count_r < stack->count_a)
	{
		while (ft_check_sort(stack->a) == 0)
			rrotate(A, stack, cmd_list, YES);
	}
	else
	{
		while (ft_check_sort(stack->a) == 0)
			rotate(A, stack, cmd_list, YES);
	}
}

int	check_limits(t_ps *stack)
{
	if ((stack->count_a <= 3 && stack->cmd_indx->size <= 3)
		|| (stack->count_a > 3 && stack->count_a <= 5
			&& stack->cmd_indx->size <= 12)
		|| (stack->count_a > 5 && stack->count_a <= 100
			&& stack->cmd_indx->size <= 700)
		|| (stack->count_a > 100 && stack->count_a <= 500
			&& stack->cmd_indx->size <= 5500)
		|| (stack->count_a > 500))
	{
		return (1);
	}
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_ps	stack;

	if (argc <= 1)
		return (0);
	stack = ft_init_stack(argc, &(*argv));
	if (ft_check_sort(stack.a) == 1)
		exit (0);
	sorting(&stack);
	last_rotate(&stack, stack.cmd_indx);
	if (check_limits(&stack) == 1)
		ft_print_cmd_fd(stack.cmd_indx, 0, 1);
	else
	{
		free_stack(&stack.a, stack.count_nbr);
		fill_stack_a(&stack);
		sorting_2(&stack);
		last_rotate(&stack, stack.cmd_alm);
		ft_print_cmd_fd(stack.cmd_alm, 0, 1);
		free_list_cmd(stack.cmd_alm);
	}
	if (argc == 2)
		ft_free_split(&stack.var);
	free_list_cmd(stack.cmd_indx);
	free_stack(&stack.a, stack.count_nbr);
	return (0);
}
