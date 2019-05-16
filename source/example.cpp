#include "heapsort.cpp"
#include <vector>
#include <iostream>

int main(int argc, char *argv[]) {
  std::vector<int> numbers{1,5,3,4,2,8,6,9,7};

  heapsort(numbers.begin(), numbers.end());

  std::for_each(numbers.begin(), numbers.end(), [](int n) {
    std::cout << n;
  });

  return 0;
}