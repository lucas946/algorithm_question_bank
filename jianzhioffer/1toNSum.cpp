/*
求1+2+...+n;
要求不能使用乘除法、for、while、if、else、switch、case等关键字以及条件判断语句（A?B:C）。
*/
int Sum(int n) {
    int ret = 0;
    n == 0 || (ret = Sum(n-1))
    return ret + n;
}