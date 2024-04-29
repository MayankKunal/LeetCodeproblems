class Solution {
    int largestRectangleHistogram(vector<int>& height)
    {
      int n=height.size();
        stack<int>st;
        vector<int>leftMin(n,-1);
        vector<int>rightMin(n,n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && height[st.top()]>=height[i])
            {
                st.pop();
            }
            if(st.empty()) leftMin[i]=-1;
            else leftMin[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && height[st.top()]>=height[i])
            {
                st.pop();
            }
            if(st.empty()) rightMin[i]=n;
            else rightMin[i]=st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int temp=abs(rightMin[i]-leftMin[i])-1;
            temp=temp*height[i];
            ans=max(ans,temp);
        }
        return ans;
    }
    int largestRectangle(vector<int> arr)
    {
        int n=arr.size();
        vector<int>leftBound(n,-1);
        vector<int>rightBound(n,n);
           stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(!st.empty() && arr[st.top()]>=arr[i])
                  st.pop();
            if(!st.empty()) leftBound[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--)
        {
            if(!st.empty() && arr[st.top()]>=arr[i])
                  st.pop();
            if(!st.empty()) rightBound[i]=st.top();
            st.push(i);
        }
       int ans=0;
        for(int i=0;i<n;i++)
        {
            int temp=abs(rightBound[i]-leftBound[i])-1;
            temp*=arr[i];
            ans=max(ans,temp);
        }
        return ans;

    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>res(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0') res[j]=0;
                else res[j]++;
            }

            int temp=largestRectangleHistogram(res);
            ans=max(ans,temp);
        }
        return ans;
    }
};