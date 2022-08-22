/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:47:45 by seungjki          #+#    #+#             */
/*   Updated: 2022/08/17 13:30:03 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_base_changer(unsigned int n);
int		ft_bbase_changer(unsigned int n);
int		ft_char(unsigned char c);
int		ft_str(char *str);
int		ft_per(void);
int		ft_uint(unsigned int n);
int		ft_int(long long n);
int		ft_printf(const char *str, ...);
int		ft_memory(unsigned long long n);
char	*ft_strchr(const char *s, int c);

#endif
