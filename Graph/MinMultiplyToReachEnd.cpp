// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        int n = arr.size();
        
        const int mod = 100000;
        
        queue<pair<long long ,int>>q;
        
        q.push({start , 0});
        
        vector<int>dist(mod , 1e9);
        
        while(!q.empty()) {
            
            auto [ currNum , steps ] = q.front();
            
            q.pop();
            
            if(currNum == end ) return steps;
            
            for( int i = 0 ; i< n ; i++ ) {
                
                long long nextNum = (currNum * arr[i])%mod;
                
                if( nextNum < arr[i]) {
                    
                    q.push({nextNum , steps+1});
                    
                    arr[i] = nextNum;
                    
                }
            }
            
            
        }
        
        return -1;
        
    }
};
