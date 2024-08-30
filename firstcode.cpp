#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            numMap[nums[i]] = i;
        }
        
        return {};
    }
};

void printResult(const std::vector<int>& result) {
    if (result.size() == 2) {
        std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }
}

int main() {
    Solution solution;

    // Test case 1
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::cout << "Example 1: ";
    printResult(solution.twoSum(nums1, target1));

    // Test case 2
    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::cout << "Example 2: ";
    printResult(solution.twoSum(nums2, target2));

    // Test case 3
    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::cout << "Example 3: ";
    printResult(solution.twoSum(nums3, target3));

    return 0;
}
