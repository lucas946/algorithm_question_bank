#include<iostream>

using namespace std;

void heap_build(int a[], int root, int length){
	int lchild = root*2+1;
	if(lchild<length){
		int flag = lchild;//flag保存左右节点中最大值的下标
		int rchild = lchild + 1;
		if(rchild < length){
			if(a[rchild]>a[flag]){
				flag = rchild;
			}
		}
		if(a[root]<a[flag]){
			swap(a[root], a[flag]);
			heap_build(a, flag, length); //重新调整堆结构
		}
	}
}

void heap_sort(int a[], int length){
	for(int i=length/2-1; i>=0; --i){ //从最后一个非叶子节点开始建堆
		heap_build(a, i, length);
	}
	for(int j=length-1; j>0; --j){ //将堆顶元素逐个置为数组末尾
		swap(a[0], a[j]);
		heap_build(a, 0, j);
	}
}

int main(){
	int a[5] = {4,6,8,5,9};
	heap_sort(a, 5);
	for(int i=0;i<5;++i)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
