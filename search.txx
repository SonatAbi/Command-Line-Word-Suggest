#include "search.h"
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
SearchResultType<T> linear_search(const std::vector<T> &list, const T &value) {
	unsigned long i;
	for (i = 0; i < list.size()-1; i++) {
		if (value == list[i]) {
			return SearchResultType<T>(true, value, i);
		}
	}
	return SearchResultType<T>(false, list[i], i);
}

template <typename T>
SearchResultType<T> iterative_binary_search(const std::vector<T> &list,const T &value){
	long low = 0;
	long high = list.size() - 1;
	long mid;

	while (low <= high) {
		mid = low + (high - low) / 2;
		if (value < list[mid]) {
			high = mid - 1;
		}
		else if (value > list[mid]) {
			low = mid + 1;
		}
		else
			return SearchResultType<T>(true, list[mid], mid);
	}
	return SearchResultType<T>(false, list[mid], mid);
}

template <typename T>
SearchResultType<T> recursive_binary_search(const std::vector<T> &list,const T &value){
	long int low = 0;
	long int high = list.size() - 1;

	return recursive_binary_search2(list, low, high, value);
	
}

template <typename T>
SearchResultType<T> recursive_binary_search2(const std::vector<T> &list,long low,long high, const T &value) {
	high = high;
	low = low;
	long mid = low + (high - low) / 2;
	if (low > high) return SearchResultType<T>(false, list[low],low);

	if (value < list[mid]) {
		return recursive_binary_search2(list,low,mid-1, value);		
	}
	else if (value > list[mid]) {
		return recursive_binary_search2(list,mid+1,high, value);
	}
	else {
		return SearchResultType<T>(true, list[mid], mid);
	}

}