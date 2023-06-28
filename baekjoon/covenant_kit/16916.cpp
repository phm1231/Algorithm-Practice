// based problem:
#include <iostream>
#include <vector>

using namespace std;


#define ll long long
#define MAX 100001

void init();
void input();
void solve();
vector<int> getPi(string str);
bool kmp(string parent, string pattern, const vector<int>& pi);

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{

}

void solve()
{
    string parent, pattern;
    cin >> parent >> pattern;

    vector<int> pi = getPi(pattern);
    kmp(parent, pattern, pi) ? cout << 1 : cout << 0;
}

vector<int> getPi(string str){
    int len = str.size();
    vector<int> pi(len, 0);

    for(int i=1, j=0; i<len; i++){
        while(j > 0 && str[i] != str[j]){
            j = pi[j-1];
        }
        if(str[i] == str[j]){
            j++;
            pi[i] = j;
        }
    }
    return pi;
}

bool kmp(string parent, string pattern, const vector<int>& pi){
    for(int i=0, j=0; i<parent.size(); i++){
        while(j > 0 && parent[i] != pattern[j]){
            j = pi[j-1];
        }
        if(parent[i] == pattern[j]){
            if(j == pattern.size() - 1) return true;
            else j++;
        }
    }
    return false;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}