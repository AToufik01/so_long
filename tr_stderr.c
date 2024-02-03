/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr_stderr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:08:41 by ataoufik          #+#    #+#             */
/*   Updated: 2024/02/01 00:10:37 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long.h"
#include "Mandatory/so_long.h"

void	printgameover(void)
{
	ft_putendl_fd("\033[1;31m"
		"\n"
		"\n"
		"\n"
		"\n"
		" ██████╗  █████╗ ███╗   ███╗███████╗     "
		"██████╗ ██╗   ██╗███████╗██████╗\n"
		"██╔════╝ ██╔══██╗████╗ ████║██╔════╝    "
		"██╔═══██╗██║   ██║██╔════╝██╔══██╗\n"
		"██║  ███╗███████║██╔████╔██║█████╗      "
		"██║   ██║██║   ██║█████╗  ██████╔╝\n"
		"██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      "
		"██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗\n"
		"╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    "
		"╚██████╔╝ ╚████╔╝ ███████╗██║  ██║\n"
		"╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     "
		"╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝\n"
		"\n"
		"\n"
		"\033[0m\n", 2);
	exit(0);
}

void	printwin(void)
{
	ft_putendl_fd("\033[1;32m"
		"\n"
		"██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗██╗███╗   ██╗    ██╗\n"
		"╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║██║████╗  ██║    ██║\n"
		" ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║    ██║\n"
		"  ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║██║╚██╗██║    ╚═╝\n"
		"   ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║    ██╗\n"
		"   ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝    ╚═╝\n"
		"\033[0m\n", 2);
	exit(0);
}