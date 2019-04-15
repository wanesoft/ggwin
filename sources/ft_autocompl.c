/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autocompl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:44:47 by draynor           #+#    #+#             */
/*   Updated: 2019/03/02 17:45:33 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static char			**ft_get_gcom_arr(char str[B_SIZE], int *j)
{
	char			**arr;
	int				i;
	int				count;
	
	count = 0;;
	i = 0;
	arr = NULL;
	while (g_commands[i])
	{
		if (ft_strnequ(str, g_commands[i], *j))
		{
			count++;
			if (count == 1)
				ft_putchar('\n');
			ft_putstr(g_commands[i]);
			if (count)
				ft_putchar(' ');
		}
		i++;
	}
	if (count)
	{
		arr = (char **)malloc(sizeof(char *) * (count + 1));
		arr[count] = NULL;
	}
	ft_putchar('\n');
	return (arr);
}

//void				ft_autocompl_2(char str[B_SIZE], int *j)
//{
//	int				i;
//
//	i = 0;
//	while (g_commands[i])
//	{
//		if (ft_strnequ(str, g_commands[i], ((*j))))
//		{
//			ft_memcpy(str, g_commands[i], ft_strlen(g_commands[i]) + 1);
//			break ;
//		}
//		i++;
//	}
//	if (g_commands[i])
//		(*j) = (int)ft_strlen(g_commands[i]);
////	ft_putstr_fd(tgetstr("dl", NULL), TESTTT);
////	ft_putstr_fd(tgetstr("cr", NULL), TESTTT);
//}

static void			ft_autocompl_2(char str[B_SIZE], int *j, char **arr_gcom)
{
	int				i;
	int				jj;
	
	jj = 1;
	i = 0;
	while (arr_gcom && arr_gcom[i])
	{
		if (arr_gcom[i + 1] && arr_gcom[i][*j] == arr_gcom[i + 1][*j])
			++jj;
		++i;
	}
	if (jj == ft_count_arr(arr_gcom))
	{
		--i;
		str[*j] = arr_gcom[i][*j];
		*j = *j + 1;
		ft_autocompl_2(str, j, arr_gcom);
	}
//	if (g_commands[i])
//		(*j) = (int)ft_strlen(g_commands[i]);
}

void				ft_autocompl(char str[B_SIZE], int *j)
{
	int				i;
	char			**arr_gcom;
	int				k;
	
	arr_gcom = ft_get_gcom_arr(str, j);
	i = 0;
	k = 0;
	while (arr_gcom && g_commands[i])
	{
		if (ft_strnequ(str, g_commands[i], *j))
		{
			arr_gcom[k] = ft_strdup(g_commands[i]);
			k++;
		}
		i++;
	}
	ft_autocompl_2(str, j, arr_gcom);
	free(arr_gcom);
	//del arr_gcom
	ft_putstr_fd(tgetstr("dl", NULL), TESTTT);
	ft_putstr_fd(tgetstr("cr", NULL), TESTTT);
}
