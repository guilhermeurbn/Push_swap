/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:36:37 by guisanto          #+#    #+#             */
/*   Updated: 2025/01/27 14:44:37 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//criando um nó e ja inicializando eles
t_node	*create_node(int number)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node -> number = number;
    new_node -> next = NULL;
    new_node ->index = -1;
    return (new_node);
}
//buscando o ultimo nó
t_node *last_node(t_node *top)
{
    if (!top)
        return (NULL);
    while (top -> next)
        top = top -> next;
    return (top);
}
//adicionano um nó na frente
void	add_node_front(t_node **stack, t_node *new_node)
{
    if (!new_node)
        return ;
    new_node->next = *stack;
    *stack = new_node;
}
//adicionando um nó atras
void add_node_back(t_node **stack, t_node *new_node)
{
    t_node *tmp;
    
    if (!new_node)
        return ;
    if(*stack)
    {
        tmp = last_node(*stack);
        tmp->next = new_node;
    }
    else
        *stack = new_node;
}