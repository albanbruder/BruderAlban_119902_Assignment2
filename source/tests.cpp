#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <vector>
#include <array>
#include "heapsort.hpp"

TEST_CASE("sort int vector without compare function", "[heapsort]")
{
  std::vector<int> v{1,-5,6,3,10,-2,-8,21,109,2,1,222};
  buw::heapsort(std::begin(v), std::end(v));
  REQUIRE(std::is_sorted(std::cbegin(v), std::cend(v), std::less<int>()));
}

TEST_CASE("sort float vector with compare function", "[heapsort]")
{
  std::vector<float> v{8.3f, 1.0f, -3.33f, 2.2f, 101.101f, 200.0f, 89.0f, 32.4f, -44.34f};
  buw::heapsort(std::begin(v), std::end(v), [](float l, float r) {
    return l < r;
  });
  REQUIRE(std::is_sorted(std::cbegin(v), std::cend(v), std::less<float>()));
}

TEST_CASE("sort array of strings with compare functor", "[heapsort]")
{
  std::array<std::string, 3> a{"Foo", "Bar", "FooBar"};
  buw::heapsort(std::begin(a), std::end(a), std::less<std::string>());
  REQUIRE(std::is_sorted(std::cbegin(a), std::cend(a), std::less<std::string>()));
}

TEST_CASE("sort already sorted vector", "[heapsort]")
{
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  buw::heapsort(std::begin(v), std::end(v));
  REQUIRE(std::is_sorted(std::cbegin(v), std::cend(v), std::less<int>()));
}

TEST_CASE("sort reverse sorted vector", "[heapsort]")
{
  std::vector<int> v{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  buw::heapsort(std::begin(v), std::end(v));
  REQUIRE(std::is_sorted(std::cbegin(v), std::cend(v), std::less<int>()));
}

TEST_CASE("sort empty vector", "[heapsort]")
{
  std::vector<int> v;
  buw::heapsort(std::begin(v), std::end(v));
  REQUIRE(v.size() == 0);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
