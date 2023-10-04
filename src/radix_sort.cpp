#include "sorting_algorithms.h"

vector<int> radix_sort(vector<int> nums){
    int max_num = nums[0];
    for (int num : nums) {
        if (num > max_num) {
            max_num = num;
        }
    }
    int exp = 1;
    int n = nums.size();
    std::vector<int> sorted(n);
    while (max_num / exp > 0) {
        std::vector<int> count(10, 0);
        for (int i = 0; i < n; i++) {
            int digit = (nums[i] / exp) % 10;
            count[digit]++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            int digit = (nums[i] / exp) % 10;
            sorted[count[digit] - 1] = nums[i];
            count[digit]--;
        }
        for (int i = 0; i < n; i++) {
            nums[i] = sorted[i];
        }
        exp *= 10;
    }
    return sorted;
}
