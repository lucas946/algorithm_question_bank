/*
 writen by July from his book The method of Programming
 题目描述：
 给定一个字符串，要求将字符串前面的若干个字符移到字符串的尾部，
 例如将字符串“abcdef”的前3个字符a,b,c移到字符串的尾部，那么
 原字符串将变为"defabc"，请写一个函数实现此功能
*/

#include<stdio.h>

void LeftShiftOne(char *s, int n){
    //保存第一个字符
    char t = s[0];
    for(int i = 1;i<n;i++){
        s[i-1]=s[i];
    }
    s[n-1] = t;
}

int main(){
    char *s;
    int n,m;
    scanf("%s", s);
    scanf("%d", &n);
    scanf("%d", &m);
    while(m--){
        LeftShiftOne(s, n);
    }
    printf("%s\n", s);
    return 1;
}