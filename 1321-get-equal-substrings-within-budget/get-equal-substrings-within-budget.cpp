class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int left = 0, right = 0;
        int currentCost = 0;
        int maxLength = 0;
        
        // Iterate over the string with the right pointer
        while (right < n) {
            // Calculate the cost of transforming s[right] to t[right]
            currentCost += abs(s[right] - t[right]);
            
            // If the current cost exceeds maxCost, move the left pointer
            while (currentCost > maxCost) {
                currentCost -= abs(s[left] - t[left]);
                left++;
            }
            
            // Update the maximum length of the valid substring
            maxLength = max(maxLength, right - left + 1);
            
            // Move the right pointer forward
            right++;
        }
        
        return maxLength;
    }
};
