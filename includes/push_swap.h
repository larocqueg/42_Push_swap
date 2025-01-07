/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:13:02 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/07 14:24:38 by gde-la-r         ###   ########.fr       */
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
	int				n; // refers to the value
	int				index; // position of n
	int				cost; // push cost
	bool			a_median; // is above of median?
	bool			cheapest; // is the cheapest cost?
	struct s_stack	*t_node; // nodes inside the stack
	struct s_stack	*next; // points to the next node of my stack
	struct s_stack	*prev; // uso ou n?
}	t_stack;

// sort.c
int		ft_sorted(t_stack *stack);
void	ft_sort_three(t_stack **s);
void	ft_sort(t_stack **a, t_stack **b);

// utils.c
size_t	ft_stack_len(t_stack *stack);
void	free_stack(t_stack **stack);
void	ft_free(t_stack **stack, char **arr);
t_stack *ft_last(t_stack *stack);

// error.c
int		ft_error(t_stack *a);
int		only_numbers(char **arr);
int		doubles(t_stack **stack, int n);

// init_stack.c
void	create_nodes(t_stack **stack, int n);
t_stack	*init_stack_a(t_stack **stack, char **nums);

// swap.c
void	sa(t_stack **a, int n);
void	sb(t_stack **b, int n);
void	ss(t_stack **a, t_stack **b, int n);

// push.c
void	pa(t_stack **a, t_stack **b, int n);
void	pb(t_stack **a, t_stack **b, int n);

// rotate.c
void	ra(t_stack **a, int n);
void	rb(t_stack **b, int n);
void	rr(t_stack **a, t_stack **b, int n);

// rev_rotate.c

#endif
