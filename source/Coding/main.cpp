#include <vector>
#include <iostream>
#include "CommonStruct.h"

#include "question/FindStockBuySell.hpp"
#include "question/MajorityElement.hpp"
#include "question/LruCache.hpp"
#include "question/SpiralOrder.hpp"
#include "question/GenMatrix.hpp"
#include "question/ReverseBits.hpp"
#include "question/Pow.hpp"
#include "question/QuickSort.hpp"
#include "question/LengthOfLongestSubstring.hpp"
#include "question/ThreeSum.hpp"
#include "question/Trap.hpp"
#include "question/NextPermutation.hpp"
#include "question/ReorderList.hpp"
#include "question/MergeKLists.hpp"
#include "question/ReverseBetween.hpp"
#include "question/BuildTree.hpp"

using namespace std;

int main() {

	vector<int> preorder = { 3,9,20,15,7 };
	vector<int> inorder = { 9,3,15,20,7 };
	BuildTree buildTree ;
	TreeNode* tree = buildTree.buildTree(preorder, inorder);

	ListNode* l1 = new ListNode(0, 5);

	ReverseBetween::GetReverseRes(l1, 1, 1);

	ListNode* l2 = new ListNode(0, 7);
	vector<ListNode*> kLists = { l1, l2 };

	ListNode* kListRes = MergeKLists::GetResult(kLists);


	ReorderList::GetReorderList(l1);

	vector<int> nums1{1,2,3};
	NextPermutation::sortNextPermutation(nums1);

	vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	int ans = Trap::GetTrapResult(height);

	vector<int> nums = { -1,0,1,2,-1,-4 };
	auto res = ThreeSum::Sum(nums);

	string getMaxSubLength = "dvdf";
	int data = LengthOfLongestSubstring::GetMaxLength(getMaxSubLength);


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