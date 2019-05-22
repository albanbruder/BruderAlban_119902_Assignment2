#include "heapsort.hpp"
#include <vector>
#include <iostream>

int main(int argc, char *argv[]) {
  std::vector<int> numbers(20);

  for(auto& num : numbers) {
    num = std::rand() % 100;
  }

  heapsort(
    std::begin(numbers), 
    std::end(numbers), 
    [](int l, int r) { return l < r; }
  );

  std::copy(std::cbegin(numbers), std::cend(numbers), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
  return 0;
}