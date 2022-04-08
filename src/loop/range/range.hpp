/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 01:09:52 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/04/04 02:39:47 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include "../../macro_utils.hpp"

namespace loop {

	template < class T >
	std::vector< T >	range(T begin, T end) {
		std::size_t				dist = abs(end - begin);
		std::vector< T >	rg;

		rg.reserve(dist);
		if (begin < end) {
			while (begin < end) {
				rg.push_back(begin++);
			}
		} else {
			while (begin > end)
				rg.push_back(begin--);
		}
		return rg;
	}

}
