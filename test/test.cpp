#define BOOST_TEST_MODULE test

#include <boost/test/unit_test.hpp>

#include "add.hpp"

BOOST_AUTO_TEST_CASE(test_add)
{
    BOOST_CHECK(add(1, 2) == 3);
}