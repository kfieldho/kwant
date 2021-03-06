/*ckwg +5
 * Copyright 2014 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef INCL_AOI_UTILS_H
#define INCL_AOI_UTILS_H

///
/// Track oracle's AOI class.  Can be either pixel or lat/lon.
/// See help_text() for the format of the construction string.
///
/// ***
/// *** THIS CLASS WILL THROW an aoi_exception if the format string
/// *** is incorrect!  Also if the lat/lon AOI doesn't fit in a single
/// *** MGRS zone.
/// ***
///

#include <string>
#include <stdexcept>

namespace vidtk
{

namespace aoi_utils
{

struct aoi_impl;

class aoi_t
{
public:
  enum flavor_t { INVALID, PIXEL, GEO };

  aoi_t();
  explicit aoi_t( const std::string& s );   // can throw!
  void set( const std::string& s );       // can throw!
  virtual ~aoi_t();

  flavor_t flavor() const;
  bool in_aoi( double x, double y) const;

  std::string to_str() const;

  static std::string help_text();

private:
  aoi_impl* p;
};

class aoi_exception: public std::runtime_error
{
public:
  explicit aoi_exception( const std::string& s ): std::runtime_error( s ) {}
};

} // aoi_utils
} // vidtk


#endif
