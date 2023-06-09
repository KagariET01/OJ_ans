/*
[Q]https://leetcode.com/problems/binary-search/
[二分搜]
[AC]
*/
class Solution {
	public:
		int search(vector<int>& nums, int target) {
			#define ulli unsigned long long int
			#define lli long long int
			ulli lef=0,rig=nums.size()-1,ans;
			if(nums[0]>target || nums[rig]<target){
				return -1;
			}
			if(nums[0]==target){
				return 0;
			}
			if(nums[rig]==target){
				return rig;
			}
			while(true){
				if(nums[(rig+lef)/2]>target) rig=(rig+lef)/2;
				else if(nums[(rig+lef)/2]<target) lef=(rig+lef)/2;
				else{
					ans=(rig+lef)/2;
					break;
				}
				if(rig-lef<=2){
					if(nums[lef]==target){
						ans=lef;
						break;
					}else if(nums[lef+1]==target){
						ans=lef+1;
					}else if(nums[rig]==target){
						ans=rig;
						break;
					}else{
						ans=-1;
						break;
					}
				}
			}
			return ans;
		}
};