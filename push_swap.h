/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:37:07 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/31 13:05:23 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>
#include <limits.h>

typedef struct s_node
{
	int				number;
	int				index;
	struct s_node	*next;
}					t_node;

t_node				*create_node(int number);
t_node				*last_node(t_node *top);

int					min(t_node **stack, int number);
int					get_max_bits(t_node *stack);
int					get_max_index(t_node *stack);
int					stack_is_sorted(t_node **stack);
int					ft_stack_size(t_node *top);
int					check_repeat(int num, char **argv, int i);
int					check_num(char *num);
long long			ft_long_atoi(const char *str);
void				free_stack(t_node **stack);
void				ft_free(char **str);
void				error_msg(char *str);
void				check_argc(int argc, char **argv);
void				index_stack(t_node **stack);
void				init_stack(t_node **stack, int argc, char **argv);
void				sort_stack(t_node **stack_a, t_node **stack_b);
void				validade_args(char **argv, int i, char **split_argv);
void				add_node_front(t_node **stack, t_node *new_node);
void				add_node_back(t_node **stack, t_node *new_node);
void				sort_three(t_node **stack_a);
void				sort_four(t_node **stack_a, t_node **stack_b);
void				sort_five(t_node **stack_a, t_node **stack_b);
void				simple_sort(t_node **stack_a, t_node **stack_b);
void				radix_sort(t_node **stack_a, t_node **stack_b);
void				swap(t_node **stack_a);
void				sa(t_node **stack_a);
void				sb(t_node **stack_b);
void				ss(t_node **stack_a, t_node **stack_b);
void				push(t_node **stack_src, t_node **stack_dst);
void				pa(t_node **stack_a, t_node **stack_b);
void				pb(t_node **stack_a, t_node **stack_b);
void				rotate(t_node **stack);
void				ra(t_node **stack_a);
void				rb(t_node **stack_b);
void				rr(t_node **stack_a, t_node **stack_b);
void				reverse_rotate(t_node **stack);
void				rra(t_node **stack_a);
void				rrb(t_node **stack_b);
void				rrr(t_node **stack_a, t_node **stack_b);

#endif
