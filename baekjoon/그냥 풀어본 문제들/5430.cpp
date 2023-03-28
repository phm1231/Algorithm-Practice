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
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void init();
void input();
void solve();

int t, n;
string funcs;
deque<int> dq;

void init()
{
    FAST
}

void input()
{
    while(!dq.empty()) dq.pop_front();

    cin >> funcs;
    cin >> n;

    string arr;
    cin >> arr;

    if(n != 0){
        string tmp = "";
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == '[' || arr[i] == ']' || arr[i] == ','){
                if(tmp == "") continue;
                else{
                    dq.push_back(stoi(tmp));
                    tmp = "";
                }
            }
            else{
                tmp += arr[i];
            }
        }
    }
}

void solve()
{
    bool isFront = true;
    bool isError = false;

    for(int i=0; i<funcs.size(); i++){
        char func = funcs[i];
        switch(func){
            case 'R':
                isFront = !isFront;
                break;
            case 'D':
                if(!dq.empty()){
                    if(isFront) dq.pop_front();
                    else dq.pop_back();
                }
                else isError = true;
                break;
            default:
                break;
        }
        if(isError) break;
    }

    if(isError){
        cout << "error" << endl;
        return;
    }
    if(n == 0 || dq.empty()){
        cout << "[]" << endl;
        return;
    }
    if(isFront){
        string output = "[";
        while(!dq.empty()){
            output += to_string(dq.front()) + ",";
            dq.pop_front();
        }
        output.erase(output.size() - 1);
        output += "]";
        cout << output << endl;
    }
    else{
        string output = "[";
        while(!dq.empty()){
            output += to_string(dq.back()) + ",";
            dq.pop_back();
        }
        output.erase(output.size() - 1);
        output += "]";
        cout << output << endl;
    }
}

int main()
{
    init();
    cin >> t;
    while(t--){
        input();
        solve();
    }
    return 0;
}