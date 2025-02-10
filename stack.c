/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:36:57 by guisanto          #+#    #+#             */
/*   Updated: 2025/02/10 17:16:37 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_node *stack)
{
	int	max;
	int	bits;

	max = get_max_index(stack);
	bits = 0;
	while (max >> bits)
		bits++;
	return (bits);
}
// Obtém o maior índice da pilha
int	get_max_index(t_node *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}
//tamanho da stack
int		ft_stack_size(t_node *top)
{
    int i;
    
    i = 0;
    while(top)
    {
        i++;
        top = top->next;
    }
    return (i);
}
//verificando se a stack esta em ordem
int		stack_is_sorted(t_node **stack)
{
    t_node *top;
    
    top = *stack;
    
    while(top->next)
    {
        if (top->number > top->next->number)
            return (0);
        top = top->next;
    }
    return (1);
}
//prencher a stack com os nós
void	init_stack(t_node **stack, int argc, char **argv)
{
    t_node *new;

    int i;
    i = 0;
    if (argc == 2)
        argv = ft_split(argv[1], ' ');
    else
        i = 1;
    while (argv[i])
    {
        new = create_node(ft_atoi(argv[i]));
        add_node_back(stack, new);
        i++;
    }
    index_stack(stack);
    if (argc == 2)
        ft_free(argv);
}
