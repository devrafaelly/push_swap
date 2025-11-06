/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 23:19:51 by codespace         #+#    #+#             */
/*   Updated: 2025/11/06 01:39:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    move_rr(t_stack **a, t_stack **b, t_stack *c)
{
    int min_cost;
    int count;

    min_cost = min(c->cost_ra, c->cost_rb);
    count = 0;
    while (count++ < min_cost)
            rr(a, b);
    if (c->cost_ra < c->cost_rb)
    {
        while (count++ < c->cost_rb)
            rb(b);
    }
    else if (c->cost_ra > c->cost_rb)
    {
        while (count++ < c->cost_ra)
            ra(a);
    }
}

void    move_rrr(t_stack **a, t_stack **b, t_stack *c)
{
    int min_cost;
    int count;

    min_cost = min(c->cost_rra, c->cost_rrb);
    count = 0;
    while (count++ < min_cost)
            rrr(a, b);
    if (c->cost_rra < c->cost_rrb)
    {
        while (count++ < c->cost_rrb)
            rrb(b);
    }
    else if (c->cost_rra > c->cost_rrb)
    {
        while (count++ < c->cost_rra)
            rra(a);
    }
}

void    move_ra_rrb(t_stack **a, t_stack **b, t_stack *c)
{
    int count;

    count = 0;
    while (count++ < c->cost_ra)
        ra(a);
    count = 0;
    while (count++ < c->cost_rrb)
        rrb(b);
}

void    move_rra_rb(t_stack **a, t_stack **b, t_stack *c)
{
    int count;

    count = 0;
    while (count++ < c->cost_rra)
        rra(a);
    count = 0;
    while (count++ < c->cost_rb)
        rb(b);
}
