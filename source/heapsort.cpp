#include "heapsort.hpp"

#include <algorithm>

template<class Iterator>
void heapsort(Iterator first, Iterator last)
{
  while(first != last) {
    heapify(first, last);
    last--;
    std::iter_swap(first, last);
  }
}

template<class Iterator>
void heapify(Iterator first, Iterator last)
{
  std::make_heap(first, last);
}