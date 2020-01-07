/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-gin <mvan-gin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 15:58:12 by mvan-gin       #+#    #+#                */
/*   Updated: 2019/12/22 14:50:59 by mvan-gin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	get_flag_information(const char *format, int *index, t_list **info)
{
	while (format[*index] != '\0')
	{
		if (format[*index] == '-')
			(*info)->has_minus = 1;
		else if (format[*index] == '0')
			(*info)->has_zero = 1;
		else
			return ;
		*index = *index + 1;
	}
}

void	get_width_information(const char *format, int *index, t_list **info,
		va_list *arg_ptr)
{
	int		width;
	int		arg_value;

	width = 0;
	if (is_digit(format[*index]) == 1 && format[*index] != '0')
	{
		width = calculate_width(format, index);
		(*info)->has_width = 1;
		(*info)->width = width;
	}
	else
	{
		if (format[*index] == '*' && format[*index] != '0')
		{
			arg_value = va_arg(*arg_ptr, long);
			if (arg_value < 0)
			{
				(*info)->has_minus = 1;
				arg_value = arg_value * -1;
			}
			(*info)->has_width = 1;
			(*info)->width = arg_value;
			(*index)++;
		}
	}
}

void	get_precision_information(const char *format, int *index, t_list **info,
		va_list *arg_ptr)
{
	int		precision;

	precision = 0;
	if (format[*index] == '.')
	{
		(*info)->has_pre = 1;
		if (is_digit(format[*index + 1]) == 1 && format[*index + 1] != '\0')
		{
			*index = *index + 1;
			(*info)->pre = calculate_width(format, index);
		}
		else
		{
			if (format[*index + 1] == '*' && format[*index + 1] != '\0')
			{
				(*info)->pre = va_arg(*arg_ptr, long);
				if ((*info)->pre < 0)
				{
					(*info)->has_pre = 0;
				}
				*index = *index + 1;
			}
			*index = *index + 1;
		}
	}
}

void	get_type_information(const char *format, int *index, t_list **info)
{
	if (format[*index] == 0)
		return ;
	if (format[*index] == '%')
		(*info)->is_percent = 1;
	else if (format[*index] == 'c')
		(*info)->is_char = 1;
	else if (format[*index] == 's')
		(*info)->is_string = 1;
	else if (format[*index] == 'd' || format[*index] == 'i')
		(*info)->is_digit = 1;
	else if (format[*index] == 'u')
		(*info)->is_unsigned_dec = 1;
	else if (format[*index] == 'x')
		(*info)->is_hex = 1;
	else if (format[*index] == 'X')
		(*info)->is_big_hex = 1;
	else if (format[*index] == 'p')
		(*info)->is_pointer = 1;
	else
		return ;
	*index = *index + 1;
}
