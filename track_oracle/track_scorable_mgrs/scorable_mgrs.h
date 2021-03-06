/*ckwg +5
 * Copyright 2012-2015 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef INCL_SCORABLE_MGRS_H
#define INCL_SCORABLE_MGRS_H

///
/// When computing radial intersection, we'll do so using MGRS
/// coordinates: zone, northing, easting, and their alternates.  (My
/// understanding, although I haven't seen it stated this bluntly,
/// is that the northing/easting are only comparable when the zones
/// match; if the zones don't match, look to the alternate zones (used
/// when a world point falls in an overlap region.)  If the zones
/// just won't line up, the distance is essentially infinite.
///
///

#include <iostream>
#include <vector>
#include <geographic/geo_coords.h>

namespace vidtk
{

struct scorable_mgrs
{
  bool valid;

  enum { DEFAULT_ZONE=0, ZONE_BEGIN = DEFAULT_ZONE, ALT_ZONE=1, N_ZONES=2 }; // indices into the zone / northing / easting arrays
  int zone[2];
  bool entry_valid[2];
  double northing[2];
  double easting[2];

  static double INF_DISTANCE;
  static double diff( const scorable_mgrs& pos1, const scorable_mgrs& pos2 );
  static double diff( const scorable_mgrs& pos1, const scorable_mgrs& pos2, const std::vector<int>& zone_map );
  scorable_mgrs():
    valid(false)
  {}
  explicit scorable_mgrs( const geographic::geo_coords& g );

  bool operator==( const scorable_mgrs& other ) const;

  // align the zones of this object against the other scorable_mgrs.
  // Returns a vector of N_ZONES values, in zone enum order, whose
  // values are themselves zone enums, such that if v[] is the
  // return value, and v[i] = j, then this object's zone[i] equals
  // the other object's zone[j].  Some examples:
  //
  // this.zone[] = [12, 19] ; other.zone[] = [12, 19]; ret = [DEFAULT_ZONE, ALT_ZONE]
  //
  // this.zone[] = [12, 19] ; other.zone[] = [19, 12]; ret = [ALT_ZONE, DEFAULT_ZONE]
  //
  // this.zone[] = [12, 19] ; other.zone[] = [12, 13]; ret = [DEFAULT_ZONE, N_ZONES]
  //
  // this.zone[] = [19, 13] ; other.zone[] = [12, 13]; ret = [N_ZONES, ALT_ZONE]
  //
  // this.zone[] = [19, 13] ; other.zone[] = [13, 12]; ret = [N_ZONES, DEFAULT_ZONE]
  //
  // this.zone[] = [12, 13] ; other.zone[] = [14, 15]; ret = [N_ZONES, N_ZONES]
  //
  std::vector< int > align_zones( const scorable_mgrs& other ) const;

  void mark_zone_invalid( size_t z );

  int find_zone( int z ) const;

};

std::ostream& operator<<( std::ostream& os, const scorable_mgrs& m );
std::istream& operator>>( std::istream& os, scorable_mgrs& m );

} // ...vidtk

#endif
