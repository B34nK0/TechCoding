#include <vector>
#include <iostream>

#include "question/findStockBuySell.hpp"
#include "question/majorityElement.hpp"
#include "question/lruCache.hpp"
#include "question/spiralOrder.hpp"
#include "question/genMatrix.hpp"

using namespace std;

int main() {

	vector<int> stockPrices{1,3,4,2,7,8};

	
	cout << FindStockBuySell::FindResult(stockPrices) << endl;


	vector<int> stockPrices2{ 7,1,5,3,6,4 };
	cout << FindStockBuySell::SumBuySell(stockPrices2) << endl;

	cout << FindStockBuySell::SumBuySell2(stockPrices2) << endl;

	vector<int> numbers{ 2, 2, 1, 1, 1, 2, 2};
	cout << MajorityElement::FindElement(numbers) << endl;

	LruCache* cache = new LruCache(2);
	cache->Put(2, 2);
	cache->Put(1, 1);
	cout<< cache->Get(1) << endl;
	cache->Put(3, 3);
	cout << cache->Get(1) << endl;
	cout << cache->Get(2) << endl;
	cout << cache->Get(3) << endl;

	vector<vector<int>> matrix{ {1,2,3, 4}, {5, 6, 7,8}, {9,10,11,12} };
	vector<int> result = SpiralOrder::GetSpiralOrder(matrix);

	auto aaa = GenMatrix::GenMatrixByN(3);

	return 0;
}