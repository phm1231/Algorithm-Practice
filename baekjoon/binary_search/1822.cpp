// based problem:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int asiz, bsiz;
vector<int> a, b, answer;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> asiz >> bsiz;
    a.resize(asiz, 0);
    b.resize(bsiz, 0);
    for(int i=0; i<asiz; i++) cin >> a[i];
    for(int i=0; i<bsiz; i++) cin >> b[i];

}

void solve()
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i=0; i<asiz; i++){
        if(!binary_search(b.begin(), b.end(), a[i])) answer.push_back(a[i]);
    }
    cout << answer.size() << "\n";
    for(int i=0; i<answer.size(); i++) cout << answer[i] << ' ';
}


int main()
{
    init();
    input();
    solve();
    return 0;
}