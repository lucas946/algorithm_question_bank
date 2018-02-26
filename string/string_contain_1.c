/*
    给定一长字符串a和一短字符串b。请问，如何最快地判断出短字符串b中的所有字符是否都在
    长字符串a中？请编写函数bool StringContain(char *a,char *b)实现此功能。
*/

// 蛮力轮询，时间复杂度为O(mn)
#include<stdio.h>
#include<string.h>

int StringContain(char *a, char *b){
    int i,j;
    int n = strlen(b);
    int m = strlen(a);
    for(i=0; i < n;i++){
        for(j=0;(j<m)&&(a[j]!=b[i]);j++);
        if(j==(int)strlen(a)) return -1;
    }
    return 1;
}

int main(){
    char a[100], b[100];
    int flag;
    scanf("%s", a);
    scanf("%s", b);
    flag = StringContain(a,b);
    printf("%d\n", flag);
    return 0;
}