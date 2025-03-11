/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:50:43 by iharch            #+#    #+#             */
/*   Updated: 2025/03/04 12:42:17 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct t_node
{
	int				content;
	int				index;
	int				pos;
	int				cost;
	struct t_node	*next;
}	t_node;

void	ft_lstadd_back(t_node **head, t_node *new);
void	ft_lstadd_front(t_node **head, t_node *new);
int		ft_lstsize(t_node *node);
t_node	*ft_lstlast(t_node *lst);
t_node	*lst_new(int content);
void	parsing(char **str);
int		ft_cheak(char *str);
int		*to_tab(char **str);
int		ft_size(char **str);
int		ft_count(char *s);
char	**ft_split(char *s);
int		is_repeat(char **str);
void	index_stack(t_node *stack_a);
int		min_pos(t_node *stack);
int		max_pos(t_node *stack);
void	set_position(t_node *stack);
int		index_position(t_node **stack, int add);
t_node	*ft_stack(t_node **stack_a, char **str);
int		find_pos(t_node *stack, int value);
void	ft_free(char **str);
void	swap(t_node **stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	push(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_b, t_node **stack_a);
void	pb(t_node **stack_a, t_node **stack_b);
void	rotate(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	reverse_rotate(t_node **stack_a);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	sort_2_3(t_node **stack_a);
void	sort_4(t_node **stack_a, t_node **stack_b);
void	sort_5(t_node **stack_a, t_node **stack_b);
t_node	*quick_sort(t_node *stack_a, t_node *stack_b);
void	push_to_b(t_node **stack_a, t_node **stack_b, int range);
void	push_to_a(t_node **stack_a, t_node **stack_b);
void	sort_stack(t_node **stack_a, t_node **stack_b);
int		is_sorted(t_node *stack_a);

#endif
