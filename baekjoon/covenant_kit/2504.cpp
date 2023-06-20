// based problem:
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define MAX 100001

void init();
void input();
void solve();
int dfs(int);

string s = "";

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> s;
}

void solve()
{
    stack<char> stk;
    // 올바른 괄호열인지 검사
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(' || s[i] == '['){
            stk.push(s[i]);
        }
        else{
            if(s[i] == ')' && stk.top() == '(') stk.pop();
            else if(s[i] == ']' && stk.top() == '[') stk.pop();
            else{
                cout << 0;
                return;
            }  
        }
    }

    int answer = 0;
    int tmp = 1;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(') tmp *= 2;
        else if(s[i] == ')'){
            if(s[i-1] == '(') answer += tmp;
            tmp /= 2;
        }
        else if(s[i] == '[') tmp *= 3;
        else if(s[i] == ']'){
            if(s[i-1] == '[') answer += tmp;
            tmp /= 3;
        }
    }
    cout << answer;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}