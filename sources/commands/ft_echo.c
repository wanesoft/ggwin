/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 12:31:45 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/01 21:05:49 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_echo(char **arr)
{
	while (*arr)
	{
		ft_putstr(*arr);
		if (*(++arr))
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (1);
}