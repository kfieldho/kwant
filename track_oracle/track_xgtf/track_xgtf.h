/*ckwg +5
 * Copyright 2011-2014 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef INCL_TRACK_XGTF_H
#define INCL_TRACK_XGTF_H

#include <track_oracle/track_base.h>
#include <track_oracle/track_field.h>

#include <vgl/vgl_box_2d.h>

#include <string>
#include <utility>

namespace vidtk
{

  /// This is the track_oracle schema for an XGTF track generated
  /// by the VIPER ground-truthing tool, used on e.g. VIRAT.
  /// The particular columns ("activity", "occlusion", etc.) are specific
  /// to MITRE's ground-truthing effort on VIRAT.

struct track_xgtf_type: public track_base< track_xgtf_type >
{

  //track level data
  track_field< unsigned >& external_id; //attribute id in phase one
  track_field< std::string >& type; // 'name' in phase one. could be pvo as well.
  track_field< std::pair< unsigned int, unsigned int > >& frame_span;

  //For activities, allowing string printed. Alternative is enum??
  track_field< int >& activity;
  track_field< double >& activity_probability;

  //frame level data
  track_field< vgl_box_2d< double > >& bounding_box;
  track_field< unsigned >& frame_number;
  track_field< double >& occlusion;

  track_xgtf_type():

    /// track-level data
    external_id( Track.add_field< unsigned >("external_id") ),
    type(Track.add_field< std::string >( "type") ),
    frame_span( Track.add_field< std::pair< unsigned int, unsigned int > >("frame_span") ),

    /// the index of the activity; in VIRAT, it corresponds to the indices
    /// found in aries_interface
    activity( Track.add_field< int >("activity") ),

    /// the probability of the activity; for ground-truth, it's fixed at 1.0
    activity_probability( Track.add_field< double >("activity_probability") ),

    /// frame-level data
    bounding_box( Frame.add_field< vgl_box_2d< double > >("bounding_box") ),
    frame_number( Frame.add_field< unsigned >("frame_number") ),
    occlusion( Frame.add_field< double >("occlusion") )
  {
  }
};

} //namespace vidtk
#endif