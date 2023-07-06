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
bool isIncluded(const string, const string);

int n;
int answer = 0;
vector<string> v;

bool cmp(const string& a, const string& b){
    return a.size() > b.size();
}

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
}

void solve()
{
    sort(v.begin(), v.end(), cmp);
    // 문자열의 길이가 큰 순서대로 정렬
    vector<string> answers;
    answers.push_back(v[0]);

    for(int i=1; i<n; i++){
        string next = v[i];
        bool canOn = true;
        for(string s: answers){
            if(isIncluded(s, next)){
                canOn = false;
                break;
            }
        }
        if(canOn) answers.push_back(next);
    }
    cout << answers.size();
}

bool isIncluded(const string a, const string b){
    if(a.find(b) == 0 || b.find(a) == 0) return true;
    return false;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}