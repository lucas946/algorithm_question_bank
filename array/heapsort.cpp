#include<iostream>
#include<vector>


using namespace std;

void heap_build(vector<int> &nums, int root, int length){
	int lchild = root*2+1;
	if(lchild<length){
		int flag = lchild;
		int rchild = lchild+1;
		if(rchild<length){
			if(nums[rchild]>nums[lchild]){
				flag = rchild;
			}
		}
		if(nums[flag]>nums[root]){
			swap(nums[flag],nums[root]);
			heap_build(nums,flag,length);
		}
	}
}

void heap_sort(vector<int> &nums){
	for(int i=nums.size()/2-1;i>=0;--i)
		heap_build(nums,i, nums.size());
	for(int i=nums.size()-1;i>=0;--i){
		swap(nums[i],nums[0]);
		heap_build(nums,0,i);
	}
}

int main(){
	int temp[] = {1,5,3,2,7};
	vector<int> nums(temp, temp+5);
	heap_sort(nums);
	for(int i=0;i<nums.size();++i)
		cout<<nums[i]<<" ";
	cout<<endl;
	return 0;
}
