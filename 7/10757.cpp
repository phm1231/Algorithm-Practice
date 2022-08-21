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
#include <cmath>

#define ll long long
#define MAX 10002
using namespace std;

void init();
void input();
void solve();

stack<char> stk;
char num_1[MAX];
char num_2[MAX];

void init()
{
    memset(num_1, 0, sizeof(num_1));
    memset(num_2, 0, sizeof(num_2));
}

void input()
{
    scanf("%s %s", num_1, num_2);
}

void solve()
{
    int len_1 = strlen(num_1);
    int len_2 = strlen(num_2);

    char* ptr_1 = num_1;
    char* ptr_2 = num_2;
    int longer = max(len_1, len_2);
    if(len_1 < len_2)
    {
        char* tmp = ptr_1;
        ptr_1 = ptr_2;
        ptr_2 = tmp;
    }
    int gap = abs(len_1 - len_2);
    int i;
    bool plus_one = false;

    for(i = longer - 1; i-gap >= 0; i--)
    {
        int result = (ptr_1[i] - '0') + (ptr_2[i-gap] - '0');
        if(plus_one)
        {
            plus_one = false;
            result++;
        }

        if(result >= 10)
        {
            plus_one = true;
            result -= 10;
            stk.push(char(result + '0'));
        }
        else
        {
            stk.push(char(result + '0'));
        }
    }

    for(int j=i; j>=0; j--)
    {
        int result = ptr_1[j] - '0';
        if(plus_one){
            plus_one = false;
            result++;
        }

        if(result >= 10)
        {
            plus_one = true;
            result -= 10;
            stk.push(char(result + '0'));
        }
        else{
            stk.push(char(result + '0'));
        }
    }
    
    if(plus_one){ printf("1"); }

    while(!stk.empty())
    {
        char out = stk.top();
        stk.pop();
        printf("%c", out);
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}