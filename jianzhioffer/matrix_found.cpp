/*剑指offer No.4
 *在一个二维数组中，每一行都按照从左到右递增的顺序排序，
 *每一列都按照从上到下递增的顺序进行排序。请完成一个函数，
 *输入这样的一个二维数组和一个整数，判断数组中是否含有该
 *整数。
 */
#include<iostream>
using namespace std;
bool matrix_found(int *matrix, int rows, int columns, int number){
	bool found = false;
	int row = 0, column = columns-1;
	while(row < rows && column >= 0){
		if(matrix[row*columns+column] == number){
			found = true;
			break;
		}
		else if(matrix[row*columns+column] > number)
			--column;
		else
			++row;
	}
	return found;	
}

int main(int argc, char *argv[]){
	int matrix[9]={1,2,3,4,5,6,7,8,9};
	bool found = matrix_found(matrix,3,3,10);
	cout<<found<<endl;
	return 0;
}
