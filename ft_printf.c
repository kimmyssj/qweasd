/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 04:18:21 by seungjki          #+#    #+#             */
/*   Updated: 2022/08/22 13:03:42 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	"ft_printf.h"
#include	<stdarg.h>

int	type_check(char cha, va_list *ap)
{
	int		str_idx;

	str_idx = 0;
	if (cha == 'x')
		str_idx = ft_base_changer(va_arg(*ap, unsigned int));
	else if (cha == 'X')
		str_idx = ft_bbase_changer(va_arg(*ap, unsigned int));
	else if (cha == 'p')
		str_idx = ft_memory(va_arg(*ap, long long));
	else if (cha == 's')
		str_idx = ft_str(va_arg(*ap, char *));
	else if (cha == 'c')
		str_idx = ft_char(va_arg(*ap, int));
	else if (cha == 'd')
		str_idx = ft_int(va_arg(*ap, int));
	else if (cha == 'i')
		str_idx = ft_int(va_arg(*ap, int));
	else if (cha == 'u')
		str_idx = ft_uint(va_arg(*ap, unsigned int));
	else if (cha == '%')
		str_idx = ft_per();
	return (str_idx);
}

int	additional_flag(char const *str, va_list *ap)
{
	char	*set;
	int		idx;
	int		str_idx;

	idx = 0;
	str_idx = 0;
	set = "xXpscdiu%";
	while (!ft_strchr(set, *str))
		idx ++;
	str_idx = type_check(str[idx], ap);
	return (str_idx);
}

int	ft_printf(const char *str, ...)
{
	int		idx;
	int		str_idx;
	va_list	ap;

	va_start(ap, str);
	idx = 0;
	str_idx = 0;
	while (str[idx])
	{
		if (str[idx] == '%')
		{
			idx ++;
			str_idx = str_idx + additional_flag(str + idx, &ap);
		}
		else
		{
			write(1, str + idx, 1);
			str_idx ++;
		}
		idx ++;
	}
	va_end(ap);
	return (str_idx);
}
