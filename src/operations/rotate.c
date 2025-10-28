/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:48:00 by codespace         #+#    #+#             */
/*   Updated: 2025/10/27 20:49:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int rotate(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if (stack && *stack && (*stack)->next)
    {
        first = *stack;
        last = *stack;
        *stack = (*stack)->next;
        while (last->next)
            last = last->next;
        last->next = first;
        first->next = NULL;
        return (1);
    }
    return (0);
}

void    ra(t_stack **stack_a)
{
    if (rotate(stack_a))
        ft_putstr_fd("ra\n", 1);
}

void    rb(t_stack **stack_b)
{
    if (rotate(stack_b))
        ft_putstr_fd("rb\n", 1);
}

void    rr(t_stack **stack_a, t_stack **stack_b)
{
    if (rotate(stack_a) || rotate(stack_b))
        ft_putstr_fd("rr\n", 1);
}
