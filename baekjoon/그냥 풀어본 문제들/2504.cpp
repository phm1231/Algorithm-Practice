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
#include <map>
#include <unordered_map>
#include <set>

#define ll long long
#define MAX 100001
using namespace std;

void init();
void input();
void solve();

stack<char> stk;
string str;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> str;
}

void solve()
{
    int answer = 0;
    int tmp = 1;
    for(int i=0; i<str.size(); i++){
        char ch = str[i];
        if(ch == '('){
            tmp *= 2;
            stk.push(ch);
        }
        else if(ch == ')'){
            if(stk.empty() || stk.top() != '('){
                answer = 0;
                break;
            }
            else if(str[i-1] == '('){
                answer += tmp;
                tmp /= 2;
                stk.pop();
            }
            else{
                tmp /= 2;
                stk.pop();
            }

        }
        else if(ch == '['){
            tmp *= 3;
            stk.push(ch);
        }
        else if(ch == ']'){
            if(stk.empty() || stk.top() != '['){
                answer = 0;
                break;
            }
            else if(str[i-1] == '['){
                answer += tmp;
                tmp /= 3;
                stk.pop();
            }
            else{
                tmp /= 3;
                stk.pop();
            }
        }
    }

    if(!stk.empty()) answer = 0;
    cout << answer;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}