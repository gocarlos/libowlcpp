/** @file "/owlcpp/lib/rdf/doc_info_store.cpp" 
part of owlcpp project.
@n @n Distributed under the Boost Software License, Version 1.0; see doc/license.txt.
@n Copyright Mikhail K Levin 2012
*******************************************************************************/
#ifndef OWLCPP_RDF_SOURCE
#define OWLCPP_RDF_SOURCE
#endif
#include "boost/assert.hpp"
#include "owlcpp/rdf/doc_info_store.hpp"
#include "owlcpp/terms/term_tags.hpp"

namespace owlcpp {

/*
*******************************************************************************/
Doc_store::id_type Doc_store::insert(std::string const& path, const Node_id iri, const Node_id ver) {
   path_index_t const& path_index = store_.get<path_tag>();
   path_iter_t path_iter = path_index.find(path);

   if( path_iter == path_index.end() ) {
      const id_type id = tracker_.get();
      BOOST_ASSERT(store_.get<id_tag>().find(id) == store_.get<id_tag>().end());
      store_.insert(entry_t(id, path, iri, ver));
      return id;
   }
   if( path_iter->iri_id_ != iri )
      BOOST_THROW_EXCEPTION(
            Err()
            << Err::msg_t("different IRI in same location")
            << Err::str1_t(path)
            << Err::int1_t(iri())
            << Err::int2_t(path_iter->iri_id_())
      );
   if( path_iter->version_id_ != ver )
      BOOST_THROW_EXCEPTION(
            Err()
            << Err::msg_t("different ontology version in same location")
            << Err::str1_t(path)
            << Err::int1_t(ver())
            << Err::int2_t(path_iter->version_id_())
      );

   return path_iter->id_;
}


}//namespace owlcpp
