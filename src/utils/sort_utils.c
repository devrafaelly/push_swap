/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 22:41:30 by codespace         #+#    #+#             */
/*   Updated: 2025/11/06 01:36:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *stack)
{
    if (!stack)
        return (1);
    while (stack->next)
    {
        if (stack->index > stack->next->index)
            return (0);
        stack = stack->next;
    }
    return (1);
}

int find_min(t_stack *stack)
{
    int min_index;
    
    min_index = stack->index;
    while (stack)
    {
        if (min_index > stack->index)
            min_index = stack->index;
        stack = stack->next;
    }
    return (min_index);
}

void    bring_to_top(t_stack **stack)
{
    t_stack *temp;
    int stack_len;
    int min_index;
    int count;

    stack_len = stack_size(*stack);
    min_index = find_min(*stack);
    temp = *stack;
    count = 0;
    while(temp->index != min_index)
    {
        temp = temp->next;
        count++;
    }
    while ((*stack)->index != min_index)
    {
        if (count > (stack_len / 2))
            rra(stack);
        else
            ra(stack);
    }
}
