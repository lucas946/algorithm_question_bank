/* 问题描述：
 * 二分查找
 *
 * 适应范围：
 * 有序数组（链表不可以使用）
 *
 * 时间复杂度：O(logn)
 */

#include<iostream>
#include<vector>

using namespace std;

//递归实现
int binary_search(const vector<int> &nums, int low, int high, int target){
	if(low>high)
		return -1;
	int mid = (low+high)/2;
	if(nums[mid]>target){
		return binary_search(nums, low, mid-1, target);
	}
	else if(nums[mid]<target){
		return binary_search(nums, mid+1, high, target);
	}

	return mid;
}

// 非递归实现
/* 所有的递归都可以自行定义stack来解递归，所以二分查找法也可以不用递归实现，
 * 而且它的非递归实现甚至可以不用栈，因为二分的递归其实是尾递归，它不关心递
 * 归前的所有信息。
 */

/*
int binary_search(const vector<int> &nums, int low, int high, int target){
	while(low<=high){
		int mid = (low+high)/2;
		if(nums[mid]>target)
			high = mid - 1;
		else if(nums[mid]<target){
			low = mid +1;
		else
			return mid;
	}
	return -1;
}
*/

int bsearch(const vector<int> &nums, int target){
	int size = nums.size();
	return binary_search(nums, 0, size-1, target);
}

int main(){
	int tmp[]={1,2,3,4,5,6,7};
	vector<int> nums(tmp,tmp+7);
	int target = 5;
	int result = bsearch(nums, target);
	cout<<result<<endl;
	return 0;
}

