/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:36:53 by guisanto          #+#    #+#             */
/*   Updated: 2025/02/17 14:36:11 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate A
void	ra(t_node **stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

// rotate B
void	rb(t_node **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

// rotate A e B ao mesmo tempo
void	rr(t_node **stack_a, t_node **stack_b)
{
	if ((ft_stack_size(*stack_a) < 2) || (ft_stack_size(*stack_b) < 2))
		return ;
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}

// reverve_rotate A
void	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

// reverse_rotate B
void	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}
