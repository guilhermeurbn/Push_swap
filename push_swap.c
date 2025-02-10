/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:36:31 by guisanto          #+#    #+#             */
/*   Updated: 2025/02/10 14:32:12 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//algoritmo para organizar a Stack conforme com os bites
void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = ft_stack_size(*stack_a);
	max_bits = get_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (*stack_b)
			pa(stack_b, stack_a);
		i++;
	}
}
//organizando conforme o tamanho da stack
void	simple_sort(t_node **stack_a, t_node **stack_b)
{
    int size;
    if (!stack_a || !*stack_a)
	{
		error_msg("Error");
		return ;
	}
    if (stack_is_sorted(stack_a) || ft_stack_size(*stack_a) == 1 || ft_stack_size(*stack_a) == 0)
        return ;
    size = ft_stack_size(*stack_a);
    if (size == 2)
        sa(stack_a);
    else if (size == 3)
        sort_three(stack_a);
    else if (size == 4)
        sort_four(stack_a, stack_b);
    else if (size == 5)
        sort_five(stack_a, stack_b);
}
//pegando o 2 menor
static t_node	*get_next_min(t_node **stack)
{
    t_node *top;
    t_node *min;
    int tmp_min;
    
    min = NULL;
    tmp_min = 0;
    top = *stack;
    if (top)
    {
        while(top)
        {
            if ((top -> index == -1) && (!tmp_min || top->number < min->number))
            {
                min = top;
                tmp_min = 1;
            }
            top = top ->next;
        }
    }
    return (min);
}
//organizando os index de cada numero
void	index_stack(t_node **stack)
{
    t_node *top;
    int     index;

    index = 0;
    top = get_next_min(stack);
    while (top)
    {
        top -> index = index++;
        top = get_next_min(stack);
    }
}
