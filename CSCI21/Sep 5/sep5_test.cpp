#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "sep5.h"


TEST_CASE("my first unit test") {
  CHECK(divide(1, 1) == 1);
  CHECK(divide(0, 1) == 0);
  CHECK(divide(1, 0) == 0);
  CHECK(divide(16, 2) == 8);
  CHECK(divide(5, 10) == 0);
}
