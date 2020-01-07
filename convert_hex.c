/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_hex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-gin <mvan-gin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 13:00:00 by mvan-gin       #+#    #+#                */
/*   Updated: 2019/12/19 18:06:27 by mvan-gin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			only_precision_hex(t_list *info, unsigned int digit, char *hex_str,
			int hex_len)
{
	int index;

	index = 0;
	if (digit == 0 && info->pre == 0)
		return (0);
	while (index < info->pre - hex_len)
	{
		index += print_char('0');
	}
	index += print_hex(hex_str);
	return (index);
}

int			only_width_hex(t_list *inf, unsigned int dig, char *hex_str,
			int hex_len)
{
	int i;

	i = 0;
	if (inf->has_minus)
	{
		print_hex_string(inf, dig, hex_str, &i);
	}
	else
	{
		while (i < inf->width - hex_len)
		{
			inf->has_zero ? print_char('0') : print_char(' ');
			i++;
		}
		if (inf->has_pre && inf->pre == 0 && dig == 0)
			i += print_char(' ');
		else
			i += print_hex(hex_str);
	}
	return (i);
}

int			bigger_diglen_than_pre_hex(t_list *inf, unsigned int dig,
			char *hex_str, int hex_len)
{
	int i;

	i = 0;
	while (inf->has_minus && i < inf->pre - hex_len)
	{
		i += print_char('0');
	}
	while (!inf->has_minus && i < inf->width - hex_len)
	{
		if (i > (inf->width - inf->pre - 1))
		{
			i += print_char('0');
		}
		else if (i < inf->width - hex_len)
			i += print_char(' ');
	}
	print_hex_string(inf, dig, hex_str, &i);
	return (i);
}

int			width_and_precision_hex(t_list *info, unsigned int digit,
			char *hex_str, int hex_len)
{
	int	index;

	index = 0;
	if (info->pre >= info->width)
		index = only_precision_hex(info, digit, hex_str, hex_len);
	else
	{
		if (info->width > info->pre && info->pre <= hex_len && !info->has_zero)
		{
			index = only_width_hex(info, digit, hex_str, hex_len);
		}
		else
		{
			index = bigger_diglen_than_pre_hex(info, digit, hex_str, hex_len);
		}
	}
	return (index);
}

int			convert_hex(t_list *info, unsigned int digit, int is_upper)
{
	int		index;
	char	*hex_str;
	int		hex_length;

	index = 0;
	hex_str = dec_to_hex(digit, is_upper);
	hex_length = (int)ft_strlen(hex_str);
	info->pos = 1;
	if (info->has_width && !info->has_pre)
		index += only_width_hex(info, digit, hex_str, hex_length);
	else if (!info->has_width && info->has_pre)
		index += only_precision_hex(info, digit, hex_str, hex_length);
	else if (!info->has_width && !info->has_pre)
		index += no_width_no_pre_hex(hex_str);
	else
		index += width_and_precision_hex(info, digit, hex_str, hex_length);
	free(hex_str);
	free(info);
	return (index);
}
