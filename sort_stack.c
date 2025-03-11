/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:11:09 by iharch            #+#    #+#             */
/*   Updated: 2025/03/04 13:40:03 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	set_position(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
}

int	index_position(t_node **stack, int add)
{
	int		i;
	t_node	*head;

	i = 0;
	head = *stack;
	while (i < ft_lstsize(*stack))
	{
		if (head->index < (add))
			break ;
		head = head->next;
		i++;
	}
	return (i);
}

int	find_pos(t_node *stack, int value)
{
	set_position(stack);
	while (stack)
	{
		if (value == stack->content)
			return (stack->pos);
		stack = stack->next;
	}
	return (0);
}

void	push_to_b(t_node **stack_a, t_node **stack_b, int range)
{
	int	i;
	int	size;
	int	add;

	size = ft_lstsize(*stack_a);
	i = 0;
	while (*stack_a && i < size)
	{
		add = i + range;
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if (index_position(stack_a, add) < size / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	push_to_a(t_node **stack_a, t_node **stack_b)
{
	int	max;
	int	pos;

	while (ft_lstsize(*stack_b))
	{
		max = max_pos(*stack_b);
		pos = find_pos(*stack_b, max);
		if ((*stack_b)->content == max)
		{
			pa(stack_b, stack_a);
			if (*stack_b)
			{
				max = max_pos(*stack_b);
				pos = find_pos(*stack_b, max);
			}
		}
		else
		{
			if (pos <= ft_lstsize(*stack_b) / 2)
				rb(stack_b);
			else
				rrb(stack_b);
		}
	}
}
