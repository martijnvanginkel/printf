/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_char.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-gin <mvan-gin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 13:00:00 by mvan-gin       #+#    #+#                */
/*   Updated: 2019/12/19 18:03:51 by mvan-gin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		set_value_left_c(char c, t_list *info)
{
	int	index;
	int	count;

	count = 0;
	index = 0;
	count += print_char(c);
	index++;
	while (index < info->width)
	{
		count += print_char(' ');
		index++;
	}
	return (count);
}

int		fill_right_without_zero_c(char c, t_list *info)
{
	int index;
	int count;

	count = 0;
	index = 0;
	while (index < (info->width - 1))
	{
		count += print_char(' ');
		index++;
	}
	count += print_char(c);
	return (count);
}

int		fill_right_with_zero_c(char c, t_list *info)
{
	int index;
	int count;

	count = 0;
	index = 0;
	while (index < (info->width - 1))
	{
		count += print_char('0');
		index++;
	}
	count += print_char(c);
	return (count);
}

int		set_value_right_c(char my_char, t_list *info)
{
	if (info->has_zero == 0)
	{
		return (fill_right_without_zero_c(my_char, info));
	}
	else
	{
		return (fill_right_with_zero_c(my_char, info));
	}
}

int		convert_char(t_list *info, int c)
{
	char	my_char;
	int		return_value;

	my_char = (char)c;
	return_value = 0;
	if (info->has_minus)
	{
		return_value += set_value_left_c(my_char, info);
	}
	else
	{
		return_value += set_value_right_c(my_char, info);
	}
	free(info);
	return (return_value);
}
