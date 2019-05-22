#ifndef BUW_HEAPSORT_HPP
#define BUW_HEAPSORT_HPP

#include <iterator>

namespace buw {

  template<typename Iterator, typename Compare>
  void heapify(Iterator first, Iterator last, Iterator parent, Compare comp)
  {
    Iterator left_child = parent + std::distance(first, parent);
    Iterator right_child = left_child + 1;
    
    if(left_child < last && comp(*parent, *left_child)) {
      std::iter_swap(parent, left_child);
      buw::heapify(first, last, left_child, comp);
    }

    if(right_child < last && comp(*parent, *right_child)) {
      std::iter_swap(parent, right_child);
      buw::heapify(first, last, right_child, comp);
    }
  }

  template<typename Iterator, typename Compare>
  void build_heap(Iterator first, Iterator last, Compare comp)
  {
    auto it = last - std::distance(first, last)/2;
    while(it != first-1) {
      buw::heapify(first, last, it, comp);
      it--;
    }
  }

  template<typename Iterator, typename Compare>
  void sort_heap(Iterator first, Iterator last, Compare comp) 
  {
    auto it = last-1;
    while(it != first-1) {
      std::iter_swap(first, it);
      buw::heapify(first, it, first, comp);
      it--;
    }
  }

  template<typename Iterator, typename Compare>
  void heapsort(Iterator first, Iterator last, Compare comp)
  {
    buw::build_heap(first, last, comp);
    buw::sort_heap(first, last, comp);
  }

  template<typename Iterator>
  void heapsort(Iterator first, Iterator last)
  {
    buw::heapsort(first, last, std::less<typename Iterator::value_type>());
  }
}

#endif