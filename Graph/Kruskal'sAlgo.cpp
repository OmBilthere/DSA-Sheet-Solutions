// User function Template for C++
class DisjointSet {
    
    vector<int> size , parent;
    
    public:
    
    DisjointSet(int n ) {
        
        parent.resize(n+1);
        size.resize(n+1 , 1);
    
        for(int i=0 ; i<= n ; i++ ) {
            parent[i] = i;
        }
        
        
    }
    
    int findParent(int node) {
        
        if(parent[node] == node ) return node;
        
        return parent[node] = findParent(parent[node]);
    }
    
    void unionBySize (int a , int b) {
        
        int ult_a = findParent(a);
        
        int ult_b = findParent(b);
        
        if( ult_a == ult_b ) return;
        
        else if ( size[ult_a] < size[ult_b]) {
            
            parent[ult_a] = ult_b;
            
            size[ult_b] += size[ult_a];
        }
        
        else {
            
            parent[ult_b] = ult_a;
            
            size[ult_a] += size[ult_b];
        }
    }
    
};

class Solution {
  public:
  
   static bool comp ( vector<int>& a , vector<int> & b) {
        
        return a[2] < b[2];
        
    }
    
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        
     
       DisjointSet ds(V);    
       
       sort(edges.begin() , edges.end() , comp );
       
       int weight = 0;
       
       for(auto it: edges) {
           
           int u = it[0];
           
           int v = it[1];
           
           int wt = it[2];
           
           if( ds.findParent(u) != ds.findParent(v)) {
               
               weight += wt;
               
               ds.unionBySize( u , v);
           }
          
       }
       
       return weight;
    }
};