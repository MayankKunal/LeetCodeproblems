class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        int n = hand.size();
        if (n % groupSize != 0) return false;

        // Count the frequency of each card
        for (int card : hand) {
            mp[card]++;
        }

        // Try to construct groups
        while (!mp.empty()) {
            int minVal = mp.begin()->first; // Get the smallest card
            // Try to construct a group of groupSize starting from minVal
            for (int i = 0; i < groupSize; i++) {
                if (mp[minVal + i] > 0) {
                    mp[minVal + i]--;
                    if (mp[minVal + i] == 0) {
                        mp.erase(minVal + i);
                    }
                } else {
                    return false; // If a card is missing, return false
                }
            }
        }

        return true;
    }
};
