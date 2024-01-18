import java.util.*;


class Solution {
    public List<List<Integer>> threeSum(int[] nums) {

        Arrays.sort(nums);
        
        Set<List<Integer>> ans = new HashSet<>();

        int n = nums.length;

        for(int i=0;i<n-1;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = n-1;

            int target = nums[i]*-1;

            while(j<k){
                if(nums[j]+nums[k]>target){
                    k--;
                }
                else if(nums[j]+nums[k]<target){
                    j++;
                }
                else{
                    ArrayList<Integer> al = new ArrayList<>();
                    al.add(nums[i]);
                    al.add(nums[j]);
                    al.add(nums[k]);
                    ans.add(new ArrayList<>(al));
                    j++;
                    k--;
                }
            }
        }
        return new ArrayList<>(ans);
    }
}
