/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:04:57 by username          #+#    #+#             */
/*   Updated: 2024/10/14 01:41:34 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

enum e_moves
{
	PUSH_A,
	PUSH_B,
	SWAP_A,
	SWAP_B,
	ROTATE_A,
	ROTATE_B,
	RROTATE_A,
	RROTATE_B,
	SWAP_AB,
	RROTATE_AB,
	ROTATE_AB,
};

enum e_stacks
{
	A,
	B
};

typedef struct s_ops
{
	enum e_moves	op;
	struct s_ops	*next;
	struct s_ops	*prev;
}	t_ops;

typedef struct s_stack
{
	int				value;
	int				index;
	int				upper;
	int				price;
	int				cheap;
	enum e_stacks	stk_e;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_push
{
	struct s_stack	**from;
	struct s_stack	**to;
}	t_push;

// Parse
void	parse_mul(t_stack **a, int argc, char **argv);
void	parse_one(t_stack **a, char *str);
int		add_new(t_stack **a, int value, enum e_stacks stk_e);
int		is_valid(char *str, int *value, int parse_one);

// Sort
int		sort(t_stack **a, t_stack **b, t_ops **ops);
int		is_sorted(t_stack *a);
t_stack	*set_cost(t_stack **a, t_stack **b);
int		push_node(t_push push_data, t_stack *node, t_ops **ops);
int		top_price(t_stack *node, int stack_size);
int		sort_three(t_stack **stk, t_ops **ops);

// Operations
int		opti_ops(t_ops **ops);
int		add_op(t_ops **ops, enum e_moves move);

// Memory
void	free_stack(t_stack **stk);
void	free_ops(t_ops **ops);
void	free_all(t_stack **a, t_stack **b, t_ops **ops);

// Print
void	print_ops(t_ops *ops);

// Stack utils
int		set_index(t_stack **stk);
void	set_props(t_stack **a, t_stack **b);
int		get_avg(t_stack **stk);

// Moves
int		rotate(t_stack **stk, t_ops **ops);
int		rrotate(t_stack **stk, t_ops **ops);
int		swap(t_stack **stk, t_ops **ops);
int		push(t_push push_data, t_ops **ops);
int		s_rot(t_stack **stk, t_stack *node, t_ops **ops);

#endif
