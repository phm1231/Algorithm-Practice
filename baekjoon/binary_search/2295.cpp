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

int n;
vector<int> v;
vector<int> sum;
void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    v.resize(n, 0);
    for(int i=0; i<n; i++) cin >> v[i];
}

void solve()
{
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            sum.push_back(v[i] + v[j]);
        }
    }
    sort(v.begin(), v.end()); // v[z]
    sort(sum.begin(), sum.end()); // v[x] + v[y]

    for(int i=n-1; i>=0; i--){
        for(int j=i; j>=0; j--){
            if(binary_search(sum.begin(), sum.end(), v[i] - v[j])){
                cout << v[i];
                return;
            }
        }
    }

}


int main()
{
    init();
    input();
    solve();
    return 0;
}