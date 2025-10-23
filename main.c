/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:05:23 by marvin            #+#    #+#             */
/*   Updated: 2025/10/21 19:05:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**numbers;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = init_stack(ac, av);
	if (!stack_a)
		return (1);
	// ordenaçao
	return (0);
}
