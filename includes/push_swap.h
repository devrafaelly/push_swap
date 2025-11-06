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
	int cost_ra;
    int cost_rra;
    int cost_rb;
    int cost_rrb;
	int target_pos;
	int	total_cost;
	t_move_type	move_type;
	struct s_stack	*next;
}	t_stack;

// Parsing
t_stack	*init_stack(int ac, char **av);
char	**parse_args(int ac, char **av);
int		is_valid_number(char **numbers);
int		check_duplicates(char **numbers);

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

// Algorithm
void	algorithm(t_stack **stack_a, t_stack **stack_b);
void    split_stack(t_stack **stack_a, t_stack **stack_b);
void	sort_small(t_stack **stack_a, t_stack **stack_b);
void	movement_cost(t_stack *stack_a, t_stack *stack_b);
void    movement_logic(t_stack **stack_a, t_stack **stack_b);
void	move_rr(t_stack **a, t_stack **b, t_stack *c);
void    move_rrr(t_stack **a, t_stack **b, t_stack *c);
void    move_ra_rrb(t_stack **a, t_stack **b, t_stack *c);
void    move_rra_rb(t_stack **a, t_stack **b, t_stack *c);

// Utils
t_stack	*new_stack_node(int value, int index);
void	stack_add_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack **stack);
void    assign_index(t_stack *stack);
int 	is_sorted(t_stack *stack);
int 	find_min(t_stack *stack);
void    bring_to_top(t_stack **stack);
long	ft_atol(const char *nptr);
int		min_cost(int a, int b, int c, int d);
int 	max(int a, int b);
t_stack	error(void);
void	free_stack(t_stack **stack);

//! debug
void    print_stack(t_stack **stack_a, t_stack **stack_b);

#endif