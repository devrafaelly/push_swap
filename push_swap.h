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
# define INT_MAX 2147483647

typedef	struct s_stack
{
	int	value;
	int	index;
	struct s_stack	*next;
}	t_stack;

// stack
t_stack	*init_stack(int ac, char **av);
int	overflow_atoi(const char *nptr, int *error);
char	**parse_args(int ac, char **av);
int	is_valid_number(char **numbers);
int	check_duplicates(char **numbers);
t_stack	*new_node(int value, int index);
void	stack_add_back(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst);

// Error
t_stack	error(void);

#endif