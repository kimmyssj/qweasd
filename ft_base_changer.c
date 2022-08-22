/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_changer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 02:50:08 by seungjki          #+#    #+#             */
/*   Updated: 2022/07/27 22:42:09 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_base_put_in(char *hex)
{
	int	idx;

	idx = 0;
	while (idx < 10)
	{
		hex[idx] = '0' + idx;
		idx ++;
	}
	while (idx - 10 < 6)
	{
		hex[idx] = 'a' - 10 + idx;
		idx ++;
	}
}

int	ft_base_changer(unsigned int n)
{
	char				hex[16];
	unsigned long long	front_numb;
	int					idx;

	idx = 0;
	front_numb = 1;
	ft_base_put_in(hex);
	while (n / front_numb >= 16)
		front_numb = front_numb * 16;
	while (front_numb != 0)
	{
		idx ++;
		write(1, hex + (n / front_numb), 1);
		n = n % front_numb;
		front_numb = front_numb / 16;
	}
	return (idx);
}

void	ft_bbase_put_in(char *hex)
{
	int	idx;

	idx = 0;
	while (idx < 10)
	{
		hex[idx] = '0' + idx;
		idx ++;
	}
	while (idx - 10 < 6)
	{
		hex[idx] = 'A' - 10 + idx;
		idx ++;
	}
}

int	ft_bbase_changer(unsigned int n)
{
	char				hex[16];
	unsigned long long	front_numb;
	int					idx;

	idx = 0;
	front_numb = 1;
	ft_bbase_put_in(hex);
	while (n / front_numb >= 16)
		front_numb = front_numb * 16;
	while (front_numb != 0)
	{
		idx ++;
		write(1, hex + (n / front_numb), 1);
		n = n % front_numb;
		front_numb = front_numb / 16;
	}
	return (idx);
}
