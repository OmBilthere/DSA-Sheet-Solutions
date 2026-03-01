class DisjointSet {
   vector<int> parent , size;

   public:
   
   DisjointSet(int n ) {
     
     parent.resize( n );
     size.resize( n , 1);

     for(int i=0 ; i< n ; i++ ) 

     parent[i]=i;
    
   }

   int findParent(int node) {


        if(node == parent[node]) return node;

        return parent[node] = findParent(parent[node]);

    }

  void unionBySize(int u , int v) {
     int ul_u = findParent(u);
     int ul_v = findParent(v);

     if(ul_u == ul_v) return;

     else if( size[ul_u] < size[ul_v]) {

        size[ul_v]+=size[ul_u];

        parent[ul_u]= ul_v;
     }

     else {
        size[ul_u] += size[ul_v];

        parent[ul_v] = ul_u;
     }
  }

    
};

class Solution {

public:

    int makeConnected(int n, vector<vector<int>>& connections) {

       DisjointSet ds(n); 

       int extraEdges = 0;

       for(int i=0 ; i< connections.size() ; i++ ) {

           int u = connections[i][0];

           int v = connections[i][1];

           if(ds.findParent(u) == ds.findParent(v)) extraEdges++;

           else  ds.unionBySize(u , v);
          
       }
       
       int numberOfGraph = 0;

       for(int i=0 ; i<n ; i++) 
          
       if(ds.findParent(i) == i ) numberOfGraph++;
    
       if(extraEdges >= (numberOfGraph-1))

       return numberOfGraph-1;

       return -1;

    }
};