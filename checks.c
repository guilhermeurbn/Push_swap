/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:36:35 by guisanto          #+#    #+#             */
/*   Updated: 2025/02/10 15:18:00 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//dando free na stack inteira
void    free_stack(t_node **stack)
{
    t_node *tmp;
    t_node *top;

    top = *stack;
    while(top)
    {
        tmp = top;
        top = top->next;
        free(tmp);
    }
    free(stack);
}
//so liberando memoria
void ft_free(char **str)
{
    int i;

    i = 0;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}
//verificando se um numero esta se repetindo
int check_repeat(int num, char **argv, int i)
{
    i++;
    while(argv[i])
    {
        if(ft_atoi(argv[i]) == num)
            return (1);
        i++;
    }
    return (0);
}
//verificando o tamanho do numero
long long	ft_long_atoi(const char *str)
{
	int	i;
	int	sign;
	long long   result;

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
//verificando se e um numero
static int check_num(char *num)
{
    int i;

    i = 0;
    if (num[0] == '-')
        i++;
    while (num[i])
    {
        if (!ft_isdigit(num[i]))
            return (0);
        i++;
    }
    return (1);
}
//verificando os argumentos
void    check_argc(int argc, char **argv)
{
    char    **split_args;

    split_args = NULL;
    if (argc == 2)
    {
        split_args = ft_split(argv[1], ' ');
        if (!split_args || !*split_args)
        {
            ft_free(split_args);
            error_msg("Error");
        }
        argv = split_args;
    }
    validade_args(argv, argc != 2, split_args);
}
void validade_args(char **argv, int i, char **split_argv)
{
    long tmp;

    while(argv[i])
    {
        if (!(check_num(argv[i]) || !*argv[i]))
        {
            if (split_argv)
                ft_free(split_argv);
            error_msg("Error");
        }
        tmp =  ft_long_atoi(argv[i]);
        if (tmp < -2147483648 || tmp > 2147483647 || check_repeat(tmp, argv, i))
        {
            if (split_argv)
                ft_free(split_argv);
            error_msg("Error");
        }
        i++;
    }
    if (split_argv)
        ft_free(split_argv);
}
