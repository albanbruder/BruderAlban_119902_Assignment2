#include "heapsort.hpp"
#include <vector>
#include <iostream>
#include <sstream>

int main(int argc, char *argv[]) {
  std::vector<float> numbers;

  // get numbers from arguments (if there are any)
  if(argc > 1) {
    for (int i=1; i<argc; ++i) {
      numbers.push_back(std::atof(argv[i]));
    }

  // or wait for user input
  } else {
    // read one line from std::cin
    std::string input;
    std::getline(std::cin, input);

    // parse floats from string
    std::istringstream inputStream(input);
    std::copy(std::istream_iterator<float>(inputStream),
      std::istream_iterator<float>(),
      std::back_inserter(numbers));
  }

  // sort with heapsort.hpp
  buw::heapsort(
    std::begin(numbers), 
    std::end(numbers), 
    [](float l, float r) { return l < r; }
  );

  // output sorted vector
  std::copy(std::cbegin(numbers), std::cend(numbers), std::ostream_iterator<float>(std::cout, " "));
  return 0;
}