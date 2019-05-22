#include "heapsort.hpp"
#include <vector>
#include <iostream>
#include <sstream>

int main(int argc, char *argv[]) {
  std::vector<float> numbers;

  if(argc > 1) {
    for (int i=1; i<argc; ++i) {
      numbers.push_back(std::atof(argv[i]));
    }
  } else {
    // read input from cin
    std::string input;
    std::getline(std::cin, input);
    std::istringstream inputStream(input);
    
    std::copy(std::istream_iterator<float>(inputStream),
      std::istream_iterator<float>(),
      std::back_inserter(numbers));
  }

  buw::heapsort(
    std::begin(numbers), 
    std::end(numbers), 
    [](float l, float r) { return l < r; }
  );

  std::copy(std::cbegin(numbers), std::cend(numbers), std::ostream_iterator<float>(std::cout, " "));
  return 0;
}