class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1,0);
        int prev = 0;
        for(int i = 1 ; i <= rowIndex+1 ; i++)
        {
            for(int j = 0 ; j < i ; j++)
            {
                if(j == 0 || j == rowIndex)
                {
                    res[j] = 1;
                    prev = 1;
                }
                else
                {
                    int tmp = res[j];
                    res[j] += prev;
                    prev = tmp;
                }
            }
        }
        return res;
    }
};
