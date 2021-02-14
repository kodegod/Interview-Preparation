class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        double z=myPow(x,n/2);
        if(n%2==0)
            return z*z;
        else
        {
            if(n>0)
                return x*z*z;
            else
                return z*z/x;
        }
    }
};
