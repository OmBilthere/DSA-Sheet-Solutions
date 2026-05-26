class Solution {
public:
    bool rotateString(string s, string goal) {
        

        int n = s.size() , m = goal.size();

        if ( n != m ) return false;

        s = s+s;

        for(int i=0 ; i<n ; i++) {
           
           if(s[i] == goal[0]) {
               int k=0;
               while(k<n && s[k+i]==goal[k] ) 
               k++;

               if(k==n) return true;

           }

        }
       return false;
    }
};