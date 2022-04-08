/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:20:00 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/04/07 12:12:48 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <random>

namespace rng {

  int	random(int min, int max) {
    static std::random_device							d;
    static std::mt19937										rng(d());
    std::uniform_int_distribution< int >	dist(min, max);

    return dist(rng);
  }

}
