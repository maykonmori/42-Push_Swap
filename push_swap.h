/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:06:27 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/19 18:17:38 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
// # include "libft.h"

typedef struct s_stack
{
	// int				content;
	// int				index;
	// struct s_dlist	*next;
	// struct s_dlist	*previous;
	int num;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

typedef struct s_ps
{
	t_stack *a;
	t_stack *b;
} t_ps;

// void error_arg(void);

#endif