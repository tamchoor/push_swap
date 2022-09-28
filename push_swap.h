/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:32:12 by tamchoor          #+#    #+#             */
/*   Updated: 2022/03/09 15:17:02 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

# define A 1
# define B 2
# define YES 1
# define NO 0
# define R 1
# define RR 2
# define BUFFER_SIZE 1

typedef struct s_stck
{
	int				nbr;
	struct s_stck	*next;
	struct s_stck	*prev;
	int				keep;
	int				indx;
}	t_stck;

typedef struct s_elem
{
	int	nbr;
	int	keep;
	int	indx;
}	t_elem;

typedef struct s_r_rr
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
}	t_r_rr;

typedef struct s_command
{
	char				*name;
	struct s_command	*next;
}						t_command;

typedef struct s_command_list
{
	int			size;
	t_command	*head;
}						t_command_list;

typedef struct s_ps
{
	t_stck			*a;
	t_stck			*b;
	char			**var;
	int				count_nbr;
	int				count_a;
	int				count_b;
	t_command_list	*cmd_indx;
	t_command_list	*cmd_alm;
	int				count_sort;
	t_stck			*head_max_sort;
	int				min;
	int				max;
}	t_ps;

typedef struct s_rotations
{
	t_elem		a_elem;
	t_elem		b_elem;
	int			a_direction;
	int			b_direction;
	int			size;
	int			is_set;
}						t_rotations;

int		ft_tab(int c);
void	index_a(t_ps *stck);
void	sorting(t_ps *stck);
void	free_list_cmd(t_command_list *list);
void	free_stack(t_stck **a, int count_nbr);
void	minmax(t_stck **a, int *min, int *max);
void	ft_free_split(char ***str);
void	ft_error_print(char *str);
t_ps	ft_init_stack(int argc, char **argv);
long	ft_atol(const char *str);
void	fill_stack_a(t_ps *stack);
int		ft_max(int a, int b);
void	push_to(int flag, t_ps *stck, t_command_list *cmd_list, int cmd);
void	swap(int flag, t_ps *stck, t_command_list *cmd_list, int cmd);
void	sswap(t_ps *stck, t_command_list *cmd_list, int cmd);
void	rotate(int flag, t_ps *stck, t_command_list *cmd_list, int cmd);
void	rrotate(int flag, t_ps *stck, t_command_list *cmd_list, int cmd);
void	rotate_rotate(t_ps *stck, t_command_list *cmd_list, int cmd);
void	rrotate_rrotate(t_ps *stck, t_command_list *cmd_list, int cmd);
void	ft_add_back(t_stck **alst, t_stck *new1);
void	ft_add_front(t_stck **lst, t_stck *new1);
int		ft_check_sort(t_stck *a);
void	ft_add_cmd(t_command **alst, t_command *new1);
void	add_cmd(char *name, t_command_list *cmd_list);
char	*get_next_line(int fd);
size_t	ft_strlen1(char *str);
char	*ft_strchr1(char *s, int c);
char	*ft_strjoin1(char *s1, char *s2);
int		count_sort_enum(t_stck **a, int indx);
int		count_sort_almost(t_stck **a, int indx);
int		max_sorted_seq(t_ps *stck,
			int (*count_s_el)(t_stck **, int));
void	push_to_b(t_ps *stck, t_command_list *cmd_list,
			int (*count_s_el)(t_stck **, int));
void	make_sort(t_ps *stck, t_command_list *cmd_list,
			int (*count_s_el)(t_stck **, int));
void	count_rotations(t_ps *stck, t_rotations *rotations);
void	check_rotation(t_ps *stck, t_rotations *rotations, t_stck *elem_in_b);
void	sorting_2(t_ps *stck);
void	sorting3(int flag, t_stck **a, t_ps *stck);

#endif