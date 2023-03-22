// based problem:
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
#include <climits>

#define ll long long
#define MAX 100001

using namespace std;

void init();
void input();
void solve();

int t, n;
bool front;
bool error;
char FuncArr[MAX];
deque<int> dq;

void init()
{
    front = true;
    error = false;
    memset(FuncArr, 0, sizeof(FuncArr));
    dq.clear();
}

void input()
{
    char ch;
    int tmp;

    scanf("%s", FuncArr);
    getchar();
    scanf("%d", &n);
    getchar();

    // [
    getchar();
    // %d, %d, %d ... %d, ]

    while(1)
    {
        int check;
        check = scanf("%d", &tmp);
        printf("input is %d\n", tmp);
        printf("Check is %d\n", check);
        getchar();
        if(check == 1)
        {
            dq.push_back(tmp);
        }
        else break;
    }

    while ( (ch = getchar()) != '\n') ;
}

void solve()
{
    int siz = strlen(FuncArr);
    for(int i=0; i<siz; i++)
    {
        char ch = FuncArr[i];
        if(ch == 'R')
        {
            front = !front;
        }
        else if(ch == 'D')
        {
            if(!dq.empty())
            {
                front ? dq.pop_front() : dq.pop_back();
            }
            else
            {
                error = true;
                break;
            }
        }
    }

    if(error)
    {
        printf("error\n");
        return;
    }
    else
    {
        if(front)
        {
            int siz = dq.size();
            if(siz == 0) {printf("[]\n"); return;}
            putchar('[');
            for(int i=0; i<siz-1; i++)
            {
                printf("%d,", dq[i]);
            }
            printf("%d]", dq[siz-1]);
        }
        else
        {
            int siz = dq.size();
            if(siz == 0) {printf("[]\n"); return;}
            putchar('[');
            for(int i=siz-1; i>0; i--)
            {
                printf("%d,", dq[i]);
            }
            printf("%d]", dq[0]);
        }
    }
}

int main()
{
    scanf("%d", &t);
    getchar();
    for(int i=0; i<t; i++)
    {
        init();
        input();
        solve();
    }
    return 0;
}