#
# example using the track oracle
#

add_executable( track_oracle_example track_oracle_example.cxx )
target_link_libraries( track_oracle_example track_oracle track_oracle_file_formats data_terms ${Boost_SYSTEM_LIBRARY} )

#
# example track reader
#

add_executable( track_reader_example track_reader_example.cxx )
target_link_libraries( track_reader_example track_oracle data_terms track_oracle_file_formats ${Boost_SYSTEM_LIBRARY} )

#
# example track writer
#

add_executable( track_writer_example track_writer_example.cxx )
target_link_libraries( track_writer_example track_oracle track_oracle_file_formats )

#
# example track schema introspection
#

add_executable( track_format_example track_format_example.cxx)
target_link_libraries( track_format_example track_oracle track_oracle_file_formats )

#
# example user-specified field manipulation
#

add_executable( runtime_field_query_example runtime_field_query_example.cxx )
target_link_libraries( runtime_field_query_example track_oracle track_oracle_file_formats )


#
# test the xml tokenizer
#

add_executable( xml_tokenizer_example xml_tokenizer_example.cxx )
target_link_libraries( xml_tokenizer_example vidtk_logger track_oracle_tokenizers )
