/*
    该方法的问题描述与string_rotate_1.c一致，
    不同的是该方法的时间复杂度为O(n)，空间复杂度不变

    这种方法把字符串先分为两个部分，各自反转，最后整体反转的方法，俗称三步反转法
*/

#include<stdio.h>

void ReverseString(char *s, int from, int to){
    while(from < to){
        char t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }
}

int main(){
    char *s;
    int n,m;
    scanf("%s", s);
    scanf("%d", &n);
    scanf("%d", &m);
    // 三步反转
    ReverseString(s,0,m-1);
    ReverseString(s,m,n-1);
    ReverseString(s,0,n-1);

    printf("%s\n", s);
    return 1;
}
