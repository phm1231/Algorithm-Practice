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
int check(string, string);

int n, m;
int answer = 0;
string p;

void init()
{
    FAST
}

void input()
{
    cin >> n;
    cin >> m;
    cin >> p;
}

void solve()
{
    string myp = "";
    for(int i=1; i<=n*2+1; i++){
        if(i % 2 == 1) myp += 'I';
        else myp += 'O';
    }
    int siz = myp.size();

    for(int i=0; i<m; i++){
        for(int j=0; j<siz; j++){
            if(p[i+j] != myp[j]){
                i += j-1;
                break;
            }
            if(j == siz-1) answer++;
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