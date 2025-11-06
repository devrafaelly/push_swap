/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_logic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:40:40 by codespace         #+#    #+#             */
/*   Updated: 2025/11/06 01:53:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack    *find_cheapest(t_stack *stack_b)
{
    t_stack *cheapest_node;
    
    if (!stack_b)
        return (NULL);
    cheapest_node = stack_b;
    while (stack_b)
    {
        if (stack_b->total_cost < cheapest_node->total_cost)
            cheapest_node = stack_b;
        stack_b = stack_b->next;
    }
    return (cheapest_node);
}

void    movement_logic(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *cheapest;
    int rr_case;
    int rrr_case;
    int ra_rrb_case;
    int rra_rb_case;

    cheapest = find_cheapest(*stack_b);
    if (!cheapest)
        return;
    rr_case = max(cheapest->cost_ra, cheapest->cost_rb);
    rrr_case = max(cheapest->cost_rra, cheapest->cost_rrb);
    ra_rrb_case = cheapest->cost_ra + cheapest->cost_rrb;
    rra_rb_case = cheapest->cost_rra + cheapest->cost_rb;
    if (cheapest->total_cost == rr_case)
        move_rr(stack_a, stack_b, cheapest);
    else if (cheapest->total_cost == rrr_case)
        move_rrr(stack_a, stack_b, cheapest);
    else if (cheapest->total_cost == ra_rrb_case)
        move_ra_rrb(stack_a, stack_b, cheapest);
    else if (cheapest->total_cost == rra_rb_case)
        move_rra_rb(stack_a, stack_b, cheapest);
    pa(stack_a, stack_b);
}
