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
