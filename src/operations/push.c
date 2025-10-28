/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:47:52 by codespace         #+#    #+#             */
/*   Updated: 2025/10/27 20:49:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int push(t_stack **src, t_stack **dest)
{
    t_stack *temp;

    if (src && *src)
    {
        temp = *src;
        *src = (*src)->next;
        temp->next = *dest;
        *dest = temp;
        return (1);
    }
    return (0);
}

void    pa(t_stack **stack_a, t_stack **stack_b)
{
    if (push(stack_b, stack_a))
        ft_putstr_fd("pa\n", 1);
}

void    pb(t_stack **stack_a, t_stack **stack_b)
{
    if (push(stack_a, stack_b))
        ft_putstr_fd("pb\n", 1);
}
