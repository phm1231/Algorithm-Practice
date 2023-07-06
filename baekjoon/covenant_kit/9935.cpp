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

string str, boom;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> str >> boom;
}

void solve()
{
    stack<char> stk;
    int endIdx = boom.size() - 1;

    for(int i=0; i<str.size(); i++){
        stk.push(str[i]);
        if(stk.top() == boom[endIdx]){
            int curIdx = endIdx;
            stack<char> tmp;
            while(1){
                // boom 모두 일치함.
                if(curIdx == -1){
                    break;
                }
                // 유추가 끝나지 않았는데 문자열이 더 이상 없음
                else if(stk.empty()){
                    // 문자열 복구
                    while(!tmp.empty()){
                        stk.push(tmp.top());
                        tmp.pop();
                    }
                    break;
                }
                // 폭발 문자열인지 유추하는 과정
                else if(boom[curIdx] == stk.top()){
                    tmp.push(stk.top());
                    stk.pop();
                    curIdx--;
                }
                // 폭발 문자열이 아님
                else{
                    // 문자열 복구
                    while(!tmp.empty()){
                        stk.push(tmp.top());
                        tmp.pop();
                    }
                    break;
                }
            }
        }
    }
    if(stk.empty()){
        cout << "FRULA";
        return;
    }
    stack<char> output;
    while(!stk.empty()){
        output.push(stk.top());
        stk.pop();
    }
    while(!output.empty()){
        cout << output.top();
        output.pop();
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}