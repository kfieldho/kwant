/*ckwg +5
 * Copyright 2012-2014 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef INCL_ELEMENT_STORE_H
#define INCL_ELEMENT_STORE_H

///
/// the type-aware storage for the element.
///

#include <map>

#include <track_oracle/track_oracle_api_types.h>
#include <track_oracle/element_store_base.h>
#include <track_oracle/kwiver_io_base.h>


class TiXmlElement;

namespace vidtk
{

template< typename T >
class element_store: public element_store_base
{
public:
  explicit element_store( const element_descriptor& e );
  element_store( const element_descriptor& e, kwiver_io_base<T>* io_base );
  virtual ~element_store();
  void set_io_handler( kwiver_io_base<T>* io_base );
  kwiver_io_base<T>* get_io_handler() const;
  virtual bool exists( const track_handle_type& h ) const;
  virtual bool exists( const frame_handle_type& h ) const;
  virtual bool exists( const oracle_entry_handle_type& h ) const;

  virtual bool remove( const track_handle_type& h );
  virtual bool remove( const frame_handle_type& h );
  virtual bool remove( const oracle_entry_handle_type& h );

  virtual bool copy_value( const oracle_entry_handle_type& src, const oracle_entry_handle_type& dst );

  virtual std::ostream& emit_as_XML( std::ostream& os, const oracle_entry_handle_type& h ) const { return this->emit_as_XML_typed( os, h ); }
  std::ostream& default_xml_output( std::ostream& os, const oracle_entry_handle_type& h ) const;
  virtual std::ostream& emit_as_kwiver( std::ostream& os, const oracle_entry_handle_type& h, const std::string& indent ) const;
  virtual std::ostream& emit_as_csv( std::ostream& os, const oracle_entry_handle_type& h, bool emit_default_if_missing = false ) const;
  virtual bool read_kwiver_xml_to_row( const oracle_entry_handle_type& h, const TiXmlElement* e );
  virtual bool read_csv_to_row( const oracle_entry_handle_type& h, const std::map< std::string, std::string >& header_value_map );
  virtual std::vector<std::string> csv_headers() const;
  virtual void set_to_default_value( const oracle_entry_handle_type& h );

  std::map< oracle_entry_handle_type, T> storage;
  const T& get_default_value() const;
  void set_default_value( const T& val );

private:
  T* default_value_ptr;
  kwiver_io_base<T>* io_base_ptr;
  std::ostream& emit_as_XML_typed( std::ostream& os, const oracle_entry_handle_type& h ) const;
};


} // vidtk

#endif
