/*ckwg +5
 * Copyright 2010-2014 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#include "track_oracle.h"
#include <track_oracle/element_descriptor.h>
#include <track_oracle/track_oracle_impl.h>

#include <boost/thread/mutex.hpp>


using std::ostream;
using std::string;
using std::vector;


namespace // anon
{
boost::mutex instance_lock;
};

namespace vidtk
{

track_oracle_impl&
track_oracle
::get_instance()
{
  if ( ! track_oracle::impl )
  {
    boost::unique_lock< boost::mutex > lock( instance_lock );
    if ( ! track_oracle::impl )
    {
      track_oracle::impl = new track_oracle_impl();
    }
  }
  return *track_oracle::impl;
}

field_handle_type
track_oracle
::lookup_by_name( const string& name )
{
  return track_oracle::get_instance().lookup_by_name( name );
}

element_descriptor
track_oracle
::get_element_descriptor( field_handle_type f )
{
  return track_oracle::get_instance().get_element_descriptor( f );
}

const element_store_base*
track_oracle
::get_element_store_base( field_handle_type f )
{
  return track_oracle::get_instance().get_element_store_base( f );
}

element_store_base*
track_oracle
::get_mutable_element_store_base( field_handle_type f )
{
  return track_oracle::get_instance().get_mutable_element_store_base( f );
}

bool
track_oracle
::field_has_row( oracle_entry_handle_type row, field_handle_type field )
{
  return track_oracle::get_instance().field_has_row( row, field );
}

vector< field_handle_type >
track_oracle
::fields_at_row( oracle_entry_handle_type row )
{
  return track_oracle::get_instance().fields_at_row( row );
}

oracle_entry_handle_type
track_oracle
::get_next_handle()
{
  return track_oracle::get_instance().get_next_handle();
}

handle_list_type
track_oracle
::get_domain( domain_handle_type domain )
{
  return track_oracle::get_instance().get_domain( domain );
}

domain_handle_type
track_oracle
::lookup_domain( const string& domain_name, bool create_if_not_found )
{
  return track_oracle::get_instance().lookup_domain( domain_name, create_if_not_found );
}

domain_handle_type
track_oracle
::create_domain()
{
  return track_oracle::get_instance().create_domain();
}

domain_handle_type
track_oracle
::create_domain( const handle_list_type& handles )
{
  return track_oracle::get_instance().create_domain( handles );
}

bool
track_oracle
::is_domain_defined( const domain_handle_type& domain )
{
  return track_oracle::get_instance().is_domain_defined( domain );
}

bool
track_oracle
::release_domain( const domain_handle_type& domain )
{
  return track_oracle::get_instance().release_domain( domain );
}

bool
track_oracle
::add_to_domain( const handle_list_type& handles, const domain_handle_type& domain )
{
  return track_oracle::get_instance().add_to_domain( handles, domain );
}

bool
track_oracle
::add_to_domain( const track_handle_type& track, const domain_handle_type& domain )
{
  return track_oracle::get_instance().add_to_domain( track, domain );
}

bool
track_oracle
::set_domain( const handle_list_type& handles, domain_handle_type domain )
{
  return track_oracle::get_instance().set_domain( handles, domain );
}

track_handle_list_type
track_oracle
::generic_to_track_handle_list( const handle_list_type& handles )
{
  track_handle_list_type ret;
  for (unsigned i=0; i<handles.size(); ++i)
  {
    ret.push_back( track_handle_type( handles[i] ));
  }
  return ret;
}

frame_handle_list_type
track_oracle
::generic_to_frame_handle_list( const handle_list_type& handles )
{
  frame_handle_list_type ret;
  for (unsigned i=0; i<handles.size(); ++i)
  {
    ret.push_back( frame_handle_type( handles[i] ));
  }
  return ret;
}

handle_list_type
track_oracle
::track_to_generic_handle_list( const track_handle_list_type& handles )
{
  handle_list_type ret;
  for (unsigned i=0; i<handles.size(); ++i)
  {
    ret.push_back( handles[i].row );
  }
  return ret;
}

handle_list_type
track_oracle
::frame_to_generic_handle_list( const frame_handle_list_type& handles )
{
  handle_list_type ret;
  for (unsigned i=0; i<handles.size(); ++i)
  {
    ret.push_back( handles[i].row );
  }
  return ret;
}

frame_handle_list_type
track_oracle
::get_frames( const track_handle_type& t )
{
  return track_oracle::get_instance().get_frames( t );
}

void
track_oracle
::set_frames( const track_handle_type& t, const frame_handle_list_type& f )
{
  track_oracle::get_instance().set_frames( t, f );
}

size_t
track_oracle
::get_n_frames( const track_handle_type& t )
{
  return track_oracle::get_instance().get_n_frames( t );
}

bool
track_oracle
::write_kwxml( ostream& os, const track_handle_list_type& tracks )
{
  return track_oracle::get_instance().write_kwxml( os, tracks );
}

bool
track_oracle
::clone_nonsystem_fields( const track_handle_type& src,
                          const track_handle_type& dst )
{
  return track_oracle::clone_nonsystem_fields( src.row, dst.row );
}

bool
track_oracle
::clone_nonsystem_fields( const frame_handle_type& src,
                          const frame_handle_type& dst )
{
  return track_oracle::clone_nonsystem_fields( src.row, dst.row );
}

bool
track_oracle
::clone_nonsystem_fields( const oracle_entry_handle_type& src,
                          const oracle_entry_handle_type& dst )
{
  return track_oracle::get_instance().clone_nonsystem_fields( src, dst );
}

bool
track_oracle
::write_kwiver( ostream& os, const track_handle_list_type& tracks )
{
  return track_oracle::get_instance().write_kwiver( os, tracks );
}


bool
track_oracle
::write_csv( ostream& os, const track_handle_list_type& tracks, bool csv_v1_semantics )
{
  return track_oracle::get_instance().write_csv( os, tracks, csv_v1_semantics );
}

csv_handler_map_type
track_oracle
::get_csv_handler_map( const vector< string >& headers )
{
  return track_oracle::get_instance().get_csv_handler_map( headers );
}

}; // namespace vidtk

