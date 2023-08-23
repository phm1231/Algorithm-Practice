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
vector<pair<int, int> > v;
vector<int> days(200000, 0);
vector<int> duplication(200000, 0);

// 컵라면을 많이 주는 순서대로 정렬
// 동일하다면, 날짜가 큰 순으로 정렬
bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.second == b.second){
        return a.first > b.first;
    }
    return a.second > b.second;
}

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++){
        int deadline, cnt;
        cin >> deadline >> cnt;
        v.push_back(make_pair(deadline - 1, cnt));
    }
}

void solve()
{
    sort(v.begin(), v.end(), cmp);

    days[v[0].first] = v[0].second;
    duplication[v[0].first]++;

    for(int i=1; i<n; i++){
        int day = v[i].first;
        int cnt = v[i].second;
        if(days[day] == 0){
            days[day] = cnt;
        }
        // 이미 다른 과제가 자리잡고 있었다면, 적절한 빈 자리를 찾아야 한다.
        else{
            int before_day = day;
            while(1){
                int current_day = before_day - duplication[before_day];
                if(before_day != day) duplication[before_day]++;

                if(current_day < 0) break;

                if(days[current_day] == 0){
                    days[current_day] = cnt;
                    duplication[current_day]++;
                    break;
                }

                before_day = current_day;
            }
        }

        duplication[v[i].first]++;
    }

    ll answer = 0;
    for(int i=0; i<n; i++){
        answer += days[i];
        // cout << days[i] << ' ';
    }
    cout << answer;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}