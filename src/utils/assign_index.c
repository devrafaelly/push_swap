/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:53:16 by codespace         #+#    #+#             */
/*   Updated: 2025/11/05 21:53:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    assign_index(t_stack *stack)
{
    t_stack *head;
    t_stack *temp;
    int i;

    if (!stack)
        return ;
    head = stack;
    while (stack)
    {
        temp = head;
        i = 0;
        while (temp)
        {
            if (stack->value > temp->value)
                i++;
            temp = temp->next;
        }
        stack->index = i;
        stack = stack->next;
    }
}
