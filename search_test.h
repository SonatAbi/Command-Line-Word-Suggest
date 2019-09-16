#include <string>
#include <vector>
#include <cxxtest/TestSuite.h>

#include "search.h"

class SearchTests : public CxxTest::TestSuite
{
public:
	void testlinearsearch( void ){
		std::vector<int> random(100);
		const int expV = 14;
		for (int i= 0; i < 100; i++) {
			random[i] = i;
		}
		SearchResultType<int> result = linear_search(random, expV);
		TS_ASSERT_EQUALS(result.found, true);
		TS_ASSERT_EQUALS(result.value, 14);
		TS_ASSERT_EQUALS(result.index, 14);
	}  
	void testlinearsearch1(void) {
		std::vector<int> random(100);
		const int expV = 16;
		for (int i = 0; i < 100; i++) {
			random[i] = i*4;
		}
		SearchResultType<int> result = linear_search(random, expV);
		TS_ASSERT_EQUALS(result.found, true);
		TS_ASSERT_EQUALS(result.value, 16);
		TS_ASSERT_EQUALS(result.index, 16);
	}
	void testlinearsearch2(void) {
		std::vector<int> random(100);
		const int expV = 120;
		for (int i = 0; i < 100; i++) {
			random[i] = i;
		}
		SearchResultType<int> result = linear_search(random, expV);
		TS_ASSERT_EQUALS(result.found, false);
		TS_ASSERT_EQUALS(result.value, 100);
		TS_ASSERT_EQUALS(result.index, 99);
	}


	void testiterativesearch( void ){
		std::vector<int> random(100);
		const int expV = 14;
		for (int i= 0; i < 100; i++) {
			random[i] = i;
		}
		SearchResultType<int> result = iterative_binary_search(random, expV);
		TS_ASSERT_EQUALS(result.found, true);
		TS_ASSERT_EQUALS(result.value, 14);
		TS_ASSERT_EQUALS(result.index, 14);
	} 
	void testiterativesearch1(void) {
		std::vector<int> random(100);
		const int expV = 16;
		for (int i = 0; i < 100; i++) {
			random[i] = i*4;
		}
		SearchResultType<int> result = iterative_binary_search(random, expV);
		TS_ASSERT_EQUALS(result.found, true);
		TS_ASSERT_EQUALS(result.value, 16);
		TS_ASSERT_EQUALS(result.index, 16);
	}
	void testiterativesearch2(void) {
		std::vector<int> random(100);
		const int expV = 120;
		for (int i = 0; i < 100; i++) {
			random[i] = i;
		}
		SearchResultType<int> result = iterative_binary_search(random, expV);
		TS_ASSERT_EQUALS(result.found, false);
		TS_ASSERT_EQUALS(result.value, 100);
		TS_ASSERT_EQUALS(result.index, 99);
	}
	void testrecursivesearch(void) {
	   std::vector<int> random(100);
	   const int expV = 14;
	   for (int i = 0; i < 100; i++) {
		   random[i] = i;
	   }
	   SearchResultType<int> result = recursive_binary_search(random, expV);
	   TS_ASSERT_EQUALS(result.found, true);
	   TS_ASSERT_EQUALS(result.value, 14);
	   TS_ASSERT_EQUALS(result.index, 14);
   }
	void testrecursivesearch1(void) {
		std::vector<int> random(100);
		const int expV = 16;
		for (int i = 0; i < 100; i++) {
			random[i] = i*4;
		}
		SearchResultType<int> result = recursive_binary_search(random, expV);
		TS_ASSERT_EQUALS(result.found, true);
		TS_ASSERT_EQUALS(result.value, 16);
		TS_ASSERT_EQUALS(result.index, 16);
	}
	void testrecursivesearch2(void) {
		std::vector<int> random(100);
		const int expV = 14;
		for (int i = 0; i < 100; i++) {
			random[i] = i*4;
		}
		SearchResultType<int> result = recursive_binary_search(random, expV);
		TS_ASSERT_EQUALS(result.found, false);
		TS_ASSERT_EQUALS(result.value, 12);
		TS_ASSERT_EQUALS(result.index, 3);
	}
};
