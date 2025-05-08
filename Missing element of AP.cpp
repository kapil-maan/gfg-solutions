#include <vector>

class Solution {
public:
    int findMissing(std::vector<int> &arr) {
        int n = arr.size();
        
        long long first_val = arr[0];
        long long last_val = arr[n - 1];

        
         if ((n - 1) > 0 && (last_val - first_val) % (n - 1) == 0) { 
            long long d_complete = (last_val - first_val) / (n - 1);
            bool is_ap_consistent = true;
            
             for (int i = 1; i < n; ++i) {
                if (arr[i] != first_val + (long long)i * d_complete) {
                    is_ap_consistent = false;
                    break;
                }
            }

            if (is_ap_consistent) {
                 
                return static_cast<int>(last_val + d_complete);
            }
        } else if (n - 1 == 0 && n == 1) { 
        }


         long long d_missing_scenario = (last_val - first_val) / n;

         for (int i = 0; i < n; ++i) { 
             long long expected_term_at_pos_i = first_val + (long long)i * d_missing_scenario;
            if (arr[i] != expected_term_at_pos_i) {
                 return static_cast<int>(expected_term_at_pos_i);
            }
        }
        
        return static_cast<int>(first_val + (long long)n * d_missing_scenario);
    }
};