/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 23:29:08 by codespace         #+#    #+#             */
/*   Updated: 2025/11/05 23:29:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_args(int ac, char **av)
{
	char	**numbers;

	if (ac == 2)
		numbers = ft_split(av[1], ' ');
	else
		numbers = av + 1;
	return (numbers);
}
