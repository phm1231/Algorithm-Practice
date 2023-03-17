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
#define MAX 1000001
using namespace std;

void init();
void input();
void solve();

int n;
stack<int> stk;
stack<int> out_stk;
stack<int> res_stk;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int input;
        cin >> input;
        stk.push(input);
    }
}

void solve()
{
    while(!stk.empty())
    {
        int value = stk.top();
        stk.pop();

        if(out_stk.empty())
        {
            out_stk.push(value);
            res_stk.push(-1);
        }
        else
        {
            int out_value = out_stk.top();
            if(value < out_value) // NGE를 찾음
            {
                out_stk.push(value);
                res_stk.push(out_value);
            }
            else // 찾지 못함
            {
                while(!out_stk.empty())
                {
                    int next_out_value = out_stk.top();
                    if(value < next_out_value) // 찾음
                    {
                        out_stk.push(value);
                        res_stk.push(next_out_value);
                        break;
                    }
                    else
                    {
                        out_stk.pop();
                    }
                }
                if(out_stk.empty())
                {
                    out_stk.push(value);
                    res_stk.push(-1);
                }
            }
        }
    }

    while(!res_stk.empty())
    {
        int out = res_stk.top();
        cout << out << ' ';
        res_stk.pop();
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}