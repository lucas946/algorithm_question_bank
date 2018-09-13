#include <iostream>
#include <vector>

using namespace std;

void heap_build(vector<int> &nums, int root, int len) {
    int lchild = 2 * root + 1;
    if(lchild < len) {
        int flag = lchild;
        int rchild = lchild + 1;
        if(rchild < len){
            if(nums[rchild] > nums[lchild]) {
                flag = rchild;
            }
        }
        if(nums[root] < nums[flag]) {
            swap(nums[root], nums[flag]);
            heap_build(nums, flag, len);
        }
    }
}

void heap_sort(vector<int> &nums) {
    int len = nums.size();
    for(int i = len/2-1 ; i >= 0; --i){ //从最后一个非叶子节点开始建堆
        heap_build(nums, i, len);
    }
    for(int i = len-1; i >= 0; --i) {
        swap(nums[0], nums[i]);
        heap_build(nums, 0, i);
    }
}

int main(){
	int tmp[] = {1,6,3,4,2};
	vector<int> nums(tmp, tmp+5);
	heap_sort(nums);
	for(int i=0;i<nums.size();++i)
		cout<<nums[i]<<" ";
	cout<<endl;
	return 0;
}