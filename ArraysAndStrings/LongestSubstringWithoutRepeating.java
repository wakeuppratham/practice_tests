import java.util.*;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxL = 0;
        Set<Character> hs = new HashSet<>();
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (!hs.contains(s.charAt(right))) {
                hs.add(s.charAt(right));
                maxL = Math.max(maxL, right - left + 1);
            } else {
                while (hs.contains(s.charAt(right))) {
                    hs.remove(s.charAt(left));
                    left++;
                }
                hs.add(s.charAt(right));
            }
        }
        
        return maxL;
    }
}
