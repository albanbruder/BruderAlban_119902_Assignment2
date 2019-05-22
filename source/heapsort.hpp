#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <iterator>

template<typename Iterator, typename Compare>
void heapify(Iterator first, Iterator last, Iterator parent, Compare comp)
{
  Iterator left_child = parent + std::distance(first, parent);
  Iterator right_child = left_child + 1;
  
  if(left_child < last && comp(*parent, *left_child)) {
    std::iter_swap(parent, left_child);
    heapify(first, last, left_child, comp);
  }

  if(right_child < last && comp(*parent, *right_child)) {
    std::iter_swap(parent, right_child);
    heapify(first, last, right_child, comp);
  }
}

template<typename Iterator, typename Compare>
void build_heap(Iterator first, Iterator last, Compare comp)
{
  auto it = last - std::distance(first, last)/2;
  while(it != first-1) {
    heapify(first, last, it, comp);
    it--;
  }
}

template<typename Iterator, typename Compare>
void sort_heap(Iterator first, Iterator last, Compare comp) 
{
  auto it = last-1;
  while(it != first-1) {
    std::iter_swap(first, it);
    heapify(first, it, first, comp);
    it--;
  }
}

template<typename Iterator, typename Compare>
void heapsort(Iterator first, Iterator last, Compare comp)
{
  build_heap(first, last, comp);
  sort_heap(first, last, comp);
}

#endif