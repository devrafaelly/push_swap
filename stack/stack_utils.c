/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:52:51 by rafaoliv          #+#    #+#             */
/*   Updated: 2025/10/22 16:32:37 by rafaoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//! swap
// sa (swap a): Troca os 2 primeiros elementos no topo da pilha a.
    // Nao faz nada se houver apenas um elemento ou nenhum.
// sb (swap b): Troca os 2 primeiros elementos no topo da pilha b.
    // Nao faz nada se houver apenas um elemento ou nenhum.
// ss : sa e sb ao mesmo tempo.

//! push
// pa (push a): Pega o primeiro elemento no topo de b e o coloca no topo de a.
    // Nao faz nada se b estiver vazia.
// pb (push b): Pega o primeiro elemento no topo de a e o coloca no topo de b.
    // Nao faz nada se a estiver vazia.

//! rotate
// ra (rotate a): Move todos os elementos da pilha a para cima em 1.
    // O primeiro elemento se torna o ultimo.
// rb (rotate b): Move todos os elementos da pilha b para cima em 1.
    // O primeiro elemento se torna o ultimo.
// rr : ra e rb ao mesmo tempo.

//! reverse rotate
// rra (reverse rotate a): Move todos os elementos da pilha a para baixo em 1.
    // O ultimo elemento se torna o primeiro.
// rrb (reverse rotate b): Move todos os elementos da pilha b para baixo em 1.
    // O ultimo elemento se torna o primeiro.
// rrr : rra e rrb ao mesmo tempo.

t_stack	*new_node(int value, int index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	return (node);
}

void	stack_add_back(t_stack **lst, t_stack *new)
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

void	ft_lstclear(t_stack **lst)
{
	t_stack	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
