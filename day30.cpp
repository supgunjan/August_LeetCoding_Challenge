class Solution {
    vector<int> parent;
    vector<int> sz;
public:
 
    void make_set(int n){
        for(int i = 0; i < n; i++){
            parent.push_back(i);
            sz.push_back(1);
        }        
    }
 
    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
 
    void union_set(int x, int y){
        int a = find(x);
        int b = find(y);
 
        if(a != b){
            if(sz[a] < sz[b]){
                swap(a, b);
            }
            sz[a] += sz[b];
            parent[b] = a;
        }
    }
 
    int largestComponentSize(vector<int>& A) {
        int n = A.size();
        make_set(n + 1);
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            int x = A[i];
            for(int j = 2; j * j <= x; j++){
                if(x % j == 0){
                    if(!mp.count(j)){
                        mp[j] = i;
                    }else{
                        union_set(i, mp[j]);
                    }
                    if(!mp.count(x / j)){
                        mp[x / j] = i;
                    }else{
                        union_set(i, mp[x / j]);
                    }
                }
            }    
            if(!mp.count(x)){
                mp[x] = i;
            }else{
                union_set(i, mp[x]);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, sz[i]);
        }
        return ans;
    }
};
