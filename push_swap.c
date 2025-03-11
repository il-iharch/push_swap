/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:08:16 by iharch            #+#    #+#             */
/*   Updated: 2025/03/11 14:53:18 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int	range;
	int	size;

	size = ft_lstsize(*stack_a);
	if (size <= 100)
		range = 16;
	else
		range = 42;
	push_to_b(stack_a, stack_b, range);
	push_to_a(stack_a, stack_b);
}

void	clear_stack(t_node **stack)
{
	t_node	*node;

	while (*stack)
	{
		node = *stack;
		(*stack) = (*stack)->next;
		free(node);
	}
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;

	if (ac >= 2)
	{
		stack_a = NULL;
		stack_b = NULL;
		parsing(av);
		stack_a = (ft_stack(&stack_a, av));
		size = ft_lstsize(stack_a);
		index_stack(stack_a);
		if (is_sorted(stack_a) == 1)
			return (0);
		if (size == 2 || size == 3 || size == 4 || size == 5)
		{
			quick_sort(stack_a, stack_b);
		}
		else
			sort_stack(&stack_a, &stack_b);
		clear_stack(&stack_a);
	}
}
