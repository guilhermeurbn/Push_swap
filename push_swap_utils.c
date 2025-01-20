/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:00:50 by guisanto          #+#    #+#             */
/*   Updated: 2025/01/20 13:34:47 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(int *stack, int n);
int ft_max(int *stack, int n);
int check_duplicates(int *stack, int n);


void print_stack(int *stack, int n)
{
    int i = 0;

    while (i < n)
    {
        printf("%d ", stack[i]); // Exibe cada elemento separado por espaço
        i++;
    }
    printf("\n"); // Nova linha ao final
}

//busca o número máximo
int ft_max(int *stack, int n)
{
    int i;
    int max;

    i = 0;
    max = stack[0];
    while(i < n)
    {
        if (stack[i] > max)
            max = stack[i];
        i++;
    }
    return (max);
}

//checa se tem números duplicados
int check_duplicates(int *stack, int n)
{
    int i;
    int j;

    i = 0;
    while(i < n)
    {
        j = i + 1;
        while(j < n)
        {
            if(stack[i] == stack[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
