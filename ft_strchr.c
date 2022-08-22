/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 02:04:59 by seungjki          #+#    #+#             */
/*   Updated: 2022/07/28 18:51:14 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	idx;

	idx = 0;
	if (c == 0)
	{
		while (s[idx])
			idx++;
		return ((char *)s + idx);
	}
	while (s[idx])
	{
		if (s[idx] == c)
			return ((char *)s + idx);
		idx++;
	}
	return (0);
}
