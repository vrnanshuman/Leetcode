class Solution {
    
    struct Edge {
        int src;
        int dest;
        int weight;
        
        bool operator < (const Edge &that) const{
            return weight > that.weight;
        }
    };
public:
    
    vector<vector<pair<int,int>>> createGraph(vector<vector<int>>& times, int& n) {
        vector<vector<pair<int,int>>> graph(n+1);
        
        for(auto& edge : times) {
            graph[edge[0]].push_back({edge[1],edge[2]});
        }
        return graph;
        
    }
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        priority_queue<Edge, vector<Edge>> min_heap;
        vector<int> visited(n+1, 0);
        vector<int> distance(n+1, INT_MAX);
        int src, dest;
        Edge top;
        
        vector<vector<pair<int,int>>> graph = createGraph(times, n);
        
        min_heap.push(Edge{k,k,0});
        distance[k] = 0;
        
        while(!min_heap.empty()) {
            top = min_heap.top();
            min_heap.pop();
            
            visited[top.dest] = 1;
            

            for(auto& edge : graph[top.dest]) {

                if(!visited[edge.first] && (distance[top.dest] + edge.second) < distance[edge.first]) {
                    min_heap.push(Edge{top.dest, edge.first, min(distance[edge.first], distance[top.dest] + edge.second)});
                    distance[edge.first] = distance[top.dest] + edge.second;
                }
            }
            
        }

        int minTime = *max_element(distance.begin()+1, distance.end());
        return  minTime== INT_MAX? -1 : minTime;
        
    }
};