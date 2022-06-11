class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
         if(points.size()==0)
        {
            return 0;
        }
        int ans=0;
        for(int i=0;i<points.size();i++)
        {
            unordered_map<double,int>m;
            for(int j=i+1;j<points.size();j++)
            {
                if(!(points[i][0]-points[j][0]))
                {
                    m[100000]++;
                    continue;
                }
                double slope=(points[j][1]-points[i][1])*1.0/(points[j][0]-points[i][0]);
                m[slope]++;
            }
            for(auto it:m)
            {
                ans=max(it.second,ans);
            }
        }
        return ans+1;
    }
};

//See the discuss section for further understanding and other ways to solve this.
