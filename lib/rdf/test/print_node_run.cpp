/** @file "/owlcpp/lib/rdf/test/print_node_run.cpp" 
part of owlcpp project.
@n @n Distributed under the Boost Software License, Version 1.0; see doc/license.txt.
@n Copyright Mikhail K Levin 2012
*******************************************************************************/
#define BOOST_TEST_MODULE print_node_run
#include <iostream>
#include "boost/test/unit_test.hpp"
#include "test/exception_fixture.hpp"
#include "owlcpp/terms/node_tags_owl.hpp"
#include "owlcpp/rdf/triple_store.hpp"
#include "owlcpp/rdf/print_node.hpp"

namespace owlcpp{ namespace test{

BOOST_GLOBAL_FIXTURE( Exception_fixture );

namespace t = owlcpp::terms;

/** Print nodes without triple store
*******************************************************************************/
BOOST_AUTO_TEST_CASE( case01 ) {
   const Node_iri niri(Ns_id(42), "blah");
   BOOST_CHECK_EQUAL(to_string(niri), "Ns42:blah");
   Node const& riri = niri;
   BOOST_CHECK_EQUAL(to_string(riri), "Ns42:blah");

   const Node_blank nb(5, Doc_id(42));
   BOOST_CHECK_EQUAL(to_string(nb), "_:Doc42-5");
   Node const& rb = nb;
   BOOST_CHECK_EQUAL(to_string(rb), "_:Doc42-5");

   const Node_bool nbo1(1, t::T_xsd_boolean::id());
   BOOST_CHECK( nbo1.value() );
   BOOST_CHECK_EQUAL(to_string(nbo1), "true");
   Node const& rbo1 = nbo1;
   BOOST_CHECK_EQUAL(to_string(rbo1), "true");

   const Node_bool nbo2("false");
   BOOST_CHECK( ! nbo2.value() );
   BOOST_CHECK_EQUAL(to_string(nbo2), "false");
   Node const& rbo2 = nbo2;
   BOOST_CHECK_EQUAL(to_string(rbo2), "false");

   const Node_string ns("blah");
   BOOST_CHECK_EQUAL(to_string(ns), "\"blah\"");
   Node const& rs = ns;
   BOOST_CHECK_EQUAL(to_string(rs), "\"blah\"");

   const Node_int ni("-1");
   BOOST_CHECK_EQUAL(to_string(ni), "\"-1\"");
   Node const& ri = ni;
   BOOST_CHECK_EQUAL(to_string(ri), "\"-1\"");

   const Node_unsigned nu("-1");
   BOOST_CHECK_EQUAL(to_string(nu), "\"-1\"");
   Node const& ru = nu;
   BOOST_CHECK_EQUAL(to_string(ru), "\"-1\"");
}

}//namespace test
}//namespace owlcpp
