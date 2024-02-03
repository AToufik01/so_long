/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:36:26 by ataoufik          #+#    #+#             */
/*   Updated: 2024/01/23 11:43:03 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if ((int)count >= 0 && (int)size >= 0)
	{
		str = malloc(count * size);
		if (!str)
			return (0);
		ft_bzero(str, count * size);
		return (str);
	}
	return (0);
}
