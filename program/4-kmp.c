#include "common.h"
#include <string.h>

#ifndef MAXSTRLEN
#define MAXSTRLEN 255
#endif

typedef char SString[MAXSTRLEN+1];//0号单元存放串的长度（pascal语言），c语言不是这样的

//函数原型声明
int Index_KMP(SString S,SString T,int pos);
void get_next(SString T,int next[]);
void get_nextval(SString T,int next[]);
void format_SSting(SString T);

int next[6];

int main(int argc, char const *argv[])
{
    SString S = "ababcabcacbab";
    format_SSting(S);
    
    SString T = "abcac";
    format_SSting(T);
    
    // return 0;
    get_next(T,next);
    printf("%d\n",next[0]);
    printf("%d\n",next[1]);
    printf("%d\n",next[2]);
    printf("%d\n",next[3]);
    printf("%d\n",next[4]);
    printf("%d\n",next[5]);
    int pos = Index_KMP(S,T,1);
    printf("%d\n", pos);
    return 0;
} 

//为了维护和书本的下标一致，所有元素往右移动一个，0号单元不用
void format_SSting(SString S) {
    int s_len = strlen(S) - 1;
    for (int i = s_len-1; i >= 1; --i)
    {
        S[i+1] = S[i];
    }
    S[0] = '^';//第一个单元不用了，废弃
}

//利用模式串T的next函数，求T在主串S中第pos个字符之后的位置的KMP算法
int Index_KMP(SString S,SString T,int pos)
{
    int i = pos,j = 1;
    int s_len = strlen(S) - 1;
    int t_len = strlen(T) - 1;
    while(i <= s_len && j <= t_len) {
        if (j == 0 || S[i] == T[j])
        {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j > t_len)
    {
        return i - t_len;
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
    int t_len = strlen(T) - 1;
    while(i < t_len) {
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
    int t_len = strlen(T) - 1;
    while(i < t_len) {
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