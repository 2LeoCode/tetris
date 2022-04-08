/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:08:49 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/04/07 13:51:49 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../math.hpp"
#include "../shape/shape.hpp"

using math::vec2;
using tetris::shape;

namespace tetris {

  class grid {
    public:                
      grid( int = 0, int = 0);
      ~grid();

      grid  &roll( void );
      grid  &push( void );
      grid  &rotate( void );
      grid  &move( bool );
      grid  &draw( void );

      struct LoseEvent { };
      struct WinEvent { };
      struct VerticalCollisionEvent { };
      struct LatteralCollisionEvent { };

      struct NoShapeException : public std::exception {
        const char  *what( void ) const throw () { return "no shape to push"; }
      };
    private:
      vec2  m_pos;
      char  m_data[18][10];
      bool  m_flushed[18][10];
      shape *m_curShape;
      shape *m_nextShape;
      vec2  m_curShapePos;
  };

}
