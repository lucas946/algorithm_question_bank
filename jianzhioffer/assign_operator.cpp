/* 赋值运算符函数的使用
 * 剑指offer第一题
 */

#include<iostream>

using namespace std;

class Mystring{
public:
	Mystring(char *pData=nullptr);
	Mystring(const Mystring& str);
	~Mystring(void);
	//注意赋值运算符函数的参数和返回值
	Mystring & operator=(const Mystring& str);
private:
	char *m_pData;
};

Mystring::Mystring(char *pData){
	if(pData == nullptr){
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else{
		int length = strlen(pData);
		m_pData = new char[length+1];
		strcpy(m_pData, pData);
	}	
	cout<<"constructor"<<endl;
}

Mystring::Mystring(const Mystring& str){
	int length = strlen(str.m_pData);
	m_pData = new char[length+1];
	strcpy(m_pData, str.m_pData);
	cout<<"copy constructor"<<endl;
}

Mystring::~Mystring(){
	delete []m_pData;
}

Mystring &Mystring::operator=(const Mystring& str){
	//如果赋值的自身对象引用，则返回自身
	if(this == &str)
		return *this;
	delete []m_pData;
	m_pData = nullptr;
	int length = strlen(str.m_pData);
	m_pData = new char[length+1];
	strcpy(m_pData, str.m_pData);
	
	cout<<"assign"<<endl;
	return *this;
}

int main(int argc, char *argv[]){
	Mystring s1;
	Mystring s2("Hello");
	Mystring s3=s2; //调用拷贝构造函数
        s1 = s3;//调用赋值运算符函数
	return 0;
}
