/* 直接插入排序
 * 直接插入排序是插入排序的一种，采用的方法是：在添加新的记录时，使用顺序查找的方式找到其要插入的位置，然后将
 * 新记录插入。
 */
#include<iostream>
#include<vector>

using namespace std;

void insert_sort(vector<int> *nums){
	for(int i=1;i<(*nums).size();++i){
		if((*nums)[i]<(*nums)[i-1]){
			int j = i-1;
			int tmp = (*nums)[i];
			while(j>-1 && tmp < (*nums)[j]){
				(*nums)[j+1] = (*nums)[j];
				--j;
			}
			(*nums)[j+1] = tmp;
		}
		
	}
}

int main(){
	int tmp[8] = {4,1,5,2,3,9,8,7};
	vector<int> nums(tmp,tmp+8);
	insert_sort(&nums);
	for(int i=0;i<nums.size();++i)
		cout<<nums[i]<<" ";
	cout<<endl;
	return 0;
}
