#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
void makeWaiting(const vector<vector<int> >& reqs, int k);
int getWaitTime(const int type, const int numberofMento);
void dfs(const int, const int, vector<int>&);

vector<vector<pair<int, int> > > waiting; // waiting[type] = {startTime, endTime}
vector<vector<int> > memo;
int answer, N, K;

void dfs(const int sum, const int depth, vector<int>& v){

    if(sum > N) return;
    if(depth == K && sum < N) return;
    
    // 자연수를 k개 골랐고, 그 수의 합이 sum임
    if(depth == K && sum == N){
        // v[i] = i번 type에서 사용할 Mento의 수
        int tmp = 0;
        for(int i=0; i<v.size(); i++){
            int type = i+1;
            int numberofMento = v[i];
            tmp += memo[type][numberofMento];
        }
        answer = min(answer, tmp);
        return;
    }
    
    for(int i=1; i<=N; i++){
        v.push_back(i);
        dfs(sum + i, depth + 1, v);
        v.pop_back();
    }
}


int solution(int k, int n, vector<vector<int>> reqs) {
    answer = 987654321;
    makeWaiting(reqs, k);
    memo.resize(k+1, vector<int>(n+1, 0));
    N = n;
    K = k;
    
    // memo[type][i] = type에 멘토가 i명 배치되었을 때 걸리는 대기 시간
    for(int type=1; type<=k; type++){
        for(int i=1; i<=n; i++){
            memo[type][i] = getWaitTime(type, i);
            if(memo[type][i] == 0) break;
        }
    }
    
    /*
    for(int type=1; type<=k; type++){
        for(int i=1; i<=n; i++){
            cout << memo[type][i] << ' '; 
        }
        cout << endl;
    }
     */
    
    // 1이상인 자연수 k개로 이루어진 덧셈 중 합이 n이 되는 수
    vector<int> v;
    dfs(0, 0, v);
    return answer;
}


int getWaitTime(const int type, const int numberofMento){
    int waitTime = 0;
    int currentTime = 0;
    priority_queue<int> pq;

    for(int i=0; i<waiting[type].size(); i++){
        int start = waiting[type][i].first;
        int duration = waiting[type][i].second;

        while(pq.size() >= numberofMento){
            currentTime = -pq.top();
            pq.pop();
        }
        currentTime = max(currentTime, start);
        waitTime += (currentTime - start);
        pq.push(-(currentTime + duration));
    }

    return waitTime;
}

void makeWaiting(const vector<vector<int> >& reqs, int k){
    waiting.resize(k+1, vector<pair<int, int> >());
    for(int i=0; i<reqs.size(); i++){
        int startTime = reqs[i][0];
        int duration = reqs[i][1];
        int type = reqs[i][2];
        waiting[type].push_back({startTime, duration});
    }   
}