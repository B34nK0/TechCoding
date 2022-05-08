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
#include "test.h"
#include "question/MaxPathSum.hpp"
#include "question/NumIslands.hpp"
#include "question/FirstMissingPositive.hpp"
#include "question/MinStack.hpp"
#include "question/MinWindow.hpp"
#include "question/SortOddEvenList.hpp"
#include "question/MaxSubArray.hpp"
#include "question/FindPeakElement.hpp"
#include "question/BackToOrigin.hpp"
#include "DeferMacro.hpp"
#include "niuke/huawei.hpp"
#include "question/MyAtoi.hpp"
#include "question/LFUCache.hpp"
#include "interview/futu.hpp"
#include "interview/byteDance.hpp"
#include "practice/SPSCQueue.hpp"

using namespace std;

int main() {

	//����64λ�ڴ���뷽ʽ
	alignas(64) std::atomic<int> _readPos;//��������λ��

	alignas(64) std::atomic<int> _writePos;//������дλ��

	size_t tes = sizeof(_writePos);

	std::vector<double> _buffer;

	size_t vetTest = sizeof(_buffer);

	char _padding[64 - sizeof(_writePos)];

	clock_t startTime = clock();

	SPSCQueue<int>* spsc = new SPSCQueue<int>(10);

	int popAns = 0;
	spsc->push_back(1);
	spsc->pop_front(popAns);

	spsc->push_back(2);
	spsc->pop_front(popAns);

	spsc->push_back(3);
	spsc->pop_front(popAns);

	spsc->push_back(4);
	spsc->pop_front(popAns);

	spsc->push_back(5);
	spsc->pop_front(popAns);

	clock_t endTime = clock();


	cout << "����������ʱ��" << double(endTime - startTime) << endl;

	vector<int> orignNums = { 1, 2, 5, 2, -1, 3, 1, 2 };
	auto matchAns = FindMatchVector::GetVec(orignNums, 4);

	int yNum = RandY::GetRandNum();

	bool b = RepeatedSubstringPattern::CheckIsRepeated("abaaba");


	LFUCache lfuCache(1);
	lfuCache.Put(10, 10);
	lfuCache.Put(2, 20);
	int i = lfuCache.Get(10);

	MyAtoi myatoi;
	myatoi.AtoiConvert("  -42");

	bool te = HJTest3("aab", "c*a*b");

	HJTest2();

	HJTest1();

	HJ24();

	HJ18();

	int hj1count = HJ1();

	int hj2Count = HJ2();

	HJ3();

	int maxRes = Max(-1, 2);

	int step = BackToOrigin::GetNums(2);
	step = BackToOrigin::GetNums(3);
	step = BackToOrigin::GetNums(4);

	vector<long long> peakNums{ -2147483648 };
	int idx = FindPeakElement::GetRes(peakNums);

	MaxSubArray maxSubArray;
	vector<int> numsArr{ -2,1,-3,4,-1,2,1,-5,4 };
	maxSubArray.GetRes(numsArr);

	ListNode* oddEvenList = new ListNode(1);

	ListNode* currOddEvenHead = oddEvenList;

	currOddEvenHead->next = new ListNode(8);
	currOddEvenHead = currOddEvenHead->next;
	currOddEvenHead->next = new ListNode(3);
	currOddEvenHead = currOddEvenHead->next;
	currOddEvenHead->next = new ListNode(6);
	currOddEvenHead = currOddEvenHead->next;
	currOddEvenHead->next = new ListNode(5);
	currOddEvenHead = currOddEvenHead->next;
	currOddEvenHead->next = new ListNode(4);
	currOddEvenHead = currOddEvenHead->next;
	currOddEvenHead->next = new ListNode(7);
	currOddEvenHead = currOddEvenHead->next;
	currOddEvenHead->next = new ListNode(2);
	currOddEvenHead = currOddEvenHead->next;
	
	SortOddEvenList::Sort(oddEvenList);

	MinWindow minWindow;
	string adadf = minWindow.GetRes("a","a");

	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	minStack.getMin();
	minStack.pop();
	minStack.getMin();

	vector<int> orderedNums = { 1,2,0 };
	int missingPositive = FirstMissingPositive::GetNum(orderedNums);

	vector<vector<int>> islands = { {1,0,1,1,1} ,{1,0,1,0,1},{1,1,1,0,1} };
	int islandsNums = NumIslands::GetNumsOfIslands(islands);


	TreeNode* binaryTree = new TreeNode(1);
	binaryTree->left = new TreeNode(2);
	binaryTree->right = new TreeNode(3);

	int max = MaxPathSum::MaxSum(binaryTree);

	test t;
	t.TestMap();

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