// User function Template for C++

class Solution {
  public:
    // Function to merge two nodes a and b.
    
    int find_par(int node , int par[] ) {
        
        if(node == par[node]) return node;
        
        return par[node] = find_par(par[node] , par);
    }
    
    
    void union_(int a, int b, int par[], int rank1[]) {
        
        int ult_a = find_par(a ,par);
        
        int ult_b = find_par(b ,par);
        
        if(ult_a == ult_b ) return;
        
        if (rank1[ult_a] < rank1[ult_b]) {
            
            par[ult_a] = ult_b;
        }
        
          else if(rank1[ult_b] < rank1[ult_a]) {
            
            par[ult_b] = ult_a;
        }
        
        else {
            
              par[ult_b] = ult_a;
              
              rank1[ult_a]++;
        }
        
    }

    // Function to check whether 2 nodes are connected or not.
    bool isConnected(int x, int y, int par[], int rank1[]) {
        
        if(find_par(x , par) == find_par(y , par)) 
        
        return true;
        
        return false;
    }
};