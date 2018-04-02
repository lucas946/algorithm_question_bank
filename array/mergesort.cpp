/* 归并排序
 * 其基本思想是先将所有的记录完全分开，然后两两合并，在合并的
 * 过程中将其排好序，最终能够得到一个完整的有序表。
 * 该算法是采用分治法的一个非常典型的应用。
 */
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void merge(vector<int> *nums, vector<int>::iterator begin, vector<int>::iterator mid, vector<int>::iterator end){
	int p = 0,q = 0;
	vector<int> m, n;
	vector<int>::iterator i;
	for(i=begin;i<=mid;++i)
		m.push_back(*i);
	m.push_back(INT_MAX);
	for(i=mid+1;i<=end;++i)
		n.push_back(*i);
	n.push_back(INT_MAX);
	for(i=begin;i<=end;++i){
		if(m[p] <= n[q]){
			*i = m[p];
			++p;
		}
		else{
			*i = n[q];
			++q;
		}
	}
	
}

void mergesort(vector<int> *nums, vector<int>::iterator begin, vector<int>::iterator end){
	if(begin < end){
		vector<int>::iterator mid = begin + (end-begin)/2;
		mergesort(nums, begin, mid);
		mergesort(nums, mid+1, end);
		merge(nums, begin, mid, end);
	}
}

int main(){
	int tmp[5] = {1,3,6,4,2};
	vector<int> nums(tmp, tmp+5);
	for(int i=0;i<nums.size();++i)
		cout<<nums[i]<<" ";
	cout<<endl;
	mergesort(&nums,nums.begin(),nums.end()-1);
	for(int i=0;i<nums.size();++i)
		cout<<nums[i]<<" ";
	cout<<endl;	
	return 0;
}

