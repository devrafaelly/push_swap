/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:48:04 by codespace         #+#    #+#             */
/*   Updated: 2025/10/27 20:49:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int    swap(t_stack **stack)
{
    int temp;

    if (*stack && (*stack)->next)
    {
        temp = (*stack)->value;
        (*stack)->value = (*stack)->next->value;
        (*stack)->next->value = temp;
        return (1);
    }
    return (0);
}

void    sa(t_stack **stack_a)
{
    if (swap(stack_a))
        ft_putstr_fd("sa\n", 1);
}

void    sb(t_stack **stack_b)
{
    if (swap(stack_b))
        ft_putstr_fd("sb\n", 1);
}

void    ss(t_stack **stack_a, t_stack **stack_b)
{
    if (swap(stack_a) || swap(stack_b))
        ft_putstr_fd("ss\n", 1);
}
