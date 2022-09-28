/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:32:06 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/09 15:01:01 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	find_c(char *str)
{
	char	c;
	int		i;

	i = 0;
	while (ft_tab(str[i]) == 0)
	{
		i++;
	}
	c = str[i];
	return (c);
}

void	split_vars(int argc, char **argv, t_ps *stack)
{
	if (argc != 2)
	{
		stack->var = &argv[1];
		stack->count_nbr = argc - 2;
	}
	else
	{
		stack->count_nbr = 0;
		stack->var = ft_split(argv[1], find_c(*argv));
		if (stack->var == NULL)
			ft_error_print("Error\n");
		while (stack->var[stack->count_nbr])
		{
			stack->count_nbr++;
		}
		stack->count_nbr--;
	}
	if (stack->count_nbr == -1)
		exit(0);
}

int	check_digital(char *s1)
{
	int	i;

	i = 0;
	while (s1[i] && i != 12)
	{
		if (ft_isdigit_and_sign(s1[0]) == 0
			|| (ft_isdigit(s1[i]) == 0 && i >= 1))
			ft_error_print("Error\n");
		i++;
		if (!s1[i])
		{
			break ;
		}
	}
	if (i == 1)
	{
		if (ft_isdigit(s1[0]) == 0 && s1[1] == '\0')
			ft_error_print("Error\n");
	}
	if (i >= 12 || i == 0)
		ft_error_print("Error\n");
	return (1);
}

void	ft_cheak_argv(int count, t_ps *stack)
{
	int	i;

	i = 0;
	while (i <= count)
	{
		check_digital(stack->var[i]);
		i++;
	}
}

t_ps	ft_init_stack(int argc, char **argv)
{
	t_ps	stack;

	stack.a = NULL;
	stack.b = NULL;
	stack.count_nbr = 0;
	stack.count_a = 0;
	stack.count_b = 0;
	split_vars(argc, &(*argv), &stack);
	ft_cheak_argv(stack.count_nbr, &stack);
	fill_stack_a(&stack);
	return (stack);
}
