/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:36:40 by guisanto          #+#    #+#             */
/*   Updated: 2025/02/17 14:35:50 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// vai trocar os 2 primeiros
void	swap(t_node **stack_a)
{
	t_node	*tmp;

	if (ft_stack_size(*stack_a) < 2)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = tmp->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
}

// vai mover o primeiro da Stack para a outra Stack
void	push(t_node **stack_src, t_node **stack_dst)
{
	t_node	*tmp;

	if (ft_stack_size(*stack_src) == 0)
		return ;
	tmp = *stack_src;
	*stack_src = (*stack_src)->next;
	add_node_front(stack_dst, tmp);
}

// vai rotacionar o 1 com o ultimo numero
void	rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*last;

	if (ft_stack_size(*stack) < 2)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = tmp;
}

// vai desrotacionar o 1 com o ultimo
void	reverse_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*second_last;

	if (ft_stack_size(*stack) < 2)
		return ;
	last = last_node(*stack);
	second_last = *stack;
	while (second_last->next->next)
		second_last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
