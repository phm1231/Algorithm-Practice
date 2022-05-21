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
#define MAX 100001

using namespace std;

void init();
void input();
void solve();
bool mysquare(int);

int n;
stack<ll> stk5;
stack<ll> stk6;

bool mysquare(int value){
    ll v = (ll)value;
    ll res = v * v;
    
    char v_str[100];
    char res_str[100];
    memset(v_str, 0, sizeof(v_str));
    memset(res_str, 0, sizeof(res_str));

    sprintf(v_str, "%lld", v);
    sprintf(res_str, "%lld", res);

    stack<char> v_stk;
    stack<char> res_stk;

    int v_len = strlen(v_str);
    int res_len = strlen(res_str);

    for(int i=0; i<v_len; i++){
        v_stk.push(v_str[i]);
    }

    for(int i=0; i<res_len; i++){
        res_stk.push(res_str[i]);
    }

    bool result = true;
    while(!v_stk.empty()){
        char v_ch = v_stk.top();
        v_stk.pop();
        char res_ch = res_stk.top();
        res_stk.pop();

        if(v_ch != res_ch){
            result = false;
            break;
        }
    }
    return result;
}

void init()
{

}

void input()
{
    scanf("%d", &n);
}

void solve()
{
    stk5.push(5);
    stk6.push(6);

    while(stk5.top() <= n){
        char buf[100];
        memset(buf, 0, sizeof(buf));
        for(int i=1; i<=100; i++){
            sprintf(buf, "%d%lld", i, stk5.top());
            int target = atoi(buf);
            if(mysquare(target)){ //f(x)
                stk5.push(target);
                break;
            }
        }
    }
    while(stk6.top() <= n){
        char buf[100];
        memset(buf, 0, sizeof(buf));
        for(int i=1; i<=100; i++){
            sprintf(buf, "%d%lld", i, stk6.top());
            int target = atoi(buf);
            if(mysquare(target)){ //f(x)
                stk6.push(target);
                break;
            }
        }
    }

    stk5.pop();
    stk6.pop();
    printf("%lld\n", max(stk5.top(), stk6.top()));
}

int main()
{
    init();
    input();
    solve();
    return 0;
}