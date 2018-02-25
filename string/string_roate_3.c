/*
    单词翻转
    输入一个英文句子，翻转句子中单词的顺序。要求单词内字符的顺序不变，
    句子中单词以空格符隔开。为简单起见，标点符号和普通字母一样处理。
    例如，若输入“I am a student.”，则输出“student. a am I”。

    该题的解法参考string_rotate_2.c的三步反转
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
    char s[100];
    int i = 0,j=0;
    scanf("%[^\n]",s); //为了输入带空格的字符串
    while(s[i] != '\0'){
        if(s[i] == ' '){
            ReverseString(s, j, i-1);
            j = i+1;
        }
        i++;
    }
    ReverseString(s, j, i-1);
    ReverseString(s, 0, i-1);
    printf("%s\n", s);
    return 0;
}