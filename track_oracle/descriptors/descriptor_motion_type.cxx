/*ckwg +5
 * Copyright 2014 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#include "descriptor_motion_type.h"

using std::ostream;
using std::istream;
using std::ios;

ostream&
operator<<( ostream& os, const descriptor_motion_type& )
{
  os << "motion output TODO";
  return os;
}

istream&
operator>>( istream& is, descriptor_motion_type& )
{
  is.setstate( ios::failbit );
  return is;
}
