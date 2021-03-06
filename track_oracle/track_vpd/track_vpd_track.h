/*ckwg +5
 * Copyright 2013 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef INCL_TRACK_VPD_H
#define INCL_TRACK_VPD_H

#include <track_oracle/track_base.h>
#include <track_oracle/track_field.h>
#include <string>
#include <utility>
#include <vgl/vgl_box_2d.h>

namespace vidtk
{

/// This is the track_oracle schema for the VIRAT Public Data 2.0 object
/// tracks.

struct track_vpd_track_type: public track_base< track_vpd_track_type >
{
  track_field< unsigned >& object_id;
  track_field< unsigned >& object_type;
  track_field< unsigned >& frame_number;
  track_field< vgl_box_2d< double > >& bounding_box;

  track_vpd_track_type():
    object_id( Track.add_field< unsigned >( "object_id" )),
    object_type( Track.add_field< unsigned >( "object_type" )),
    frame_number( Frame.add_field< unsigned >( "frame_number" )),
    bounding_box( Frame.add_field< vgl_box_2d< double > >( "bounding_box" ))
  {}

  static std::string object_type_to_str( unsigned t );
  static unsigned str_to_object_type( const std::string& s );
};


} // namespace vidtk

#endif
