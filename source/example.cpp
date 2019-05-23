#include "heapsort.hpp"
#include <vector>
#include <iostream>
#include <sstream>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  bool help_flag = false;
  bool quiet_flag = false;

  // parse arguments
  char c;
  while((c = getopt(argc, argv, "hq")) != -1) {
    switch(c) {
      case 'h':
        help_flag = true;
        break;
      case 'q':
        quiet_flag = true;
        break;
      default:
        abort();
    }
  }

  // if the user asked for help: output help message
  if(help_flag) {
    std::cout << "Usage: " << argv[0] << " [-h] [-q] [NUMBER NUMBER ...]" << "\n";
    return 0;
  }

  std::vector<float> numbers;

  // get numbers from arguments
  for (int i=1; i<argc; ++i) {
    if(argv[i][0] != '-') {
      numbers.push_back(std::atof(argv[i]));
    }
  }

  // if no numbers where passed: prompt the user
  if(numbers.size() == 0) {
    if(!quiet_flag) {
      std::cout << "Please the numbers you want to sort separated with spaces:" << "\n";
    }
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