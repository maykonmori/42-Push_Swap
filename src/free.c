/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:58:28 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/02/08 11:59:47 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_data *conjunct, t_stack *stack, int error)
{
	free(stack->stack);
	free(conjunct->stack_a->stack);
	free(conjunct->stack_a);
	free(conjunct->stack_b->stack);
	free(conjunct->stack_b);
	free(conjunct->stack_aux->stack);
	free(conjunct->stack_aux);
	free(conjunct->res_step);
	free(conjunct->slice);
	free(conjunct);
	free(stack);
	if (error == EXIT_FAILURE)
		exit(1);
	exit(0);
}
