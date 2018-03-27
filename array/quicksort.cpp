/*快速排序
 * 输入：N个整数
 * 输出：排序好的N个整数
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int partition(vector<int> &vi,int low, int high){
	int pivot = vi[high];
	int i = low-1;
	for(int j=low;j<high;++j){
		if(vi[j]<=pivot){
			i++;
			swap(vi[i],vi[j]);
		}
	}
	swap(vi[i+1],vi[high]);
	return i+1;
}

void quicksort(vector<int> &vi,int low, int high){
	if(low<high){
		int mid = partition(vi,low,high);
		quicksort(vi,low,mid-1);
		quicksort(vi,mid+1,high);
	}	
}

void qsort(vector<int> &vi){
	quicksort(vi,0,vi.size()-1);
}

void print_vector(vector<int> &vi){
	for(int i=0;i<vi.size();++i)
		cout<<vi[i]<<" ";
	cout<<endl;	
}

int main(){
	vector<int> numbers;
	char ch;
	int temp;
	while(cin>>temp){
		ch = getchar();
		numbers.push_back(temp);
		if(ch == '\n') break;
	}
	print_vector(numbers);
	qsort(numbers);
	print_vector(numbers);
}
