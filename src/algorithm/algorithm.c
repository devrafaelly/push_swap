/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:29:17 by codespace         #+#    #+#             */
/*   Updated: 2025/11/06 01:59:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    algorithm(t_stack **stack_a, t_stack **stack_b)
{
    split_stack(stack_a, stack_b);
    while (*stack_b)
    {
        movement_cost(*stack_a, *stack_b);
        execute_move(stack_a, stack_b);
    }
    bring_to_top(stack_a);
}
