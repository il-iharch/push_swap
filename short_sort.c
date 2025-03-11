/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:09:50 by iharch            #+#    #+#             */
/*   Updated: 2025/03/04 11:18:36 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int	min_pos(t_node *stack)
{
	int	i;

	i = stack->content;
	while (stack)
	{
		if (i > stack->content)
			i = stack->content;
		stack = stack->next;
	}
	return (i);
}

int	max_pos(t_node *stack)
{
	int	i;

	i = 0;
	i = stack->content;
	while (stack)
	{
		if (i < stack->content)
			i = stack->content;
		stack = stack->next;
	}
	return (i);
}

void	sort_2_3(t_node **stack_a)
{
	int	min;
	int	max;

	min = min_pos(*stack_a);
	max = max_pos(*stack_a);
	if (ft_lstsize(*stack_a) == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
		return ;
	}
	if ((*stack_a)->content == max)
		ra(stack_a);
	if ((*stack_a)->next->content == min)
		sa(stack_a);
	if (ft_lstlast(*stack_a)->content == min)
		rra(stack_a);
}

void	sort_4(t_node **stack_a, t_node **stack_b)
{
	int	min;
	int	i;
	int	b;

	i = 0;
	b = ft_lstsize(*stack_a);
	min = min_pos(*stack_a);
	while (b >= 0)
	{
		if ((*stack_a)->content == min)
		{
			pb(stack_a, stack_b);
			break ;
		}
		else
			ra(stack_a);
		b--;
	}
	sort_2_3(stack_a);
	pa(stack_b, stack_a);
}

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int	min;

	while (ft_lstsize(*stack_a) > 3)
	{
		min = min_pos(*stack_a);
		if ((*stack_a)->content == min)
			pb(stack_a, stack_b);
		else if (find_pos(*stack_a, min) <= ft_lstsize(*stack_a) / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	sort_2_3(stack_a);
	while (*stack_b)
		pa(stack_b, stack_a);
}
