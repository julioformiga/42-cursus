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
# define PRINTF_FORMAT "-0.# +"
# define PRINTF_NUMBERS "0123456789"
# define HEX_STR "0123456789abcdef"

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_data
{
	char			type;
	char			format_type;
	char			*format;
	char			*print;
	int				number_neg;
	int				len;
}	t_data;

int		print_char(char c);
int		print_string(char *str);
void	print_args(const char *str, t_data *data, va_list args);
void	print_data(t_data *data);
void	print_pre_format(t_data *data);
void	print_pos_format(t_data *data);
int		print_pos_format_conditions(t_data *data);
void	print_pre_format_specifics(t_data *data);
void	print_pre_format_number(t_data *data);
void	print_pre_format_string(t_data *data);
void	print_pre_pointers(t_data *data);
void	print_pre_pointers_specifics(t_data *data);
void	print_pos_pointers(t_data *data);
int		print_format_null(t_data *data);

char	*get_string(char *str);
char	*get_nbr(int nbr);
char	*get_ptr_addrs(void *ptr);
char	*get_unsigned_hex(unsigned int nbr, t_data *data);
void	get_data_strings(t_data *data, va_list args);
void	get_arg_format(char c, t_data *data);

void	show_data(t_data *data);
void	reset_data(t_data *data);
char	*ft_uitoa_base(unsigned long nbr, char *b_to, unsigned long b_size);
char	*ft_uitoa(unsigned int nbr);
int		ft_printf(const char *s, ...);
int		is_print_null(t_data *data);
int		ftype_has(t_data *data, char *has);

#endif
