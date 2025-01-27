/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:36:35 by guisanto          #+#    #+#             */
/*   Updated: 2025/01/27 15:29:44 by guisanto         ###   ########.fr       */
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
    int i;
    long tmp;

    i = 0;
    if (argc == 2)
    {
        argv = ft_split(argv[1], ' ');
        if (!*argv)
            return ;
    }
    else
        i = 1;
    while (argv[i])
    {
        tmp = ft_atoi(argv[i]);
        if (!check_num(argv[i]) || check_repeat(tmp, argv, i) || !*argv[i])
            error_msg("Error");
        tmp = ft_long_atoi(argv[i]);
        if (tmp < -2147483648 || tmp > 2147483647)
            error_msg("Error");
        i++;
    }
    if (argc == 2)
        ft_free(argv);
}
