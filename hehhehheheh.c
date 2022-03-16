#include<stdio.h>
void reverse(char *begin,char* end)
{
    char t;
    while(begin<end){
        t=*begin;
        *begin++=*end;
        *end--= t;
    }
}
void reverse_Word(char *s)
{
    char* begin =s;
    char* t=s;
    while(*t){
        t++;
        if(*t=='\0'){
            reverse(begin,t-1);
        }
        else if(*t==' '){
            reverse(begin,t-1);
            begin=t+1;
        }
    }
    reverse(s,t-1);
}
int main()
{
    char s[1000];
    scanf("%[^\n]",&s);
    reverse_Word(s);
    printf("%s",s);
    return 0;
}