class Solution {
public:
    // Function to check if it's possible to reach the office on time with given speed
    bool possible(vector<int>& dist, int speed, double hour) {
        double time = 0; // total time needed

        // For all trains except the last one
        for(int i = 0; i < dist.size() - 1; i++) {
            // Each train departs at integer hour, so take ceil
            time += ceil((double)dist[i] / (double)speed);
        }

        // Last train can arrive at fractional hour, no need to ceil
        time += (double)dist.back() / (double)speed;

        // Return true if total time is within allowed hour
        return time <= hour;
    }

    // Main function to find minimum speed to arrive on time
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;                 // minimum possible speed
        int high = 1e7;              // maximum possible speed (safe upper bound)
        // Explanation for high = 1e7:
        // Based on constraints:
        //   - Each train distance <= 1e5
        //   - Number of trains <= 1e5
        //   - Hour <= 1e9
        // Even if all distances are maximum, speed = 1e7 gives extremely small travel time
        // so this upper bound ensures binary search includes all valid speeds.
        // It acts as a safe cushion to cover edge cases, so if no speed <= 1e7 works, 
        // the answer is impossible (-1).

        int ans = -1;                // store answer, -1 if impossible

        // Binary search for the minimum speed
        while(low <= high) {
            int mid = low + (high - low) / 2; // prevents integer overflow

            if(possible(dist, mid, hour)) {
                ans = mid;              // current speed works
                high = mid - 1;         // try smaller speed
            } else {
                low = mid + 1;          // speed too slow, increase
            }
        }

        return ans;                     // return minimum speed or -1 if impossible
    }
};
