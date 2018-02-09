#include "common.h"

#ifndef MAXSTRLEN
#define MAXSTRLEN 255
#endif

typedef unsigned char SString[MAXSTRLEN+1];//0号单元存放串的长度

//函数原型声明
int Index_KMP(SString S,SString T,int pos);
void get_next(SString T,int next[]);
void get_nextval(SString T,int next[]);

int next[5];

int main(int argc, char const *argv[])
{
    SString S = "ababcabcacbab";
    SString T = "abcac";
    get_nextval(T,next);
    // printf("%d\n",next[0]);
    // printf("%d\n",next[1]);
    // printf("%d\n",next[2]);
    // printf("%d\n",next[3]);
    // printf("%d\n",next[4]);
    int pos = Index_KMP(S,T,1);
    printf("%d\n", pos);
    return 0;
} 
//利用模式串T的next函数，求T在主串S中第pos个字符之后的位置的KMP算法
int Index_KMP(SString S,SString T,int pos)
{
    int i = pos,j = 1;
    while(i <= S[0] && j <= T[0]) {
        if (j == 0 || S[i] == T[j])
        {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j > T[0])
    {
        return i-T[0];
    } else {
        return 0;
    }
}

//求模式串T的next函数值，并存入next数组
void get_next(SString T,int next[])
{
    int i = 1;
    next[1] = 0;
    int j = 0;
    while(i < T[0]) {
        if (j == 0 || T[i] == T[j])
        {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

//求模式串T的next函数修正值，并存入next数组
void get_nextval(SString T,int next[])
{
    int i = 1;
    next[1] = 0;
    int j = 0;
    while(i < T[0]) {
        if (j == 0 || T[i] == T[j])
        {
            ++i;
            ++j;
            //修正的代码
            if (T[i] != T[j])
            {
                next[i] = j;
            } else {
                next[i] = next[j];
            }
        } else {
            j = next[j];
        }
    }
}