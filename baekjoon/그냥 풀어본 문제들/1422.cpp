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
bool cmp(string s1, string s2);
bool check(string answer, int idx, string str);

int k, n;
vector<int> num_v;
vector<string> str_v;

bool cmp(string s1, string s2){
    while(s1.size() != s2.size()){
        if(s1.size() < s2.size()) s1 += "1";
        else if(s1.size() > s2.size()) s2 += "1";
    }

    for(int i=0; i<s1.size(); i++){
        if(s1[i] == s2[i]) continue;
        else return s1[i] > s2[i];
    }
    return true;
}

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> k >> n;
    for(int i=0; i<k; i++){
        int tmp;
        cin >> tmp;
        num_v.push_back(tmp);
        str_v.push_back(to_string(tmp));
    }

}

void solve()
{
    // sort(num_v.begin(), num_v.end(), greater<int>()); // 크기순대로 정리.
    // for(int num: num_v) cout << num << ' ';

    sort(str_v.begin(), str_v.end(), cmp);

    int maxValue = -1;
    for(const int& num: num_v) maxValue = max(maxValue, num);
    
    string answer = "";
    for(string s: str_v) answer += s + "/";

    string maxString = to_string(maxValue);
    string concatString = "";

    for(int i=0; i<n-k; i++) concatString += maxString;

    for(int i=0; i<answer.size(); i++){
        // 마지막에 끼워넣기
        if(i == answer.size() - 1){
            answer += concatString;
            break;
        }

        if(answer[i] == '/') continue;

        // 처음에 끼워넣기
        if(i == 0 || answer[i-1] == '/'){
            if(check(answer, i, maxString)){
                answer = answer.substr(0, i) + concatString + answer.substr(i);
                break;
            }
        }

        // 중간에 끼워넣기
        /*
        if(answer[i-1] == '/'){
            if(check(answer, i, maxString)){
                answer = answer.substr(0, i) + concatString + answer.substr(i);
                break;
            }
        }
        */
    }
    for(int i=0; i<answer.size(); i++){
        if(answer[i] != '/') cout << answer[i];
    }

    // 핵심은 각 수를 한번씩 사용해서 가장 큰 수를 만드는 것임.
    // 그리고 가장 큰 수를 사이에 끼워넣으면 된다.
    // 50개의 수를 모두 써보는 것은.. 50!로 존나 큽니다.
    // 어떤 순서를 사용하던 "자릿수는 모두 동일하다."
    // 최대한 앞의 자릿수가 큰 수가 와야 한다.

    // 3 20 19 -> 32019
    // 1 12 -> 121
    // 1 10 -> 110
    // 1 13 -> 131
    // 정렬을 할때, 자릿수를 맞추기 위해 1을 추가해주는 것은 어떨까.

    // 기본적으로, 자릿수는 맞춰주고 정렬을 들어가야 함.
    // 자릿수마다 비교해서, 앞자리가 큰 것이 앞으로 오도록 해야함.
    // 1 10 100 -> 110100

    // 자릿수를 모두 통일을 시켜서..
}

bool check(string answer, int idx, string s2){
    string s1 = "";
    for(int i=idx; i<answer.size(); i++){
        if(answer[i] == '/') break;
        s1 += answer[i];
    }

    while(s1.size() != s2.size()){
        if(s1.size() < s2.size()) s1 += "1";
        else if(s1.size() > s2.size()) s2 += "1";
    }
    if(s1 <= s2 ) return true;
    return false;
}


// 그냥 <=으로 처리해버리면
// 3 4
// 1 10 100
// -> 1 10 100 100
// -> 100 1 10 100 이 된다.


int main()
{
    init();
    input();
    solve();
    return 0;
}