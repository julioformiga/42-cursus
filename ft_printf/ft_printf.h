/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:22:54 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/11/13 09:22:54 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define PRINTF_TYPES "cspdiuxX%"
# define PRINTF_FORMAT " 0-+#."
# define PRINTF_NUMBERS "0123456789"
# define HEX_STR "0123456789abcdef"

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_data
{
	char			type;
	char			format_type;
	char			*format;
	int				len;
	char			*print;
	char			print_char;
}	t_data;

int		print_char(char c);
int		print_string(char *str);

char	*get_ptr_addrs(void *ptr);
char	*get_char(char c);
char	*get_string(char *str);
char	*get_nbr(int nbr);
char	*get_unsigned_hex(unsigned int nbr, t_data *data);

int		ft_printf(const char *s, ...);
char	*ft_uitoa_base(unsigned long nbr, char *b_to, unsigned long b_size);
char	*ft_uitoa(unsigned int nbr);

#endif
