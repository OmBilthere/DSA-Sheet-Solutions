class DisjointSet {
    
    vector<int> size , parent;
    
    public:
    
    DisjointSet(int n) {
        
        size.resize(n+1 , 1);
        
        parent.resize(n+1);
        
        for(int i = 1 ; i<= n; i++ )
        
        parent[i] = i;
    }
    
    int findParent(int node) {
        
        if(node == parent[node]) return node;
        
        return parent[node] = findParent(parent[node]);
        
    }
    
    void unionBySize(int u , int v) {
        
        int pu = findParent(u);
        
        int pv = findParent(v);
        
        if(pu==pv) return;
        
        else if ( size[pu] < size[pv]) {
            
            size[pv]+=size[pu];
            
            parent[pu]= pv;
        }
        
        else {
            
            size[pu] += size[pv];
            
            parent[pv] = pu;
        }
    }
    
};

class Solution {

  public:
  
    int numProvinces(vector<vector<int>> adj, int V) {
    
       DisjointSet ds(V);
       
       int cnt = 0;
       
       for (int i=1 ; i<=V ; i++) {
           
           for(int j=1 ; j<=V ; j++ ) {
               
               if( adj[i-1][j-1] == 1 && ds.findParent(i) != ds.findParent(j)) 
               
               ds.unionBySize(i , j);
               
           }
       }
       
       for(int i=1 ; i<=V ; i++ ) {
           
           if(ds.findParent(i) == i ) cnt++;
           
       }
       
       return cnt;
    } 
};