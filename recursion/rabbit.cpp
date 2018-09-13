/* 问题描述：
 * 13世纪意大利数学家斐波那契在他的《算盘书》中提出这样一个问题：
 * 有人想知道一年之内一对兔子可繁殖多少对，便筑了一道围墙把一对
 * 兔子关在里面。已知一对兔子每一个月可以生一对小兔子，而一对兔子
 * 出生后第3个月开始生小兔子，假如一年之内没有发生死亡，则一对兔子
 * 一年内能繁殖成多少对？
 */
#include<iostream>

using namespace std;

const int MONTH = 12;

int rabbit(int n){
	if(n == 0) return 2;
	else if(n == 1) return 4;
	else if(n == 2) return 6;
	else if(n == 3) return 8;
	else return rabbit(n-2)+rabbit(n-3)+rabbit(n-4);
}

int main(int argc, char *argv[]){
	int count;
	count = rabbit(MONTH);
	cout<<count<<endl;
	return 0;
}
