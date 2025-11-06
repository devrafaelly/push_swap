/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:53:54 by codespace         #+#    #+#             */
/*   Updated: 2025/11/05 22:11:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    split_stack(t_stack **stack_a, t_stack **stack_b)
{
    int stack_len;
    int min_index;
    int count;

    if (!stack_a || !*stack_a)
        return ;
    stack_len = stack_size(*stack_a);
    min_index = stack_len - 3;
    count = 0;
    while (count < stack_len)
    {
        if ((*stack_a)->index < min_index)
            pb(stack_a, stack_b);
        else
            ra(stack_a);
        count++;
    }
    sort_three(stack_a);
}
