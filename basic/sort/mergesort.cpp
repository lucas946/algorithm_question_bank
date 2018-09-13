/* 归并排序
 * 其基本思想是先将所有的记录完全分开，然后两两合并，在合并的
 * 过程中将其排好序，最终能够得到一个完整的有序表。
 * 该算法是采用分治法的一个非常典型的应用。
 * 
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(1)
 * 稳定性：稳定
 */
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void merge(vector<int> &nums, int low, int mid, int high){
	int p=0, q=0;
	vector<int> m,n;
	for(int i=low;i<=mid;++i)
		m.push_back(nums[i]);
	m.push_back(INT_MAX);
	for(int i=mid+1;i<=high;++i)
		n.push_back(nums[i]);
	n.push_back(INT_MAX);
	for(int i=low;i<high+1;++i){
		if(m[p]<n[q]){
			nums[i] = m[p];
			++p;
		}
		else{
			nums[i] = n[q];
			++q;
		}
	}

}

void mergesort(vector<int> &nums, int low, int high){
	if(low < high){
		int mid = low + (high-low)/2;
		mergesort(nums, low, mid);
		mergesort(nums, mid+1, high);
		merge(nums, low, mid, high);
	}
}

void msort(vector<int> &nums){
	mergesort(nums, 0, nums.size()-1);
}

int main(){
	int tmp[5] = {1,3,6,4,2};
	vector<int> nums(tmp, tmp+5);
	for(int i=0;i<nums.size();++i)
		cout<<nums[i]<<" ";
	cout<<endl;
	msort(nums);
	for(int i=0;i<nums.size();++i)
		cout<<nums[i]<<" ";
	cout<<endl;	
	return 0;
}
