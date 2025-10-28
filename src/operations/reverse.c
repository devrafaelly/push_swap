/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:47:44 by codespace         #+#    #+#             */
/*   Updated: 2025/10/27 20:49:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int rr(t_stack **stack)
{
    t_stack *prev;
    t_stack *last;

    if (stack && *stack && (*stack)->next)
    {
        prev = *stack;
        last = *stack;
        while (last->next)
            last = last->next;
        while (prev->next != last)
            prev = prev->next;
        last->next = *stack;
        prev->next = NULL;
        *stack = last;
        return (1);
    }
    return (0);
}

void    rra(t_stack **stack_a)
{
    if (rr(stack_a))
        ft_putstr_fd("rra\n", 1);
}

void    rrb(t_stack **stack_b)
{
    if (rr(stack_b))
        ft_putstr_fd("rrb\n", 1);
}

void    rrr(t_stack **stack_a, t_stack **stack_b)
{
    if (rr(stack_a) || rr(stack_b))
        ft_putstr_fd("rrr\n", 1);
}
