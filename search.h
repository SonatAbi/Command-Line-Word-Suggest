#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <string>
#include <vector>

template <typename T> struct SearchResultType {
  SearchResultType(bool f,const T &v, long i) : found(f), value(v), index(i){};
  bool found;
  T value;
  long index;
};
//Template function for linear search algorythym
template <typename T>
SearchResultType<T> linear_search(const std::vector<T> &list, const T &value);
//Template function for iterative binary search algorythym
template <typename T>
SearchResultType<T> iterative_binary_search(const std::vector<T> &list, const T &value);
//Template function for resucrsive binary search algorythym
template <typename T>
SearchResultType<T> recursive_binary_search(const std::vector<T> &list, const T &value);
//Template helper function for recursive binary search algorythym
template <typename T>
SearchResultType<T> recursive_binary_search2(const std::vector<T> &list, long low, long high, const T &value);

#include "search.txx"

#endif // _SEARCH_H_
