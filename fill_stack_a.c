/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:31:45 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/09 14:46:13 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_back(t_stck **lst, t_stck *new1)
{
	t_stck	*ptr;
	t_stck	*head;

	if (*lst != NULL)
	{
		ptr = *lst;
		head = *lst;
		while (ptr->next != head)
			ptr = ptr->next;
		new1->prev = ptr;
		new1->next = head;
		head->prev = new1;
		ptr->next = new1;
	}
	else if (new1 != NULL)
	{
		*lst = new1;
		(*lst)->next = *lst;
		(*lst)->prev = *lst;
	}
}

int	ft_check_sort(t_stck *a)
{
	t_stck	*first;
	t_stck	*head;

	first = a;
	head = a;
	while (first && first->next && first->next != head)
	{
		if (first->nbr < first->next->nbr)
			first = first->next;
		else
			return (0);
	}
	return (1);
}

void	check_repeat_nbr(t_stck **a, int count)
{
	t_stck	*tmp;
	t_stck	*current;
	int		nbr;
	int		i;
	int		j;

	tmp = *a;
	nbr = tmp->nbr;
	i = 0;
	while (i < count - 1)
	{
		nbr = tmp->nbr;
		current = tmp->next;
		j = 0;
		while (j < count - 1 - i)
		{
			if (current->nbr == nbr)
				ft_error_print("Error\n");
			current = current->next;
			j++;
		}
		tmp = tmp->next;
		i++;
	}
}

void	free_stack(t_stck **a, int count_nbr)
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
	free(current);
	*a = NULL;
}

void	fill_stack_a(t_ps *stack)
{
	int		i;
	t_stck	*new1;
	long	nbr;

	i = 0;
	while ((stack)->var[i])
	{
		new1 = (t_stck *) ft_calloc(1, sizeof(t_stck));
		if (!new1)
			ft_error_print("Error\n");
		nbr = ft_atol((stack)->var[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			ft_error_print("Error\n");
		new1->nbr = (int) nbr;
		ft_add_back(&(stack)->a, new1);
		i++;
	}
	stack->count_a = stack->count_nbr + 1;
	check_repeat_nbr(&stack->a, stack->count_a);
}
