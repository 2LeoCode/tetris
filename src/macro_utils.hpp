/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_utils.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 01:45:12 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/04/08 17:09:09 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define term_gotoxy( x, y ) printf("\033[%d;%dH", y, x), fflush(stdout)
#define term_setbg( color ) printf("\e[48;5;%dm", color), fflush(stdout)
#define term_move( x, y ) do {\
	if ((x) > 0) printf("\033[%dC", x);\
	else if ((x) < 0) printf("\033[%dD", x);\
	if ((y) > 0) printf("\033[%dB", y);\
	else if ((y) < 0) printf("\033[%dA", y);\
	fflush(stdout);\
} while (0)

#define term_reset( ) write(1, "\e[0m", 4)
#define term_clear( ) write(1, "\e[1;1H\e[2J", 10)
