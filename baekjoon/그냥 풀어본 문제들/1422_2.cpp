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
bool cmp(string, string);

int n, k;
vector<int> num_v;
vector<string> str_v;

bool cmp(string s1, string s2){
    return s1 + s2 > s2 + s1;
}


void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> k >> n;
    num_v.resize(k, 0);
    for(int i=0; i<k; i++){
        cin >> num_v[i];;
        str_v.push_back(to_string(num_v[i]));
    }
}

void solve()
{
    int maxValue = -1;
    for(int num: num_v) maxValue = max(maxValue, num);

    for(int i=0; i<n-k; i++) str_v.push_back(to_string(maxValue));

    sort(str_v.begin(), str_v.end(), cmp);

    for (int i=0; i<str_v.size(); i++) cout << str_v[i];
    
}


int main()
{
    init();
    input();
    solve();
    return 0;
}