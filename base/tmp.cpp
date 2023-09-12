#include <iostream>
#include <vector>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();
void recur(int);

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{

}

void solve()
{
   recur(10);
}

void recur(int n){
   if(n < 0) return;
   cout << n << " ";
   recur(--n);
   // recur(n-1)
}


int main()
{
    init();
    input();
    solve();
    return 0;
}