class Solution {
public:
  void merge(vector<int>&nums,int l,int mid,int r)
  {
    vector<int>arr;
    vector<int>arr1;
    vector<int>arr2;
    for(int i=l;i<=mid;i++)
    {
        arr1.push_back(nums[i]);
    }
    for(int i=mid+1;i<=r;i++)
    {
        arr2.push_back(nums[i]);
    }
    int n=arr1.size();
    int m=arr2.size();
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(arr1[i]<=arr2[j])
        {
            arr.push_back(arr1[i++]);
        }
        else arr.push_back(arr2[j++]);
    }
    while(i<n) arr.push_back(arr1[i++]);
    while(j<m) arr.push_back(arr2[j++]);
    int s=arr.size();
    for(int k=0;k<s;k++)
    {
           nums[l+k]=arr[k];
    }
  }
   void mergeSort(vector<int>&nums,int l,int r)
   {
        if(l>=r) return;
        int mid=l+(r-l)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        merge(nums,l,mid,r);
   }
    vector<int> sortArray(vector<int>& nums) {
        
        int l=0;
        int n=nums.size();
       int r=n-1;
        mergeSort(nums,l,r);
 return nums;
    }
};