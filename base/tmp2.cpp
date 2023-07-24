int getWaitTime(const int type, const int numberofMento){
    int waitTime = 0;
    int currentTime = 0;
    priority_queue<int> pq; // 상담이 일찍 끝나는 순서대로. first = 끝나는 시간, second = 인덱스
    
    for(int i=0; i<waiting[type].size(); i++){
        int start = waiting[type][i].first; // 상담 요청 시간
        int duration = waiting[type][i].second; // 걸리는 시간
        
        // 일하지 않는 멘토가 있음
        if(pq.size() < numberofMento){
            currentTime = start;
            pq.push(-(currentTime + duration));
        }
        // 일하지 않는 멘토가 없음
        else if(pq.size() == numberofMento){
            int endTime = -pq.top(); // 가장 빨리 끝나는 상담
            pq.pop(); // 상담을 끝냄
            
            // 이미 끝난 상담이었다면
            if(endTime <= currentTime){
                currentTime = start;
                pq.push(-(currentTime + duration));
            }
            // 아직 끝나지 않은 상담이었다면
            else{
                currentTime = endTime; // 일단 끝내주고
                // 아직 시간이 남음.
                if(currentTime <= start) currentTime = start;
                // 아님
                else{
                    waitTime += (currentTime - start);
                }
                pq.push(-(currentTime + duration));
            }
        }
    }
    return waitTime;
}