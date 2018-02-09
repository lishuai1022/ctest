#include "common.h"
#include <string.h>

typedef struct
{
    char string[100];
    int length;
} SString;

void getnext(SString T,int next[]){
    int i,j;
    next[0]=-1;//next[0]放上-1   
    i=0;//指向字符串每个字符的指针   
    j=-1;
    while(i<T.length){//没有到达结尾的话   
        if(j==-1||T.string[i]==T.string[j]){//如果是第一个字符或遇到相同的字符   
            i++;j++;next[i]=j;
        } 
        else  
            j=next[j];
    }
    for(i=0;i<T.length;i++){//输出next[]值   
        printf("%d ",next[i]);
    }
} 

int kmp(SString S,SString T,int next[]){
    int i,j;
    i=j=0;
    while(i<S.length&&j<T.length){
        if(j==-1||S.string[i]==T.string[j]){
            i++;j++;
        }
        else  
            j=next[j];
    }
    if(j==T.length) return i-T.length;
    else return -1;
}

int main(){
    SString S,T;
    int next[50];
    printf("please input string S:");
    scanf("%s",S.string);

    S.length = strlen(S.string);
    printf("please input string T:");
    scanf("%s",T.string);
    T.length = strlen(T.string);

    getnext(T,next);
    printf("\n%d\n",kmp(S,T,next));
}