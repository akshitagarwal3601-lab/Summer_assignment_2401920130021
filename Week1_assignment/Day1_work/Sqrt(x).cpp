class Solution {
public:
    int mySqrt(int x) {

        if(x==0) return 0;

        int high=x, low=1;
        
        while(low<=high){
            int mid=low+(high-low)/2;

            if((long long)mid*mid <= x){
                low=mid+1;               
            }
            else{
                high=mid-1;
            }
        }
        return high;
    } 
};
