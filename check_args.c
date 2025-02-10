/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:11:17 by guisanto          #+#    #+#             */
/*   Updated: 2025/02/10 17:24:48 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// verificando os argumentos
void	check_argc(int argc, char **argv)
{
	char	**split_args;

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
// parte 2 do check de argumentos
void	validade_args(char **argv, int i, char **split_argv)
{
	long tmp;

	while (argv[i])
	{
		if (!(check_num(argv[i]) || !*argv[i]))
		{
			if (split_argv)
				ft_free(split_argv);
			error_msg("Error");
		}
		tmp = ft_long_atoi(argv[i]);
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