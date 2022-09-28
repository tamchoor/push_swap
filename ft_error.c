/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:31:51 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/08 17:35:32 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_print(char *str)
{
	if (str == NULL)
		perror("Error ");
	else
		write(2, str, ft_strlen(str));
	exit (EXIT_FAILURE);
}

void	ft_free_split(char ***str)
{
	int	i;

	i = 0;
	while ((*str)[i] != NULL)
	{
		free(((*str)[i]));
		i++;
	}
	free(*str);
}

int	ft_max(int a, int b)
{
	if (a > b)
	{
		return (a);
	}
	else
	{
		return (b);
	}
}
