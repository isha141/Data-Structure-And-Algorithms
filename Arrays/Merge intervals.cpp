class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans; 
        sort(intervals.begin(),intervals.end());
        int m=intervals.size();
        int first=0;
        int second=0; 
        first=intervals[0][0];
        second=intervals[0][1];
        for(int i=0;i<m;i++)
        {
            if(second>=intervals[i][0])
            {
                second=max(second,intervals[i][1]);
            }
            else
            {
                ans.push_back({first,second});
                first=intervals[i][0];
                second=intervals[i][1];
            }
        } 
        ans.push_back({first,second});
        return ans;        
    }
};
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
