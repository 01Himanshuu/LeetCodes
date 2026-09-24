class Solution {
public:
    int smallestIndex(vector<int>& a) {
        for(int i=0;i<a.size();i++){
            int n=a[i],s=0;
            while(n)s+=n%10,n/=10;
            if(s==i)return i;
        }
        return -1;
    }
};