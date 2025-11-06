/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_cost.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:28:36 by codespace         #+#    #+#             */
/*   Updated: 2025/11/05 22:26:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    total_cost(t_stack *stack_b)
{
    int rr_case;
    int rrr_case;
    int ra_rrb_case;
    int rra_rb_case;
    
    while (stack_b)
    {
        rr_case = max(stack_b->cost_ra, stack_b->cost_rb);
        rrr_case = max(stack_b->cost_rra, stack_b->cost_rrb);
        ra_rrb_case = stack_b->cost_ra + stack_b->cost_rrb;
        rra_rb_case = stack_b->cost_rra + stack_b->cost_rb;
        stack_b->total_cost = min_cost(rr_case, rrr_case, ra_rrb_case, rra_rb_case);
        stack_b = stack_b->next;
    }
}

static void    rotation_cost_b(t_stack *stack_b, int stack_len)
{
    int pos;
    
    pos = 0;
    while (stack_b)
    {
        stack_b->cost_rb = pos;
        stack_b->cost_rrb = stack_len - pos;
        stack_b = stack_b->next;
        pos++;
    }
}

static int    rotation_cost_a(t_stack *stack_a, int target_index)
{
    int pos;

    pos = 0;
    while (stack_a && stack_a->index != target_index)
    {
        pos++;
        stack_a = stack_a->next;
    }
    return (pos);
}
static void    target_pos(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *head;
    int target_index;
    int stack_len;
    int a_pos;

    head = stack_a;
    stack_len = stack_size(stack_a);
    while (stack_b)
    {
        stack_a = head;
        target_index = stack_a->index;
        while(stack_a)
        {
            if (stack_a->index > stack_b->index && stack_a->index < target_index)
                    target_index = stack_a->index;
            stack_a = stack_a->next;
        }
        a_pos = rotation_cost_a(head, target_index);      
        stack_b->target_pos = target_index;
        stack_b->cost_ra = a_pos;
        stack_b->cost_rra = stack_len - a_pos;
        stack_b = stack_b->next;
    }
}

void    movement_cost(t_stack *stack_a, t_stack *stack_b)
{
        target_pos(stack_a, stack_b);
        rotation_cost_b(stack_b, stack_size(stack_b));
        total_cost(stack_b);
}
