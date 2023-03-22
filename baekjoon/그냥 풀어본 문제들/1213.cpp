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
    queue<char> q;
    queue<char> midq;
    stack<char> stk;

    int counter[1000];
    memset(counter, 0, sizeof(counter));

    sort(str.begin(), str.end());
    for(int i=0; i<str.size(); i++){
        counter[str[i]]++;
    }

    // 짝수개면 넣기
    for(char ch='A'; ch <= 'Z'; ch++){
        // 2개보다 많거나 같으면
        while(counter[ch] >= 2){
            q.push(ch);
            stk.push(ch);
            counter[ch] -= 2;
        }
    }
    // 홀수개 처리 1또는 0
    for(char ch='A'; ch <= 'Z'; ch++){
        if(counter[ch] > 0){
            midq.push(ch);
            counter[ch]--;
        }
    }
    
    if(midq.size() > 1){
        cout << "I'm Sorry Hansoo";
        return;
    }

    while(!q.empty()){
        cout << q.front();
        q.pop();
    }
    while(!midq.empty()){
        cout << midq.front();
        midq.pop();
    }
    while(!stk.empty()){
        cout << stk.top();
        stk.pop();
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}