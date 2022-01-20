/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:06:37 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/19 19:06:54 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int args_validation(int argc, char **argv)
{
	if(is_number(argc, argv) && is_duplicate(argc, argv) /
	&& is_range(argc, argv))
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 3)
		return(1);
	if(!args_validation(argc, argv))
	{
		write(2, "Error\n", 6);
		return(1);
	}
	stack_a = init_stack_a(stack)
	return (0);
}