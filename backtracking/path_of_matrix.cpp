/* 问题描述：
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 * 路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
 * 如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子
 * 
 * 示例输入：
 * a b t g
 * c f c s
 * j d e h
 * 字符串：
 * bfce
 * abfb
 * 输出：
 * true
 * false
 */
 
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

bool isFound(string &s, char *matrix, int row, int col, int &pos, int rows, int cols, bool *visited){
	if(pos == s.length())
		return true;
	bool result = false;
	if(row>=0 && col>=0 && row<rows && col<cols && matrix[row*cols+col] == s[pos] && !visited[row*cols+col]){
		visited[row*cols+col] = true;
		++pos;
		result = isFound(s, matrix, row-1, col, pos, rows, cols, visited) ||
			 isFound(s, matrix, row, col-1, pos, rows, cols, visited) ||
			 isFound(s, matrix, row+1, col, pos, rows, cols, visited) ||
                         isFound(s, matrix, row, col+1, pos, rows, cols, visited);
		if(!result){
			--pos;
			visited[row*cols+col] = false;
		}
	}
	return result;
		
}

bool hasPath(string &s, char *matrix, int rows, int cols){
	int pos = 0;
	bool *visited = new bool[rows*cols];
	memset(visited,0,sizeof(visited));
	for(int i=0;i<rows;++i)
		for(int j=0;j<cols;++j){
			if(isFound(s,matrix,i,j,pos,rows,cols,visited)){
				return true;
			}
		}
	delete []visited;
	return false;
}

int main(){
	int m = 3, n = 4;
	char matrix[]={'a','b','t','g','c','f','c','s','j','d','e','h'};
	string s="bfce";
	bool result = hasPath(s,matrix,m,n);
	cout<<result<<endl;
	
	return 0;
}
