/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:30:25 by guisanto          #+#    #+#             */
/*   Updated: 2025/02/10 17:16:47 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node  **stack_a;
    t_node  **stack_b;
    
    if (argc == 1)
        return (0);
    check_argc(argc, argv);
    stack_a = (t_node **)malloc(sizeof(t_node *));
    stack_b = (t_node **)malloc(sizeof(t_node *));
    *stack_a = NULL;
    *stack_b = NULL;
    init_stack(stack_a, argc, argv);
    if (stack_is_sorted(stack_a))
    {
        free_stack(stack_a);
        free_stack(stack_b);
        return (0);
    }
    sort_stack(stack_a, stack_b);
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}
//ordenando as stacks em ordem crescente
void sort_stack(t_node **stack_a, t_node **stack_b)
{
    if (ft_stack_size(*stack_a) <= 5)
        simple_sort(stack_a, stack_b);
    else
        radix_sort(stack_a, stack_b);
}
//mensagem de error!
void    error_msg(char *str)
{
    ft_putendl_fd(str, 2);
    exit(0);
}
