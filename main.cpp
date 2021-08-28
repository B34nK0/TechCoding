#include <vector>
#include <iostream>

#include "question/findStockBuySell.hpp"
#include "question/majorityElement.hpp"
#include "question/lruCache.hpp"
#include "question/spiralOrder.hpp"

using namespace std;

int main() {

	vector<int> stockPrices{1,3,4,2,7,8};

	
	cout << findStockBuySell::findResult(stockPrices) << endl;


	vector<int> stockPrices2{ 7,1,5,3,6,4 };
	cout << findStockBuySell::sumBuySell(stockPrices2) << endl;

	cout << findStockBuySell::sumBuySell2(stockPrices2) << endl;

	vector<int> numbers{ 2, 2, 1, 1, 1, 2, 2};
	cout << majorityElement::findElement(numbers) << endl;

	LruCache* cache = new LruCache(2);
	cache->Put(2, 2);
	cache->Put(1, 1);
	cout<< cache->Get(1) << endl;
	cache->Put(3, 3);
	cout << cache->Get(1) << endl;
	cout << cache->Get(2) << endl;
	cout << cache->Get(3) << endl;

	vector<vector<int>> matrix{ {1,2,3, 4}, {5, 6, 7,8}, {9,10,11,12} };
	vector<int> result = spiralOrder::getSpiralOrder(matrix);

	return 0;
}