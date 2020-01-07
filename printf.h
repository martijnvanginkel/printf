/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-gin <mvan-gin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 14:42:38 by mvan-gin       #+#    #+#                */
/*   Updated: 2019/12/22 14:53:11 by mvan-gin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_list
{
	int			has_minus;
	int			has_zero;
	int			has_width;
	int			width;
	int			has_pre;
	int			pre;
	int			mal_size;
	int			pos;
	int			is_percent;
	int			is_string;
	int			is_char;
	int			is_digit;
	int			is_unsigned_dec;
	int			is_hex;
	int			is_big_hex;
	int			is_pointer;
}				t_list;

void			get_flag_information(const char *format, int *index,
				t_list **info);
void			get_width_information(const char *format, int *index,
				t_list **info, va_list *arg_ptr);
void			get_precision_information(const char *format, int *index,
				t_list **info, va_list *arg_ptr);
void			get_type_information(const char *format, int *index,
				t_list **info);
void			print_digit_string_u(t_list *info, unsigned int digit,
				int *index);
int				only_precision_u(t_list *info, unsigned int digit,
				int dig_length);
long			calculate_width(const char *format, int *index);
long			ft_atoi(const char *str);
size_t			ft_strlen(const char *s);
int				is_digit(int c);
int				convert_digit(t_list *info_block, long digit);
int				convert_char(t_list *info_block, int c);
int				convert_string(t_list *info_block, char *str);
int				convert_hex(t_list *info, unsigned int digit, int is_upper);
int				convert_pointer(t_list *info, unsigned long long address);
int				convert_unsigned(t_list *info, unsigned int digit);
int				print_char(char c);
int				print_string(char *str);
int				print_number(long number);
int				print_hex(char *hex_str);
int				print_unsigned(unsigned int number);
char			make_upper_on_yes(char c, int yes);
int				get_diglen(long n);
int				get_unsigned_len(unsigned int n);
int				only_width(t_list *inf, long digit, int diglen);
int				only_precision(t_list *info, long digit, int dig_length);
void			print_digit_string(t_list *info, long digit, int *index);
int				no_width_no_pre_hex(char *hex_str);
void			print_hex_string(t_list *info, unsigned int dig, char *hex_str,
				int *index);
char			*dec_to_hex(long dec_num, int is_upper);
int				ft_printf(const char *format, ...);

#endif
