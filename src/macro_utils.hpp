/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_utils.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 01:45:12 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/04/07 12:06:14 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define tgotoxy( x, y ) printf("\033[%d;%dH", y, x), fflush(stdout)
#define tsetbg( color ) printf("\e[48;5;%dm", color), fflush(stdout)
#define tmove( x, y ) do {\
	if ((x) > 0) printf("\033[%dC", x);\
	else if ((x) < 0) printf("\033[%dD", x);\
	if ((y) > 0) printf("\033[%dB", y);\
	else if ((y) < 0) printf("\033[%dA", y);\
	fflush(stdout);\
} while (0)

#define treset( ) write(1, "\e[0m", 4)
#define tclear( ) write(1, "\e[1;1H\e[2J", 10)
