/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:13:02 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/12/17 14:15:58 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include ".././libft/libft.h"

typedef struct s_stack
{
	int				n;
	int				index;
	int				cost;
	bool			a_median;
	bool			cheapest;
	struct s_stack	*t_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*init_stack(t_stack *head);
t_stack	*sa(t_stack	*a);
t_stack	*sb(t_stack *b);
t_stack	*pa(t_stack *a, t_stack *b);
t_stack	*pb(t_stack *a, t_stack *b);
t_stack	*ra(t_stack *a);
t_stack	*rb(t_stack *b);
t_stack	*rra(t_stack *a);
t_stack	*rrb(t_stack *b);
size_t	ft_stack_len(t_stack *stack);

#endif
