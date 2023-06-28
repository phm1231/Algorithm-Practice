// based problem:
#include <iostream>
#include <vector>

using namespace std;


#define ll long long
#define MAX 100001

void init();
void input();
void solve();

long long s;

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
    // 55 66 78 91 105 120 136 153 171 190 210
    vector<long long> v;
    v.push_back(0);
    long long sum = 0;
    for(int i=1; ; i++){
        sum += i;
        v.push_back(sum);

        if(sum >= s) break;
    }

    if(v.back() == s) cout << v.size() - 1;
    else cout << v.size() - 2;
    
}

int main()
{
    init();
    input();
    solve();
    return 0;
}