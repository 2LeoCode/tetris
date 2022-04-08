/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:30:33 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/04/04 02:40:48 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro_utils.hpp"
#include <iostream>
#include <cstring>
#include <string>
#include <unistd.h>
#include "rng.hpp"
#include "tetris.hpp"
#include "loop.hpp"

using std::cout;
using std::endl;

using tetris::shape;
using loop::range;


int	main( void ) {
	shape	s(rng::random());
	auto	data = s.get();

	tclear();
	for (auto i: range(0, 4)) {
		tgotoxy(30, 15 + i);
		for (auto j: range(0, 4)) {
			tsetbg(data[i][j]);
			write(1, "  ", 2);
		}
		cout << endl;
	}
	return 0;
}
