/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_string.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-gin <mvan-gin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 12:12:49 by mvan-gin       #+#    #+#                */
/*   Updated: 2019/12/20 14:13:45 by mvan-gin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		fill_right_s(t_list *info, char *str)
{
	int index;
	int count;
	int	str_len;

	count = 0;
	index = 0;
	str_len = (int)ft_strlen(str);
	if (info->has_pre && str_len >= info->pre)
		str_len = info->pre;
	while (count < info->width - str_len)
	{
		if (info->has_zero)
			count += print_char('0');
		else
			count += print_char(' ');
	}
	while (str[index] != '\0')
	{
		if (info->has_pre && index == info->pre)
			return (count);
		count += print_char(str[index]);
		index++;
	}
	return (count);
}

int		set_value_left_s(t_list *info, char *str)
{
	int	index;
	int count;

	count = 0;
	index = 0;
	while (str[index] != '\0')
	{
		if (info->has_pre && index == info->pre)
		{
			break ;
		}
		count += print_char(str[index]);
		index++;
	}
	while (index < info->width)
	{
		count += print_char(' ');
		index++;
	}
	return (count);
}

int		convert_string(t_list *info, char *str)
{
	int		return_value;

	return_value = 0;
	if (str == 0)
	{
		str = "(null)";
	}
	if (info->has_minus)
	{
		return_value += set_value_left_s(info, str);
	}
	else
	{
		return_value += fill_right_s(info, str);
	}
	free(info);
	return (return_value);
}
