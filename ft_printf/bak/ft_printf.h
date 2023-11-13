/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:24:43 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/10/27 22:24:43 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define PRINTF_TYPES "cspdiuxX%"
# define HEX_STR "0123456789abcdef"
# define CHECK_AFTER_PERCENT "-0123456789"

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_data
{
	char			type;
	int				argc;
	int				len;
	char			*print;
	char			ch;
	int				nbr;
	char			*str;
	void			*hex_ptr;
	int				offset;
	unsigned int	unsig;
	int				flag_minus;
	int				flag_zero;
	int				flag_space;
	int				flag_plus;
	int				flag_hash;
}	t_data;

//printers
int		print_char(char c);
int		print_string(char *str);
int		print_ptr_addrs(void *ptr);
int		print_nbr(int nbr, t_data *data);
int		print_unsigned(unsigned int nbr);
int		print_unsigned_hex(unsigned int nbr, t_data *data);

//controller
int		ft_printf(const char *s, ...);
char	*ft_uitoa_base(unsigned long nbr, char *b_to, unsigned long b_size);
char	*ft_uitoa(unsigned int nbr);
void	init_flags(t_data *data);
char	printf_parser(const char *s, t_data *data);

#endif
