class Solution {
    struct edge {
        int src;
        int dest;
        int weight;
        
        bool operator < (const edge& that) {
            return weight < that.weight;
        }
        
    };
    vector<int> *v = nullptr;
    vector<int> *rank = nullptr;
public:
    
        int find(int node) {
        if((*v)[node] == node)
            return node;
        return (*v)[node]=find((*v)[node]);
    }
    
    void join(int a, int b) {
        if(!connected(a,b)) {
            int roota = find(a);
            int rootb = find(b);
            if((*rank)[a] > (*rank)[b]) {
                (*v)[rootb] = roota;
            } else if((*rank)[a] < (*rank)[b]) {
                (*v)[roota] = rootb;
            } else {
                (*v)[rootb] = roota;
                (*rank)[roota] +=1; 
            }
        }
    }
    
    bool connected(int a, int b) {
        if(find(a) == find(b))
            return true;
        return false;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<edge> edges;
        
        for(int i=0;i<points.size()-1;i++) {
            for(int j=i+1;j<points.size();j++) {
                vector<int> &src = points[i];
                vector<int> &dest = points[j];
                edges.push_back(edge{i,j, abs(src[0]-dest[0]) + abs(src[1]-dest[1])});
            }
        }
        sort(edges.begin(), edges.end());

        v = new vector<int>(points.size());
        for(int i=0;i<points.size();i++) {
            (*v)[i] = i;
        } 

        rank = new vector<int>(points.size(),1);
        int edgeCount = 0;
        int minCost = 0;

        for(int i=0;i<edges.size() && edgeCount <= points.size()-1;i++) {
            if(!connected(edges[i].src, edges[i].dest)) {
                join(edges[i].src, edges[i].dest);
                minCost += edges[i].weight;
                edgeCount++;
            }
        }
        return minCost;
        
    }
};