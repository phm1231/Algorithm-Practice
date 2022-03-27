// based problem: 시간 초과
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
#include <climits>

#define ll long long
#define MAX 102

using namespace std;

void init();
void input();
int solve();

stack<char> stk;
vector<char> v;

void init()
{
    while(!stk.empty()) stk.pop();
    while(!v.empty()) v.pop_back();
}

void input()
{
    char ch;
    bool flag = true;
    while(1)
    {
        ch = getchar();
        v.push_back(ch);
        if (ch == '.') break;
    }
}

int solve()
{
    int siz = v.size();
    bool flag = true;
    for(int i=0; i < siz; i++)
    {
        char ch = v[i];
        if(i == 0 && ch == '.') return -1;
        
        if(ch == '.') break;
        if(ch == '(') stk.push(ch);
        if(ch == '[') stk.push(ch);
        if(ch == ')')
        {
            if(!stk.empty())
            {
                char ch_top = stk.top();
                if(ch_top == '(') stk.pop();
                else flag = false;
            }
            else flag = false;
        }
        if(ch == ']')
        {
            if(!stk.empty())
            {
                char ch_top = stk.top();
                if(ch_top == '[') stk.pop();
                else flag = false;
            }
            else flag = false;
        }
    }
    if(!stk.empty() || !flag) printf("no\n");
    else printf("yes\n");
    return 0;
}

int main()
{
    while(1)
    {
        init();
        input();
        int f = solve();
        if (f == -1 ) break;
    }
    return 0;
}