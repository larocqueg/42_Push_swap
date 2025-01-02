/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:21:19 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/02 16:29:25 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack *s)
{
	if (s->n > s->next->n && s->next->n > s->next->next->n)
	{
		sa(s);
		rra(s);
	}
	else if (s->n > s->next->next->n && s->next->next->n > s->next->n)
		ra(s);
	else if (s->next->n > s->n && s->n > s->next->next->n)
		rra(s);
	else if (s->next->n > s->next->next->n && s->next->next->n > s->n)
		sa(s);
	else if (s->next->next->n > s->n && s->n > s->next->n)
	{
		sa(s);
		ra(s);
	}
}
