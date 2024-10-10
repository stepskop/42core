/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:04:57 by username          #+#    #+#             */
/*   Updated: 2024/10/10 22:41:23 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
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
	ROTATE_AB,
	RROTATE_AB,
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
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// Parse
void	parse_mul(t_stack **a, int argc, char **argv);
void	parse_one(t_stack **a, char *str);
int		add_new(t_stack **a, int value);
int		is_valid(char *str, int *value, int *all_nums, int num_count);
size_t	count_words(char *str);

// Sort
int		sort(t_stack **a, t_stack **b, t_ops **ops);
int		is_sorted(t_stack *a);
void	set_props(t_stack **a, t_stack **b);

// Operations
int		opti_ops(t_ops **ops);
int		add_op(t_ops **ops, enum e_moves move);

// Memory
void	free_stack(t_stack **stk);
void	free_ops(t_ops **ops);
void	free_all(t_stack **a, t_stack **b, t_ops **ops);

// Print
void	print_ops(t_ops *ops);

#endif
