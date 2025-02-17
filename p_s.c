/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:36:49 by guisanto          #+#    #+#             */
/*   Updated: 2025/02/17 14:35:55 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap A
void	sa(t_node **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

// swap B
void	sb(t_node **stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

// swap ao mesmo tempo no A e B
void	ss(t_node **stack_a, t_node **stack_b)
{
	if (ft_stack_size(*stack_a) < 2 || ft_stack_size(*stack_b))
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}

// push no A
void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pa", 1);
}

// push no B
void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}
