#include <vector>
#include <iostream>
#include <unordered_map>
#include <random>
using namespace std;

class Solution {
public:
    // Brute-force approach
    vector<int> twoSumBruteForce(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int k = i + 1; k < n; k++) {
                if (nums[i] + nums[k] == target) {
                    return { i, k };
                }
            }
        }
        return {}; // No solution found
    }

    // Hash map approach
    vector<int> twoSumHashMap(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        // Build the hash table
        for (int i = 0; i < n; i++) {
            numMap[nums[i]] = i;
        }

        // Find the complement
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement) && numMap[complement] != i) {
                return { i, numMap[complement] };
            }
        }

        return {}; // No solution found
    }

    // Optimized hash map approach
    vector<int> twoSumOptimized(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // Map from number to its index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return { numMap[complement], i }; // Return indices
            }
            numMap[nums[i]] = i; // Store current number and its index
        }

        return {}; // No solution found
    }
};

int main() {
    Solution solution;
    vector<int> nums;

    // Random number generation
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    // Generate two random numbers
    nums.push_back(dis(gen));
    nums.push_back(dis(gen));

    int target = nums[0] + nums[1]; // Set target as the sum of the two random numbers

    // Test Brute-force approach
    vector<int> resultBruteForce = solution.twoSumBruteForce(nums, target);
    cout << "Brute-force approach:" << endl;
    cout << "Generated numbers: " << nums[0] << " " << nums[1] << endl;
    cout << "Twosum: " << target << endl;
    cout << "Indices: ";
    for (int i : resultBruteForce) {
        cout << i << " ";
    }
    cout << endl;

    // Test Hash map approach
    vector<int> resultHashMap = solution.twoSumHashMap(nums, target);
    cout << "\nHash map approach:" << endl;
    cout << "Generated numbers: " << nums[0] << " " << nums[1] << endl;
    cout << "Twosum: " << target << endl;
    cout << "Indices: ";
    for (int i : resultHashMap) {
        cout << i << " ";
    }
    cout << endl;

    // Test Optimized hash map approach
    vector<int> resultOptimized = solution.twoSumOptimized(nums, target);
    cout << "\nOptimized hash map approach:" << endl;
    cout << "Generated numbers: " << nums[0] << " " << nums[1] << endl;
    cout << "Twosum: " << target << endl;
    cout << "Indices:";
    for (int i : resultOptimized) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
