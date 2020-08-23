class Solution {
public:
    static bool comp(int a,int b)
    {
        if(a%2 == 0 && b%2) return true;
        else if(a%2 && b%2 == 0 ) return false;
        return false;
    }
    vector<int> sortArrayByParity(vector<int>& A) {
        sort(A.begin(),A.end(),comp);
        return A;
    }
};
