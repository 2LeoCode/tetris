/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:28:28 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/04/07 23:31:06 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.hpp"
#include "../../rng.hpp"
#include "../../loop.hpp"
#include "../../macro_utils.hpp"
#include <unistd.h>

using loop::range;

namespace tetris {

  grid::grid( int x, int y )
  : m_pos{ x, y },
    m_data{
      { 256, 256, 256, 256, 256, 256, 256, 256, 256, 256 },
      { 256, 0,   0,   0,   0,   0,   0,   0,   0,   256 },
      { 256, 0,   0,   0,   0,   0,   0,   0,   0,   256 },
      { 256, 0,   0,   0,   0,   0,   0,   0,   0,   256 },
      { 256, 0,   0,   0,   0,   0,   0,   0,   0,   256 },
      { 256, 0,   0,   0,   0,   0,   0,   0,   0,   256 },
      { 256, 0,   0,   0,   0,   0,   0,   0,   0,   256 },
      { 256, 0,   0,   0,   0,   0,   0,   0,   0,   256 },
      { 256, 0,   0,   0,   0,   0,   0,   0,   0,   256 },
      { 256, 0,   0,   0,   0,   0,   0,   0,   0,   256 },
      { 256, 0,   0,   0,   0,   0,   0,   0,   0,   256 },
      { 256, 0,   0,   0,   0,   0,   0,   0,   0,   256 },
      { 256, 0,   0,   0,   0,   0,   0,   0,   0,   256 },
      { 256, 0,   0,   0,   0,   0,   0,   0,   0,   256 },
      { 256, 0,   0,   0,   0,   0,   0,   0,   0,   256 },
      { 256, 0,   0,   0,   0,   0,   0,   0,   0,   256 },
      { 256, 0,   0,   0,   0,   0,   0,   0,   0,   256 },
      { 256, 256, 256, 256, 256, 256, 256, 256, 256, 256 }
    },
    m_flushed{ 0 },
    m_curShape( nullptr ),
    m_nextShape( new shape(rng::random()) ),
    m_curShapePos{ -1, -1 }
  { }

  grid::~grid( void ) {
    delete m_curShape;
    delete m_nextShape;
  }

  grid  &grid::roll( void ) {
    delete m_curShape;
    m_curShape = m_nextShape;
    m_nextShape = new shape(rng::random());
    m_curShapePos = vec2{ 0 };
    return *this;
  }

  grid  &grid::push( void ) {
    if (!m_curShape)
      throw NoShapeException();
    auto  data = m_curShape->get();
    bool  newShape = false;

    if (!m_curShapePos) {
      m_curShapePos = vec2{ 3, 1 };
      newShape = true;
    }
    for (auto i: range(0, 4)) {
      for (auto j: range(0, 4)) {
        if (data[i][j] && m_data[m_curShapePos.y + i + 1][m_curShapePos.x + j])
          throw VerticalCollisionEvent();
      }
    }
    if (!newShape) {
      for (auto i: range(0, 4)) {
        for (auto j: range(0, 4)) {
          if (data[i][j]) {
            if (i && !data[i - 1][j]) {
              m_data[m_curShapePos.y + i][m_curShapePos.x + j] = 0;
              m_flushed[m_curShapePos.y + i][m_curShapePos.x + j] = false;
            }
            if (m_data[m_curShapePos.y + i + 1][m_curShapePos.x + j] != data[i][j]) {
              m_data[m_curShapePos.y + i + 1][m_curShapePos.x + j] = data[i][j];
              m_flushed[m_curShapePos.y + i + 1][m_curShapePos.x + j] = false;
            }
          }
        }
      }
      m_curShapePos.y++;
    }
    return *this;
  }

  grid  &grid::rotate( void ) {
    if (!m_curShape)
      throw NoShapeException();
    m_curShape->rotate();
  }

  grid  &grid::draw( void ) {
    for (auto i: range(0, 18)) {
      for (auto j: range(0, 10)) {
        if (!m_flushed[i][j]) {
          tgotoxy(m_pos.x + j, m_pos.y + i);
          tsetbg(m_data[i][j]);
          write(1, "  ", 2);
        }
      }
    }
    treset();
    tgotoxy(0, 0);
    return *this;
  }

  grid  &grid::move( bool dir ) {
    if (!m_curShape)
      throw NoShapeException();
    auto data = m_curShape->get();

    if (dir == false) {
      for (auto i: range(0, 4)) {
        for (auto j: range(0, 4)) {
          if (j && data[i][j] && !data[i][j - 1]
          && m_data[m_curShapePos.y + i][m_curShapePos.x + j - 1])
            throw LatteralCollisionEvent();
        }
      }
      for (auto i: range(0, 4)) {
        for (auto j: range(0, 4)) {
          if (data[i][j]) {
            if (!j || !data[i][j - 1]) {
              m_data[m_curShapePos.y + i][m_curShapePos.x + j] = 0;
              m_flushed[m_curShapePos.y + i][m_curShapePos.x + j] = false;
            }
          } else if (j < 3 && data[i][j + 1]) {
            m_data[m_curShapePos.y + i][]
          }
        }
      }
    } else {
      for (auto i: range(0, 4)) {
        for (auto j: range(0, 4)) {
          if (j < 3 && data[i][j] && !data[i][j + 1]
          && m_data[m_curShapePos.y + i][m_curShapePos.x + j + 1])
            throw LatteralCollisionEvent();
        }
      }
    }
    return *this;
  }

}
