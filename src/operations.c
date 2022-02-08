/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:10:03 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/02/08 00:16:36 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	double_operation(char *op, t_data *conjunct, t_stack *stack)
{
	if (!ft_strncmp(op, "ss\n", 3))
	{
		swap(conjunct->stack_a);
		swap(conjunct->stack_b);
	}
	else if (!ft_strncmp(op, "rr\n", 3))
	{
		rotate(conjunct->stack_a);
		rotate(conjunct->stack_b);
	}
	else if (!ft_strncmp(op, "rrr\n", 4))
	{
		rrotate(conjunct->stack_a);
		rrotate(conjunct->stack_b);
	}
	else
	{
		write(2, "\033[31mERROR \e[0m\n", 17);
		free_all(conjunct, stack, EXIT_FAILURE);
	}
}

void	insert_command(char *op, t_data *conjunct)
{
	char	*temp;

	temp = ft_strjoin(conjunct->res_step, op);
	free(conjunct->res_step);
	conjunct->res_step = temp;
}

void	operations(char *op, t_data *conjunct, t_stack *stack)
{
	if (!ft_strncmp(op, "sa\n", 3))
		swap(conjunct->stack_a);
	else if (!ft_strncmp(op, "sb\n", 3))
		swap(conjunct->stack_b);
	else if (!ft_strncmp(op, "pa\n", 3))
		push(conjunct->stack_b, conjunct->stack_a);
	else if (!ft_strncmp(op, "pb\n", 3))
		push(conjunct->stack_a, conjunct->stack_b);
	else if (!ft_strncmp(op, "ra\n", 3))
		rotate(conjunct->stack_a);
	else if (!ft_strncmp(op, "rb\n", 3))
		rotate(conjunct->stack_b);
	else if (!ft_strncmp(op, "rra\n", 4))
		rrotate(conjunct->stack_a);
	else if (!ft_strncmp(op, "rrb\n", 4))
		rrotate(conjunct->stack_b);
	else
		double_operation(op, conjunct, stack);
	if (conjunct->res_step == NULL)
		conjunct->res_step = ft_strdup(op);
	else
		insert_command(op, conjunct);
	conjunct->steps++;
}
