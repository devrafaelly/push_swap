/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:48:08 by codespace         #+#    #+#             */
/*   Updated: 2025/10/28 00:48:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_small(t_stack **stack_a, t_stack **stack_b)
{
    int stack_len;

    stack_len = stack_size(*stack_a);
    if (stack_len == 2)
		sort_two(stack_a);
    else if (stack_len == 3)
		sort_three(stack_a);
    else if (stack_len == 4)
		sort_four(stack_a, stack_b);
    else if (stack_len == 5)
		sort_five(stack_a, stack_b);
}

static void    sort_two(t_stack **stack_a)
{
    if (stack_a && *stack_a && (*stack_a)->next)
    {
        if ((*stack_a)->value > (*stack_a)->next->value)
            sa(stack_a);
    }
}

static void    sort_three(t_stack **stack)
{
    t_stack *temp;
    
    if (stack && *stack && (*stack)->next)
    {
        while (!order(stack))
        {
            if ((*stack)->value == max_value(stack))
                ra(stack);
            else if ((*stack)->next->value == max_value(stack))
                rra(stack);
            else
                sa(stack);
        }
    }
    
}

static void    sort_four(t_stack **stack_a, t_stack **stack_b)
{
    if (stack_a && *stack_a && (*stack_a)->next)
    {
        bring_to_top(stack_a, min_value(stack_a));
        pb(stack_a, stack_b);
        sort_three(stack_a);
        pa(stack_a, stack_b);
    }
}

static void    sort_five(t_stack **stack_a, t_stack **stack_b)
{
    if (stack_a && *stack_a && (*stack_a)->next)
    {
        bring_to_top(stack_a, min_value(stack_a));
        pb(stack_a, stack_b);
        bring_to_top(stack_a, min_value(stack_a));
        pb(stack_a, stack_b);
        sort_three(stack_a);
        pa(stack_a, stack_b);
        pa(stack_a, stack_b);
    }
}

// debug - NAO ESQUECER DE APAGAR!!!!!!!!!!!!!!!!!!!
void    print_stack(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp;

    temp = *stack_a;
    ft_printf("Stack A:\n");
    while(temp)
    {
        ft_printf("%d\n", temp->value);
        temp = temp->next;
    }
    temp = *stack_b;
    ft_printf("Stack B:\n");
    while(temp)
    {
        ft_printf("%d\n", temp->value);
        temp = temp->next;
    }
}
