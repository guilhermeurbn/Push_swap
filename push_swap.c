/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:21:09 by guisanto          #+#    #+#             */
/*   Updated: 2025/01/15 19:19:46 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
//vai transformar os argumentos em interios
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
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
        return ;
    }
    print_stack(stack, n);
}
int main(int ac, char **av)
{
    int *stack;
    int n = ac - 1;
    int i = 0;
    
    if (ac < 2)
    {
        printf("error!\n");
        return (1);
    }
    
    stack = malloc(n * sizeof(int));
    if (!stack)
        return (1);
    while(i < ac - 1)
    {
        stack[i] = ft_atoi(av[i + 1]);
        i++;
    }
    push_swap(stack, n);
    free(stack);
    return (0);
}