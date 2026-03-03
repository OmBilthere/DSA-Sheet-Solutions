class DisjointSet {
  
    public:

    vector<int> size , parent;
    
    DisjointSet(int n) {
        
        size.resize(n+1 , 1);
        
        parent.resize(n+1);
        
        for(int i = 0 ; i<= n; i++ )
        
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
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        
        DisjointSet ds (n*n);

        vector<int> dx = { 0 , 0 , -1 , 1} ;

        vector<int> dy = { 1 , -1 , 0 , 0 };
        
        for(int row=0 ; row<n; row++) {

            for(int col=0 ; col<n ; col++) {
     
                if(grid[row][col]) {
                     
                     int index1 = (row*n)+col;

                     for(int i=0 ; i<4 ; i++) {
                        
                        int x= row+dx[i];

                        int y=col+dy[i];

                        if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==1 ) {
                            
                            int index2 = (x*n)+y;

                            ds.unionBySize(index1 , index2);
                        }
                     }
                }
            }
        }

        int maxi = 0;

        for(int row = 0 ; row < n ; row++ ) {

            for(int col = 0 ; col < n ; col++ ) {

                if(grid[row][col] == 0 ) {   
                    
                    set<int>st;

                    for(int i=0; i<4 ; i++) {
                        
                        int x = row+dx[i];

                        int y = col+dy[i];

                        if(x>=0 && y>=0 && x<n && y<n && grid[x][y] == 1) {
                            
                            int idx = (x*n)+y;

                            int ult_par = ds.findParent(idx);

                            st.insert(ult_par);
                        }
                    }

                   int total = 1;

                    for(auto it: st) {
                        
                        total += ds.size[it];
                      
                    }

                   maxi = max(maxi , total); 
                }
            }
        }

       return maxi == 0 ? n*n : maxi;
    }
};