/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 22:41:30 by codespace         #+#    #+#             */
/*   Updated: 2025/10/28 00:42:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int order(t_stack **stack)
{
    t_stack *temp;

    temp = *stack;
    while (temp->next)
    {
        if (temp->value > temp->next->value)
            return (0);
        temp = temp->next;
    }
    return (1);
}

int max_value(t_stack **stack)
{
    t_stack *temp;
    int n;

    temp = *stack;
    n = temp->value;
    while (temp->next)
    {
        if (temp->next->value > n)
            n = temp->next->value;
        temp = temp->next;
    }
    return (n);
}

int min_value(t_stack **stack)
{
    t_stack *temp;
    int n;

    temp = *stack;
    n = temp->value;
    while (temp->next)
    {
        if (temp->next->value < n)
            n = temp->next->value;
        temp = temp->next;
    }
    return (n);
}

void    bring_to_top(t_stack **stack, int value)
{
    t_stack *temp;
    int stack_len;
    int count;

    stack_len = stack_size(*stack);
    temp = *stack;
    count = 0;
    while(temp->value != value)
    {
        temp = temp->next;
        count++;
    }
    if (count > (stack_len / 2))
    {
        while ((*stack)->value != value)
            rra(stack);
    }
    else
    {
        while ((*stack)->value != value)
            ra(stack);
    }
}
