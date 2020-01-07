/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-gin <mvan-gin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 10:10:32 by mvan-gin       #+#    #+#                */
/*   Updated: 2020/01/06 08:54:54 by mvan-gin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_list	*make_empty_info(void)
{
	t_list *info;

	info = malloc(sizeof(t_list));
	info->has_minus = 0;
	info->has_zero = 0;
	info->has_width = 0;
	info->width = 0;
	info->has_pre = 0;
	info->pre = 0;
	info->mal_size = 0;
	info->pos = 0;
	info->is_percent = 0;
	info->is_string = 0;
	info->is_char = 0;
	info->is_digit = 0;
	info->is_unsigned_dec = 0;
	info->is_hex = 0;
	info->is_big_hex = 0;
	info->is_pointer = 0;
	return (info);
}

long	calculate_width(const char *format, int *index)
{
	char	*result;
	long	result_index;
	int		string_length;

	string_length = 0;
	result_index = *index;
	while (is_digit(format[result_index]) && format[result_index] != '\0')
	{
		result_index++;
		string_length++;
	}
	result = malloc(sizeof(char) * (string_length + 1));
	if (!result)
		return (0);
	result_index = 0;
	while (result_index < string_length)
	{
		result[result_index] = format[(*index)];
		result_index++;
		(*index)++;
	}
	result[result_index] = '\0';
	result_index = ft_atoi(result);
	free(result);
	return (result_index);
}

void	collect_information(const char *format, int *index, t_list **info,
		va_list *arg_ptr)
{
	get_flag_information(format, index, info);
	get_width_information(format, index, info, arg_ptr);
	get_precision_information(format, index, info, arg_ptr);
	get_type_information(format, index, info);
}

int		find_variable_type(const char *format, va_list *argument_ptr,
		int *index_ptr)
{
	t_list *info;

	*index_ptr = *index_ptr + 1;
	info = make_empty_info();
	collect_information(format, index_ptr, &info, argument_ptr);
	if (info->is_percent)
		return (convert_char(info, '%'));
	else if (info->is_digit)
		return (convert_digit(info, va_arg(*argument_ptr, int)));
	else if (info->is_string)
		return (convert_string(info, va_arg(*argument_ptr, char *)));
	else if (info->is_char)
		return (convert_char(info, va_arg(*argument_ptr, int)));
	else if (info->is_hex)
		return (convert_hex(info, va_arg(*argument_ptr, unsigned int), 0));
	else if (info->is_big_hex)
		return (convert_hex(info, va_arg(*argument_ptr, unsigned int), 1));
	else if (info->is_pointer)
		return (convert_pointer(info, va_arg(*argument_ptr,
		unsigned long long)));
	else if (info->is_unsigned_dec)
		return (convert_unsigned(info, va_arg(*argument_ptr, unsigned int)));
	return (0);
}

int		ft_printf(const char *format, ...)
{
	int		index;
	int		total_printed;
	va_list argument_ptr;

	index = 0;
	total_printed = 0;
	va_start(argument_ptr, format);
	while (format[index] != '\0')
	{
		if (format[index] != '%')
		{
			total_printed += print_char(format[index]);
			index++;
		}
		else
		{
			total_printed += find_variable_type(format, &argument_ptr, &index);
		}
	}
	va_end(argument_ptr);
	return (total_printed);
}
