/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:36:55 by guisanto          #+#    #+#             */
/*   Updated: 2025/04/09 13:59:12 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// busco  menor indice na stack
int	min(t_node **stack, int number)
{
	t_node	*top;
	int		min_index;

	top = *stack;
	min_index = top->index;
	while (top->next)
	{
		top = top->next;
		if ((top->index < min_index) && top->index != number)
			min_index = top->index;
	}
	return (min_index);
}

// vai organizar com apenas 3 numeros
void	sort_three(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->number;
	b = (*stack_a)->next->number;
	c = (*stack_a)->next->next->number;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c)
		rra(stack_a);
}

// vai organizar com 4 numeros
void	sort_four(t_node **stack_a, t_node **stack_b)
{
	int	min_index;

	min_index = min(stack_a, -1);
	while ((*stack_a)->index != min_index)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

// vai organizar com 5 numeros
void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	min_index;

	min_index = min(stack_a, -1);
	if ((*stack_a)->next->index == min_index)
		sa(stack_a);
	else if ((*stack_a)->next->next->index == min_index)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->next->next->next->index == min_index)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->next->next->next->next->index == min_index)
		rra(stack_a);
	if ((*stack_a)->index == min_index)
		pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

// vai desratocionar a Stack A e B ao mesmo tempo
void	rrr(t_node **stack_a, t_node **stack_b)
{
	if (ft_stack_size(*stack_a) < 2 || ft_stack_size(*stack_b) < 2)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
