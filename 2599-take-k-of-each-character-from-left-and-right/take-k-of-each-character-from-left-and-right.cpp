class Solution {
public:
    int takeCharacters(string s, int k) {
        
        int n=s.size();
        int a=0,b=0,c_=0;
        for(char &c:s)
        {
            if(c=='a') a++;
            else if(c=='b') b++;
            else c_++;
        }
        
        if(k==0) return 0;
        int maxLen=0;
        if(a<k || b<k || c_<k) return -1;
        int targetA = a - k, targetB = b - k, targetC = c_ - k;
        int left = 0, right = 0;
        int currentA = 0, currentB = 0, currentC = 0;
        int maxLength = 0;

        while (right < n) {
            // Expand the window
            if (s[right] == 'a') currentA++;
            else if (s[right] == 'b') currentB++;
            else currentC++;

            // Shrink the window if it exceeds the target
            while (currentA > targetA || currentB > targetB || currentC > targetC) {
                if (s[left] == 'a') currentA--;
                else if (s[left] == 'b') currentB--;
                else currentC--;
                left++;
            }

            // Update the maximum valid subarray length
            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        // The minimum minutes needed is the complement of the maximum valid subarray length
        return n - maxLength;

    }
};