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

