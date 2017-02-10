/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:06:23 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/20 12:46:51 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <unistd.h>

typedef struct		s_flags
{
	t_bool		sharp;
	t_bool		zero;
	t_bool		dash;
	t_bool		space;
	t_bool		plus;
}					t_flags;

typedef struct		s_length
{
	int			l;
	int			h;
	int			j;
	int			z;
	int			f;
}					t_length;

typedef struct		s_specifiers
{
	t_flags		flags;
	int			width;
	int			precision;
	t_length	length;
	char		identifier;
}					t_specifiers;

int					ft_printf(const char *format, ...);
void				ftpf_get_format_specifications(char const **format,
									va_list ap, t_specifiers *specifiers);
char				*ftpf_get_raw_data(va_list ap, t_specifiers specifiers,
									int *size, int n);
void				ftpf_process_data(char **data, int *size,
									t_specifiers specifiers);
void				ftpf_get_flags(const char **format,
									t_specifiers *specifiers);
void				ftpf_get_width(const char **format,
									t_specifiers *specifiers, va_list ap);
void				ftpf_get_precision(const char **format,
									t_specifiers *specifiers, va_list ap);
void				ftpf_get_length_specifier(char const **format,
									t_specifiers *specifiers);
void				ftpf_get_identifier(const char **format,
									t_specifiers *specifiers);
char				*ftpf_convert_unsigned(va_list ap,
									t_specifiers specifiers, int *size);
char				*ftpf_convert_signed(va_list ap,
									t_specifiers specifiers, int *size);
char				*ftpf_convert_float(va_list ap, t_specifiers specifiers,
									int *size);
char				*ftpf_convert_characters(va_list ap,
										t_specifiers specifiers, int *size);
void				ftpf_apply_width_dash(char **data, int *size, int width);
void				ftpf_process_unsigned(char **data, int *size,
									t_specifiers specifiers);
void				ftpf_process_signed(char **data, int *size,
									t_specifiers specifiers);
void				ftpf_process_characters(char **data, int *size,
									t_specifiers specifiers);
void				ftpf_process_float(char **data, int *size,
									t_specifiers specifiers);
char				*ft_itoa_base_lld(intmax_t value, int base);
char				*ft_itoa_base_llu(uintmax_t value, int base);
char				*ft_ftoa(long double value, int precision);
char				*ft_unicode_encoder(wchar_t unicode);
char				*ft_unicode_encoder_string(wchar_t *unicode_str);
t_bool				ftpf_is_flag(const char c);
t_bool				ftpf_is_length_specifier(char const c);
t_bool				ftpf_is_identifier(char const c);
t_bool				ftpf_is_signed_conv(char c);
t_bool				ftpf_is_unsigned_conv(char c);
t_bool				ftpf_is_characters_conv(char c);
t_bool				ftpf_is_float_conv(char c);
int					ftpf_get_conv_base(char id);
void				ftpf_initialize_specifiers(t_specifiers *specifiers);

#endif
