/* 约瑟夫问题
 * 有n只猴子，按顺时针方向围成一圈选大王（编号1～n），从第1只开始
 * 报数，一直数到m，数到m的猴子退到圈外，剩下的猴子再接着从1开始
 * 报数。就这样，直到圈内只剩下一只猴子时，这个猴子就是猴王。
 * 编程输入n，m后，输出最后猴王的编号。
 * 输入数据：
 * 	每行是用空格分开的两个整数，第一个是n，第2个是m（0<m，n<=1000000）。
 * 	最后一行是：
 * 	0 0
 * 输出要求：
 * 	对于每行输入数据（最后一行除外），输出数据也是一行，即最后的猴王
 * 	编号。
 */
#include<iostream>
#include<list>

using namespace std;

int main(){
	list<int> monkeys;
	int n,m;
	while(true){
		cin>>n>>m;
		if(n == 0 || m == 0) 
			break;
		if(!monkeys.empty())
			monkeys.clear();
		for(int i=1;i<=n;++i)
			monkeys.push_back(i);
		list<int>::iterator it = monkeys.begin();
		while(monkeys.size()>1){
			for(int j=1;j<m;++j){
				++it;
				if(it == monkeys.end())
					it = monkeys.begin();
			}
			it = monkeys.erase(it);
			if(it == monkeys.end())
				it = monkeys.begin();
		}
		cout<<monkeys.front()<<endl;
	}
	return 0;
}
