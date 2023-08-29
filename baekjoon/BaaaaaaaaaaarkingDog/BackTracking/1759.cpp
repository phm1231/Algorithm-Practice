#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();
bool check(const vector<char>& v);
void dfs(vector<char>& v, int idx);


int l, c;
vector<char> chs;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{  
    cin >> l >> c;
    chs.resize(c);
    for(int i=0; i<c; i++) cin >> chs[i];
}

void solve()
{
    sort(chs.begin(), chs.end());
    vector<char> v;
    dfs(v, 0);
}

void dfs(vector<char>& v, int idx){
    if(v.size() == l){
        if(check(v)){
            for(char ch: v){
                cout << ch;
            }
            cout << endl;
        }
        return;
    }

    for(int i=idx; i<c; i++){
        v.push_back(chs[i]);
        dfs(v, i+1);
        v.pop_back();
    }
}

bool check(const vector<char>& v){
    // 1개 이상의 모음, 2개 이상의 자음.
    int consonant = 0; // 자음
    int vowel = 0; // 모음
    for(char ch: v){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') vowel++;
        else consonant++;
    }

    return (consonant >= 2 && vowel >= 1);
}


int main()
{
    init();
    input();
    solve();
    return 0;
}