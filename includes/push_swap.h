/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:06:11 by marvin            #+#    #+#             */
/*   Updated: 2025/10/21 19:06:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

# define INT_MIN (-2147483647 - 1)
# define INT_MAX (2147483647)

typedef	struct s_stack
{
	int	value;
	int	index;
	struct s_stack	*next;
}	t_stack;

// Init
t_stack	*init_stack(int ac, char **av);

// Parse
char	**parse_args(int ac, char **av);
int		is_valid_number(char **numbers);
int		check_duplicates(char **numbers);

// Stack Utils
t_stack	*new_stack_node(int value, int index);
void	stack_add_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack **stack);
void	stack_clear(t_stack **stack);

// Utils
int		overflow_atoi(const char *nptr, int *error);
t_stack	error(void);

// Operations
void    pa(t_stack **stack_a, t_stack **stack_b);
void    pb(t_stack **stack_a, t_stack **stack_b);

void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b);

void    ra(t_stack **stack_a);
void    rb(t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);

void    rra(t_stack **stack_a);
void    rrb(t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);

// Sort
void    sort_small(t_stack **stack_a, t_stack **stack_b);

// Sort Utils
int 	order(t_stack **stack);
int 	max_value(t_stack **stack);
int 	min_value(t_stack **stack);
void    bring_to_top(t_stack **stack, int value);

//! debug
void    print_stack(t_stack **stack_a, t_stack **stack_b);

#endif