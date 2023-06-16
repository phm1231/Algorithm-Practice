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

unordered_map<int, string> num_to_str;
unordered_map<string, int> str_to_num;

int n, m;

void init()
{
    FAST
}

void input()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string poketmon_str;
        cin >> poketmon_str;
        num_to_str[i+1] = poketmon_str;
        str_to_num[poketmon_str] = i+1;
    }
    for(int i=0; i<m; i++){
        string str;
        cin >> str;
        // 숫자가 들어왔다면
        if('0' <= str[0] && str[0] <= '9'){
            cout << num_to_str[stoi(str)] << "\n";
        }
        else{
            cout << str_to_num[str] << "\n";
        }
    }
}

void solve()
{

}

int main()
{
    init();
    input();
    solve();
    return 0;
}