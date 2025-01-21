/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:13:02 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/21 18:54:52 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				n; // refers to the value
	int				index; // position of n
	int				cost; // push cost
	int				median; // defines the median
	int				above_median; // is above of median?
	int				cheapest; // is the cheapest cost?
	struct s_stack	*target; // target node
	struct s_stack	*next; // points to the next node of my stack
	struct s_stack	*prev; // uso ou n?
}	t_stack;

// sort.c
int		ft_sorted(t_stack *stack);
void	ft_sort_three(t_stack **s);
void	ft_sort_stacks(t_stack **a, t_stack **b);
void	set_cheapest_to_top(t_stack **stack, t_stack *node, int checker);

// utils.c
size_t	ft_stack_len(t_stack *stack);
t_stack	*ft_last(t_stack *stack);
void	check_2(t_stack **stack);
long	ft_atolong(const char *str);
t_stack	*find_cheapest(t_stack **stack);

// sort_utils.c
void	set_index(t_stack *stack);
void	set_target_a(t_stack *a, t_stack *b);
t_stack	*max_n(t_stack *stack);
void	set_cost_a(t_stack *a, t_stack *b);
void set_cost_b(t_stack *a, t_stack *b);
void	reset_index(t_stack **a, t_stack **b);

// sort_utils_utils.c
void	set_target_b(t_stack *a, t_stack *b);
t_stack	*min_n(t_stack *stack);
t_stack	*return_cheapest(t_stack *stack);

//free.c
void	free_stack(t_stack **stack);
void	ft_free(t_stack **a, t_stack **b, char **arr, int ac);

// error.c
int		ft_error(t_stack *a);
int		only_numbers(char **arr);
int		doubles(t_stack *stack, int n);

// init_stack.c
void	create_nodes(t_stack **stack, int n);
t_stack	*init_stack_a(t_stack **stack, char **nums, int ac);
void	push_b_to_a(t_stack **a, t_stack **b);
void	lower_on_top(t_stack **a);

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
void	rra(t_stack **a, int n);
void	rrb(t_stack **b, int n);
void	rrr(t_stack **a, t_stack **b, int n);

// print.c
void	print_stack(t_stack *s);
void	print_index(t_stack *s);
void	print_median(t_stack *s);
void	print_above_median(t_stack *s);
void	print_target(t_stack *s);
void	print_cost(t_stack *s);
void	print_cheap(t_stack *s);

#endif
