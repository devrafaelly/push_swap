/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 23:29:17 by codespace         #+#    #+#             */
/*   Updated: 2025/11/05 23:29:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *error(void)
{
    ft_putstr_fd("Error", 2);
    return (NULL);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

static	char	**memory_cleaner(char **array, unsigned int i)
{
	while (*array)
	{
		free(*array);
		array++;
	}
	free(array);
	return (NULL);
}
