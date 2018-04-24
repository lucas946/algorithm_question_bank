#include<iostream>
#include<vector>

using namespace std;

void bubblesort(vector<int> &nums){
	for(int i=0;i<nums.size();++i)
		for(int j=i+1;j<nums.size();++j){
			if(nums[j]<nums[i])
				swap(nums[i],nums[j]);		
		}
}

int main(){
	int temp[] = {1,2,6,4,3};
	vector<int> nums(temp, temp+5);
	bubblesort(nums);
	for(int i=0;i<nums.size();++i)
		cout<<nums[i]<<" ";
	cout<<endl;
}
