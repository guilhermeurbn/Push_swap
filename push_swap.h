/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:02:18 by guisanto          #+#    #+#             */
/*   Updated: 2025/01/15 18:36:50 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#  define PUSH_SWAP_H

#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

void    count_sort(int *stack, int n, int exp);
void    print_stack(int *stack, int n);
void    push_swap(int *stack, int n);
int     ft_atoi(const char *str);
int     check_duplicates(int *stack, int n);
int     ft_max(int *stack, int n);


#endif
