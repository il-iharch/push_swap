/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:44:59 by iharch            #+#    #+#             */
/*   Updated: 2025/02/23 11:51:45 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (!*stack_a)
		return ;
	tmp1 = *stack_a;
	tmp2 = (*stack_a)->next;
	(*stack_a)->next = NULL;
	ft_lstadd_front(stack_b, tmp1);
	*stack_a = tmp2;
}

void	pa(t_node **stack_b, t_node **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
