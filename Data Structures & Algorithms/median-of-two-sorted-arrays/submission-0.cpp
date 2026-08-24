class Solution {
public:
    vector<int> mergeSortedArray(vector<int>& nums1, vector<int>& nums2){
        int i = 0;
        int j = 0;
        int n = nums1.size();
        int m = nums2.size();

        vector<int> ans;

        while(i <n && j < m){
            if(nums1[i] < nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }else{
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while(i < n){
            ans.push_back(nums1[i]);
            i++;
        }
          while(j < m){
            ans.push_back(nums2[j]);
            j++;
        }

        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans = mergeSortedArray(nums1,nums2);
        int size = ans.size();
   
        if(size % 2 == 0){
           double  res = ans[size/2] + ans[size/2 -1 ];
            return res / 2.0;

        }else{
            return ans[size /2] ;
        }
    }
};


