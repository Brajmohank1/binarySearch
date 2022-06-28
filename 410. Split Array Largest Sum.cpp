/*
Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

 

Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], m = 2
Output: 9
Example 3:

Input: nums = [1,4,4], m = 3
Output: 4
 

*/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        
       int right = 0 , left = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            right += nums[i];
            left = max(left , nums[i]);
        }
        int j = 0;
        while(left< right){
            
            int mid = (right + left) / 2  ;
            
            int flag = 0 , cur = 0 , k = 1;
            for(int i = 0 ; i < nums.size() ; i++){
            
                    
                if(mid < cur + nums[i])
                {
                        cur = nums[i];
                        k++;
                    
                    if(k > m) {
                                flag = 1;
                        break;
                    }
                }else
                    cur += nums[i];
        }
            cout<<left<< " " <<right <<"\n";
            
            if(flag) left = mid + 1;
            else
                right = mid;
        j++;
        
        }
        
        return right;
        
    }
};
