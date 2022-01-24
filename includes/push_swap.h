/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:06:27 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/24 12:32:11 by mjose-ye         ###   ########.fr       */
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

typedef struct s_stack
{
	int	*stack;
	int	top;
} t_stack;


typedef struct s_data
{
	int		index;
	t_stack		*stack_a;
	t_stack		*stack_b;
	int		num_lower;
	int		num_higher;
	int		direction;
	int		size;
	char	*res_step;
	int		steps;
}	t_data;

int		ft_misdigit(char c);
long	ft_matoi(const char *str);
int		is_number(int argc, char **argv);
int		is_duplicate(int argc, char **argv);
int		is_integer(int argc, char **argv);
int		args_validation(int argc, char **argv);
void	*init(int argc, char **argv, t_data *conjunct, t_stack *stack);
void	push(t_stack *stack_src, t_stack *stack_dest);
void	swap(int *stack);
void	rotate(int *stack);
void	rrotate(int *stack);
void	operations(char *op, t_data *conjunct);
int		stack_size(int *stack);
void	free_all(t_data *data, int error);
int		get_lower(int *stack, t_data *conjunct);
int		get_higher(int *stack, t_data *conjunct);
int		*atribute_stack(t_data *conjunct, t_stack *stack, char **argv);
int		stack_sizep(int *stack);

#endif