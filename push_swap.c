/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:21:09 by guisanto          #+#    #+#             */
/*   Updated: 2025/01/20 13:36:51 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// corpo do sistema
void push_swap(int *stack, int n)
{
    int max;
    int exp;
    
    max = 0;
    exp = 1;
    max = ft_max(stack, n);
    
    while(max / exp > 0)
    {
        count_sort(stack, n, exp);
        exp *= 10;
    }
    if (check_duplicates(stack, n) == 0)
    {
        printf("error!\nNúmeros duplicados!\n");
        return(free(stack));
    }
    print_stack(stack, n);
}

//cerebro central
int main(int ac, char **av)
{
    int     *stack;
    char    **str;
    int     n = ac - 1;
    int     i = 0;
    
    if (ac < 2)
    {
        printf("error1!\n");
        return (1);
    }
    if (ac == 2 && av[1][0])
    {
        stack = malloc(ft_strlen((av[1]) + 1) * sizeof(int));
        str = ft_split(av[1], 32);
        
        if (!stack)
            return (free(stack), 1);
        if (!str)
            return (free(str), 1);
        
        while(str[i])
        {
            stack[i] = ft_atoi(str[i]);
            i++;
        }
        free(str);
        push_swap(stack, i);
        return (0);
    }
    else
    {
        stack = malloc((n + 1) * sizeof(int));
        if (!stack)
            return (free(stack), 1);
        while(i < n)
        {
            stack[i] = ft_atoi(av[i + 1]);
            i++;
        }
        push_swap(stack, n);
    }
    return (0);
}
