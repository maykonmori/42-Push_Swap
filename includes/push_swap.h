/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:06:27 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/02/08 00:17:09 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../42_Libft/libft.h"

# define FALSE 1
# define TRUE 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define STOP 2147483648

typedef struct s_slice
{
	int	*chunks;
	int	size;
}	t_slice;

typedef struct s_stack
{
	int	*stack;
	int	top;
}	t_stack;

typedef struct s_data
{
	int			index;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*stack_aux;
	t_slice		*slice;
	int			num_lower;
	int			num_higher;
	int			numb_lower;
	int			numb_higher;
	int			direction;
	int			size;
	char		*res_step;
	int			steps;
}	t_data;

int		ft_misdigit(char c);
long	ft_matoi(const char *str);
int		is_number(int argc, char **argv);
int		is_duplicate(int argc, char **argv);
int		is_integer(int argc, char **argv);
int		args_validation(int argc, char **argv);
void	*init(int argc, char **argv, t_data *conjunct, t_stack *stack);
void	push(t_stack *stack_src, t_stack *stack_dest);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	rrotate(t_stack *stack);
void	operations(char *op, t_data *conjunct, t_stack *stack);
void	free_all(t_data *conjunct, t_stack *stack, int error);
int		get_lower(t_stack *stack);
int		get_higher(t_stack *stack);
int		*atribute_stack(t_data *conjunct, t_stack *stack, char **argv);
void	push_swap(t_data *conjunct, t_stack *stack);
int		is_sorted(t_stack *stack);
void	sort_stack(t_data *conjunct, t_stack *stack);
void	insert_command(char *op, t_data *conjunct);
void	sort_long(t_data *conjunct, t_stack *stack);
int		locate_lower(t_data *conjunct);
void	bubble_sort(int *tab, int size);
void	setting_push(t_data *conjunct, t_stack *stack, int higher);

#endif