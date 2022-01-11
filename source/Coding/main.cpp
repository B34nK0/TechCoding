#include <vector>
#include <iostream>

#include "question/FindStockBuySell.hpp"
#include "question/MajorityElement.hpp"
#include "question/LruCache.hpp"
#include "question/SpiralOrder.hpp"
#include "question/GenMatrix.hpp"
#include "question/ReverseBits.hpp"
#include "question/Pow.hpp"
#include "question/QuickSort.hpp"

using namespace std;

int main() {


	vector<int> quickSort{ 2 - 1, 2, -8, -10 };
	QuickSort::Sort(quickSort);


	double powRes = Pow::CalculatePow(7.0, 5);

	uint32_t orgNum = 123456;
	uint32_t num = ReverseBits::Reverse(orgNum);

	vector<int> stockPrices{3,3,5,0,0,3,1,4};

	
	cout << FindStockBuySell::MaxProfit(stockPrices);

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