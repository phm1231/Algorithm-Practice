// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n;
vector<int> a, b;


void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    a.resize(n);
    b.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
}

void solve()
{
    ll maxValue = -1e12;
    int maxL, maxR;
    maxL = maxR = 0;

    for(int i=0; i<n; i++){
        ll value = a[i] * b[i];
        if(maxValue < value){
            maxValue = value;
            maxL = maxR = i;
        }
        for(int l=i-1, r=i+1; 0 <= l && r < n; l--, r++){
            value += a[l] * b[r];
            value += a[r] * b[l];
            if(maxValue < value){
                maxValue = value;
                maxL = l; 
                maxR = r;
            }
        }
    }

    for(int i=0; i<n-1; i++){
        ll value = a[i] * b[i+1] + a[i+1] * b[i];
        if(maxValue < value){
            maxValue = value;
            maxL = i;
            maxR = i + 1;
        }
        for(int l=i-1, r=i+2; 0 <= l && r < n; l--, r++){
            value += a[l] * b[r];
            value += a[r] * b[l];
            if(maxValue < value){
                maxValue = value;
                maxL = l;
                maxR = r;
            }
        }
    }
    // maxR = 단순히 right 값이므로.
    // 지워야 하는 개수는 (n - 1) - maxR
    cout << maxL << ' ' << n - 1 - maxR << '\n' << maxValue;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}