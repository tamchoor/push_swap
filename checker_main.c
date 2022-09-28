/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:31:41 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/09 17:52:28 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_cmd(char *cmd)
{
	int	count;

	count = ft_strlen(cmd);
	if (count == 3)
	{
		if ((ft_memcmp(cmd, "sa\n", 3) == 0)
			|| (ft_memcmp(cmd, "sb\n", 3) == 0)
			|| (ft_memcmp(cmd, "ss\n", 3) == 0)
			|| (ft_memcmp(cmd, "pa\n", 3) == 0)
			|| (ft_memcmp(cmd, "pb\n", 3) == 0)
			|| (ft_memcmp(cmd, "ra\n", 3) == 0)
			|| (ft_memcmp(cmd, "rb\n", 3) == 0)
			|| (ft_memcmp(cmd, "rr\n", 3) == 0))
			return (1);
	}
	else if (count == 4)
	{
		if ((ft_memcmp(cmd, "rra\n", 4) == 0)
			|| (ft_memcmp(cmd, "rrb\n", 4) == 0)
			|| (ft_memcmp(cmd, "rrr\n", 4) == 0))
			return (1);
	}
	return (0);
}

void	execve_cmd(char *cmd, t_ps *stack)
{
	if (ft_memcmp(cmd, "sa\n", 3) == 0)
		swap(A, stack, 0, 0);
	if (ft_memcmp(cmd, "sb\n", 3) == 0)
		swap(B, stack, 0, 0);
	if (ft_memcmp(cmd, "ss\n", 3) == 0)
		sswap(stack, 0, 0);
	if (ft_memcmp(cmd, "pa\n", 3) == 0)
		push_to(A, stack, 0, 0);
	if (ft_memcmp(cmd, "pb\n", 3) == 0)
		push_to(B, stack, 0, 0);
	if (ft_memcmp(cmd, "ra\n", 3) == 0)
		rotate(A, stack, 0, 0);
	if (ft_memcmp(cmd, "rb\n", 3) == 0)
		rotate(B, stack, 0, 0);
	if (ft_memcmp(cmd, "rr\n", 3) == 0)
		rotate_rotate(stack, 0, 0);
	if (ft_memcmp(cmd, "rra\n", 4) == 0)
		rrotate(A, stack, 0, 0);
	if (ft_memcmp(cmd, "rrb\n", 4) == 0)
		rrotate(B, stack, 0, 0);
	if (ft_memcmp(cmd, "rrr\n", 4) == 0)
		rrotate_rrotate(stack, 0, 0);
}

void	free_stack_aaa(t_stck **a, int count_nbr)
{
	int		i;
	t_stck	*current;
	t_stck	*for_free;

	i = 0;
	current = *a;
	while (i < count_nbr)
	{
		for_free = current;
		current = current->next;
		free(for_free);
		i++;
	}
	*a = NULL;
}

void	do_cmd(t_ps *stack)
{
	char	*cmd;
	int		count_cmd;

	count_cmd = 0;
	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			break ;
		if (ft_check_cmd(cmd) == 0)
			ft_error_print("Error\n");
		execve_cmd(cmd, stack);
		free(cmd);
		count_cmd++;
	}
	if (ft_check_sort(stack->a) == 1 && stack->count_b == 0)
		write(1, "OK\n", 3);
	else if (ft_check_sort(stack->a) == 0 && count_cmd == 0)
		ft_error_print("Error\n");
	else if (ft_check_sort(stack->a) == 0 && count_cmd != 0)
	{
		write(1, "KO\n", 3);
	}
}

int	main(int argc, char **argv)
{
	t_ps	stack;

	if (argc == 1)
		exit(0);
	stack = ft_init_stack(argc, &(*argv));
	do_cmd(&stack);
	free_stack_aaa(&stack.a, stack.count_a);
	if (stack.count_b != 0)
		free_stack_aaa(&stack.b, stack.count_b);
	if (argc == 2)
		ft_free_split(&stack.var);
	return (0);
}
