class Solution {
    
    struct Job{
        int id, timestamp, wait;
    };
    
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n,0);
        stack<Job> Stack;
        string token;
        int id, start, wait;
        for(string s: logs) {
            vector<string> log;
            stringstream ss(s);
            while(getline(ss, token, ':')) {
                log.emplace_back(token);
            }
            int id = stoi(log[0]);
            int isStart = log[1][0] == 's' ? 1 : 0;
            int timestamp = stoi(log[2]);
            
            if(isStart) {
                Stack.push(Job{id, timestamp, 0});
            } else {
                auto top = Stack.top();
                Stack.pop();
                int runtime = timestamp - top.timestamp + 1 - top.wait;
                int waittime = timestamp - top.timestamp + 1;
                result[id] += runtime;
                if(!Stack.empty())
                    Stack.top().wait += waittime;
            }
            
        }
        return result;
    }
};