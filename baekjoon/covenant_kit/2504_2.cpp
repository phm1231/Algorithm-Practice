// based problem:
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
bool check();

string str;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> str;
}

void solve()
{
    ll answer = 0;
    if(check()){
        int weight = 1;
        for(int i=0; i<str.size(); i++){
            if(str[i] == '(') weight *= 2;
            else if(str[i] == '[') weight *= 3;
            
            else if(str[i] == ')'){
                if(str[i-1] == '(') answer += weight;
                weight /= 2;
            }
            else if(str[i] == ']'){
                if(str[i-1] == '[') answer += weight;
                weight /= 3;
            }
        }
        cout << answer;
    }
    else cout << 0;
}

// 올바른 괄호열인가?
bool check(){
    stack<char> stk;
    for(int i=0; i<str.size(); i++){
        if(str[i] == ')'){
            if(stk.empty() || stk.top() != '(') return false;
            stk.pop();
        }
        else if(str[i] == ']'){
            if(stk.empty() || stk.top() != '[') return false;
            stk.pop();
        }
        else{
            stk.push(str[i]);
        }
    }
    if(!stk.empty()) return false;

    return true;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}