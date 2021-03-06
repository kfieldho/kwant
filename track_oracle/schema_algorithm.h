/*ckwg +5
 * Copyright 2012 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef INCL_SCHEMA_ALGORITHM_H
#define INCL_SCHEMA_ALGORITHM_H

//
// Various operations on schemas.
//

#include <string>
#include <vector>
#include <track_oracle/track_oracle_api_types.h>
#include <track_oracle/element_descriptor.h>

namespace vidtk
{

class track_base_impl;

namespace schema_algorithm
{

std::vector< element_descriptor > name_missing_fields( const track_base_impl& required_fields,
                                                      const track_handle_list_type tracks );

// what elements in the first (reference) schema are missing in the second (candidate) schema?
std::vector< element_descriptor > schema_compare( const track_base_impl& ref,
                                                 const track_base_impl& candidate );

} // schema_algorithm

} // vidtk

#endif
