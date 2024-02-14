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
# include <stdlib.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"

typedef struct s_stack
{
	int				*val;
	struct s_stack	*next;
}	t_stack;

char	*ft_replace(char *str, char s, char r);
int		ft_isblank(char c);
int		has_blank(const char *str);

int		check_arg(char *str);
int		valid_args(char **args);

#endif
