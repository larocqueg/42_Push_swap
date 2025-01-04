/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:13:02 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/04 20:41:56 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

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

void	ft_sort_three(t_stack *a);
void	ft_sort(t_stack *a, t-stack *b);
size_t	ft_stack_len(t_stack *stack);
int		only_numbers(char *str);
#endif
