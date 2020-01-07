/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_pointer.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-gin <mvan-gin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 15:08:31 by mvan-gin       #+#    #+#                */
/*   Updated: 2019/12/22 13:41:23 by mvan-gin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		fill_right_p(t_list *info, char *str)
{
	int index;
	int count;
	int	str_len;

	count = 0;
	index = 0;
	str_len = (int)ft_strlen(str) + 2;
	if (info->has_pre && str_len >= info->pre && info->pre != 0)
		str_len = info->pre;
	while (count < info->width - str_len)
	{
		if (info->has_zero)
			count += print_char('0');
		else
			count += print_char(' ');
	}
	count += print_string("0x");
	while (str[index] != '\0')
	{
		if (info->has_pre && index == info->pre && index != 0)
			return (count);
		count += print_char(str[index]);
		index++;
	}
	return (count);
}

int		set_value_left_p(t_list *info, char *str)
{
	int	index;
	int count;

	count = 0;
	index = 0;
	count += print_string("0x");
	info->width = info->width - 2;
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

int		null_exception(t_list *info, char *hex_str)
{
	int index;
	int	hex_len;

	index = 0;
	hex_len = (int)ft_strlen(hex_str);
	if (!info->has_width)
	{
		index += print_string("0x");
	}
	else
	{
		if (info->width > 0)
		{
			while (index < info->width - hex_len - 1)
			{
				index += print_char(' ');
			}
			index += print_string("0x");
		}
	}
	return (index);
}

int		convert_pointer(t_list *info, unsigned long long address)
{
	int		return_value;
	char	*hex_str;

	return_value = 0;
	hex_str = dec_to_hex(address, 0);
	if (address == 0 && info->has_pre && info->pre == 0 && !info->has_minus)
		return_value += null_exception(info, hex_str);
	else if (info->has_minus)
		return_value += set_value_left_p(info, hex_str);
	else
		return_value += fill_right_p(info, hex_str);
	free(hex_str);
	free(info);
	return (return_value);
}
