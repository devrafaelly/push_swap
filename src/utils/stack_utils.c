/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:52:51 by rafaoliv          #+#    #+#             */
/*   Updated: 2025/10/22 16:32:37 by rafaoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->cost_ra = 0;
    node->cost_rra = 0;
    node->cost_rb = 0;
    node->cost_rrb = 0;
	node->target_pos = 0;
	node->total_cost = 0;
	node->next = NULL;
	return (node);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

int	stack_size(t_stack *stack)
{
	t_stack	*temp;
	int		n;

	temp = stack;
	n = 0;
	while (temp != NULL)
	{
		n++;
		temp = temp->next;
	}
	return (n);
}
