/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:53:49 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/12/13 14:53:49 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define VALID_CHARS "0123456789+-"
# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stackdata
{
	int	min;
	int	max;
	int	size;
	int	pivot;
}	t_stackdata;

char	*ft_replace(char *str, char s, char r);
int		ft_isblank(char c);
int		ft_has_blank(const char *str);
int		ft_check_int_out_of_range(const char *str);

int		check_arg(char *str);
int		valid_args(char **args);
void	print_vals(t_stack *lst);

void	ft_print_stack(t_stack *stack_a);
void	ft_print_stacks(t_stack *stack_a, t_stack *stack_b);
t_stack	*ft_stack_add(t_stack *stack, int value);
t_stack	*ft_stack_add_argc(t_stack *stack, int argc, char **argv);

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

int		ft_stack_is_sorted(t_stack *stack);
// void	ft_stack_sort(t_stack *stack_a, t_stack *stack_b);
// void	ft_stack_sort(t_stack *stack_a, t_stack *stack_b, int size);
void	ft_stack_sort_short(t_stack *stack_a);

void	ft_free(char **str);
t_stack	*ft_free_stack(t_stack *stack);

#endif
