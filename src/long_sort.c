/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:22:42 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/02/05 21:43:39 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	setting_slice_size(t_data *conjunct)
{
	conjunct->slice->size = 18;
	if (conjunct->stack_a->top >= 400)
		conjunct->slice->size = 43;
	return (conjunct->slice->size);
}

int	*set_slice(int *aux_order, int *chunks, int size, t_stack *stack)
{
	int	i, j;

	chunks = (int *)ft_calloc(sizeof(int *), size);
	i = 0;
	j = stack->top;
	while (j > -1)
	{
		if (j - size  > -1)
		{
			chunks[i] = aux_order[j - size];
			i++;
			j = j - size;
		}
		else
		{
			chunks[i] = aux_order[0];
			j = -1;
		}
	}

	return (chunks);
}

void	bubble_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = size;
	while (i >= 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j--;
		}
		i--;
	}
}

int locate_lower(t_data *conjunct)
{
	int i;

	i = conjunct->stack_a->top;

	while (conjunct->stack_a->stack[i] != conjunct->num_lower)
	{
		i--;
	}
	return(i);
}

int locate_next_down(t_data *conjunct, int higher)
{
	int i;

	i = 0;

	while (conjunct->stack_a->stack[i] != higher)
	{
		if(conjunct->stack_a->stack[i] < higher)
			return (i);
		i++;
	}
	return(i);
}

int locate_next_up(t_data *conjunct, int higher)
{
	int i;

	i = conjunct->stack_a->top;

	while (conjunct->stack_a->stack[i] != higher)
	{
		if(conjunct->stack_a->stack[i] < higher)
			return (i);
		i--;
	}
	return(i);
}

static int locate_higher_b(t_data *conjunct)
{
	int i;

	i = conjunct->stack_b->top;

	while (conjunct->stack_b->stack[i] != conjunct->numb_higher)
	{
		i--;
	}
	return(i);
}

static int test_negative(int c)
{
	if (c < 0)
		c = c * -1;
	return (c);
}

static void sort_long_b(t_data *conjunct, t_stack *stack)
{
	int middle;
	int higher;
	int pos_higher;

	while (conjunct->stack_b->top != -1)
	{
		middle = conjunct->stack_b->top / 2;
		conjunct->numb_higher = get_higher(conjunct->stack_b);
		pos_higher = locate_higher_b(conjunct);
		if(pos_higher >= middle)
		{
			while (conjunct->numb_higher != conjunct->stack_b->stack[conjunct->stack_b->top])
			{
				if((conjunct->numb_higher != conjunct->stack_b->stack[conjunct->stack_b->top]) &&
				(conjunct->numb_higher != conjunct->stack_b->stack[conjunct->stack_b->top - 1]))
					operations("rb\n", conjunct, stack);
				else if ((conjunct->numb_higher != conjunct->stack_b->stack[conjunct->stack_b->top]) && (conjunct->numb_higher == conjunct->stack_b->stack[conjunct->stack_b->top - 1]))
					operations("sb\n", conjunct, stack);
			}
		}
		else if (pos_higher < middle)
		{
			while (conjunct->numb_higher != conjunct->stack_b->stack[conjunct->stack_b->top])
			{
				operations("rrb\n", conjunct, stack);
			}
		}
		operations("pa\n", conjunct, stack);
	}
	// while (conjunct->stack_b->stack[0] != conjunct->numb_lower)
	// {
	// 	operations("rrb\n", conjunct, stack);
	// }
	// while (conjunct->stack_b->top != -1)
	// {
	// 	operations("pa\n", conjunct, stack);
	// 	conjunct->num_lower = get_lower(conjunct->stack_a);
	// 	conjunct->num_higher = get_higher(conjunct->stack_a);
	// 	if (conjunct->stack_a->stack[0] != conjunct->num_higher)
	// 	{
	// 		operations("ra\n", conjunct, stack);
	// 	}
	// }
}

void sort_long(t_data *conjunct, t_stack * stack)
{
	t_slice *slice;
	int *aux_order;
	int lower;
	int i;

	// conjunct->slice = (t_slice *)ft_calloc(sizeof(t_slice), 1);
	conjunct->slice->size = setting_slice_size(conjunct);
	bubble_sort(conjunct->stack_aux->stack, conjunct->stack_aux->top);
	conjunct->slice->chunks = set_slice(conjunct->stack_aux->stack, conjunct->slice->chunks, conjunct->slice->size, conjunct->stack_a);
	i = 0;
	lower = conjunct->num_lower;
	while (!is_sorted(conjunct->stack_a) && conjunct->stack_a->top > -1)
	{
		setting_push(conjunct, stack, conjunct->slice->chunks[i], lower);
		lower = conjunct->slice->chunks[i];
		i++;
	}
	sort_long_b(conjunct, stack);
	free(conjunct->slice->chunks);
}

void setting_push(t_data *conjunct, t_stack *stack, int higher, int lower)
{
	int middle, pos_lower, pos_higher;
	int next_up, next_down;
	int i;
	int loop;

	if (higher == conjunct->slice->chunks[0])
		loop = conjunct->slice->size;
	else
		loop = conjunct->slice->size - 1;

	while(loop > -1)
	{
		middle = conjunct->stack_a->top / 2;
		// pos_lower = locate_lower(conjunct, lower);
		// pos_higher = locate_higher(conjunct);
		next_up = locate_next_up(conjunct, higher);
		next_down = locate_next_down(conjunct, higher);
		if(test_negative(middle - next_up) >= test_negative(middle - next_down))
		{
			if(middle - next_up <= 0)
			{
				i = conjunct->stack_a->top - next_up;
				while (i > 0)
				{
					conjunct->numb_higher = get_higher(conjunct->stack_b);
					if((i > 1) && (conjunct->stack_a->stack[conjunct->stack_a->top] > conjunct->stack_a->stack[conjunct->stack_a->top - 1]))
						operations("sa\n", conjunct, stack);
					if((conjunct->numb_higher != conjunct->stack_b->stack[conjunct->stack_b->top]))
						operations("rr\n", conjunct, stack);
					else
						operations("ra\n", conjunct, stack);
					i--;
				}
			}
			else
			{

				i = next_up + 1;
				while (i > 0)
				{
					conjunct->numb_higher = get_higher(conjunct->stack_b);
					if((conjunct->numb_higher != conjunct->stack_b->stack[conjunct->stack_b->top]))
						operations("rrr\n", conjunct, stack);
					else
						operations("rra\n", conjunct, stack);
					i--;
				}
			}
			operations("pb\n", conjunct, stack);
			if ((conjunct->stack_b->top > 1) && (conjunct->stack_a->top > 1) && (conjunct->stack_b->stack[conjunct->stack_b->top] < conjunct->stack_b->stack[conjunct->stack_b->top - 1]) && (conjunct->stack_a->stack[conjunct->stack_a->top] > conjunct->stack_a->stack[conjunct->stack_a->top - 1]))
			{
				operations("ss\n", conjunct, stack);
			}
			else if((conjunct->stack_b->top > 1) && (conjunct->stack_b->stack[conjunct->stack_b->top] < conjunct->stack_b->stack[conjunct->stack_b->top - 1]))
			{
				operations("sb\n", conjunct, stack);
			}
		}
		else
		{
			if(middle - next_down <= 0)
			{
				i = conjunct->stack_a->top - next_down;
				while (i > 0)
				{
					conjunct->numb_higher = get_higher(conjunct->stack_b);
					if((conjunct->numb_higher != conjunct->stack_b->stack[conjunct->stack_b->top]))
						operations("rr\n", conjunct, stack);
					else
						operations("ra\n", conjunct, stack);
					i--;
				}
			}
			else
			{
				i = next_down + 1;
				while (i > 0)
				{
					conjunct->numb_higher = get_higher(conjunct->stack_b);
					if((conjunct->numb_higher != conjunct->stack_b->stack[conjunct->stack_b->top]))
						operations("rrr\n", conjunct, stack);
					else
						operations("rra\n", conjunct, stack);
					i--;
				}
			}
			operations("pb\n", conjunct, stack);
			if ((conjunct->stack_b->top > 1) && (conjunct->stack_a->top > 1) && (conjunct->stack_b->stack[conjunct->stack_b->top] < conjunct->stack_b->stack[conjunct->stack_b->top - 1]) && (conjunct->stack_a->stack[conjunct->stack_a->top] > conjunct->stack_a->stack[conjunct->stack_a->top - 1]))
			{
				operations("ss\n", conjunct, stack);
			}
			else if((conjunct->stack_b->top > 1) && (conjunct->stack_b->stack[conjunct->stack_b->top] < conjunct->stack_b->stack[conjunct->stack_b->top - 1]))
			{
				operations("sb\n", conjunct, stack);
			}
		}
		if (conjunct->stack_a->top == -1)
			loop = -1;
		loop--;
	}
}