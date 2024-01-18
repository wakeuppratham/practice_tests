class Solution {
    public int maxArea(int[] height) {

        // Area = width * height
        int Area = 0;
        
        int n = height.length;
        int left = 0;
        int right = n-1;

        while(left<right){

            Area = Math.max(Area,(right-left)*Math.min(height[left],height[right]));

            if(height[left]<height[right]){
                left++;
            }
            else if(height[left]>height[right]){
                right--;
            }
            else{
                left++;
                right--;
            }

        }
        
        return Area;
    }
}