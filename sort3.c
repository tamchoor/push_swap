/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:32:27 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 17:41:35 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting3(int flag, t_stck **a, t_ps *stck)
{
	int	min;
	int	max;

	minmax(a, &min, &max);
	if ((*a)->nbr == max)
		rotate(flag, stck, stck->cmd_indx, YES);
	if ((*a)->nbr != max && (*a)->nbr != min)
	{
		if ((*a)->next->nbr == max)
			rrotate(flag, stck, stck->cmd_indx, YES);
		else
			swap(flag, stck, stck->cmd_indx, YES);
	}
	if ((*a)->next->nbr == max)
	{
		rrotate(flag, stck, stck->cmd_indx, YES);
		swap(flag, stck, stck->cmd_indx, YES);
	}
}
