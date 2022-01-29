#include "push_swap.h"

static void	double_operation(char *op, t_data *conjunct)
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
			free_all(conjunct, EXIT_FAILURE);
	}
}

void	 operations(char *op, t_data *conjunct)
{
	printf("antes de entrar do if %s\n", op);
	if (!ft_strncmp(op, "sa\n", 3))
	{
		printf("strncmp %d\n", !ft_strncmp(op, "sa\n", 3));
		printf("entrou no SWAP %s\n", op);
		swap(conjunct->stack_a);
		printf("%d\n", conjunct->stack_a->stack[2]);
		printf("%d\n", conjunct->stack_a->stack[1]);
		printf("%d\n", conjunct->stack_a->stack[0]);
		// write(2, op, ft_strlen(op));
	}
	else if (!ft_strncmp(op, "sb\n", 3))
		swap(conjunct->stack_b);
	else if (!ft_strncmp(op, "pa\n", 3))
		push(conjunct->stack_b, conjunct->stack_a);
	else if (!ft_strncmp(op, "pb\n", 3))
		push(conjunct->stack_a, conjunct->stack_b);
	else if (!ft_strncmp(op, "ra\n", 3))
	{
		printf("ROTATE");
		rotate(conjunct->stack_a);
	}
	else if (!ft_strncmp(op, "rb\n", 3))
		rotate(conjunct->stack_b);
	else if (!ft_strncmp(op, "rra\n", 4))
		rrotate(conjunct->stack_a);
	else if (!ft_strncmp(op, "rrb\n", 4))
		rrotate(conjunct->stack_b);
	else
		double_operation(op, conjunct);
	printf("saiu do if %s\n", op);
	conjunct->res_step = ft_strjoin(conjunct->res_step, op);
	printf("saiu do if %s\n", conjunct->res_step);
	// ft_putstr_fd(conjunct->res_step, 1);
	conjunct->steps++;
}