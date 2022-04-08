/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:54:44 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/04/08 17:25:34 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <string>
#include <cstdint>

namespace tetris {

  using std::uint8_t;

  class shape {
    public:
      shape( unsigned = 0 );
      shape( const shape& );

      shape &operator =( const shape& );

      const uint8_t *const  *get( void ) const;
      shape                 &rotate(void);


    private:

      int                   m_id;
      int                   m_rot;
      const uint8_t         *m_shape[4];
      static const uint8_t  m_data[112][5];
  };

}
