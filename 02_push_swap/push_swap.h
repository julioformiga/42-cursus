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

size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		ft_printf(const char *s, ...);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);

#endif
