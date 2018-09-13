/* 直接插入排序
 * 直接插入排序是插入排序的一种，采用的方法是：在添加新的记录时，使用顺序查找的方式找到其要插入的位置，然后将
 * 新记录插入。
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 * 稳定性：稳定
 */
#include<iostream>
#include<vector>

using namespace std;

void insertsort(vector<int> &nums) {
    for(int i = 1; i < nums.size(); ++i) {
        if(nums[i] < nums[i-1]) {
            int j = i-1;
            int temp = nums[i];
            while(j>-1 && nums[j] > temp){
                nums[j+1] = nums[j];
                --j;
            }
            nums[j+1] = temp;
        }
    }
}

int main(){
	int tmp[8] = {4,1,5,2,3,9,8,7};
	vector<int> nums(tmp,tmp+8);
	insert_sort(nums);
	for(int i=0;i<nums.size();++i)
		cout<<nums[i]<<" ";
	cout<<endl;
	return 0;
}
