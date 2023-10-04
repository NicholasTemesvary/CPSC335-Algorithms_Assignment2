#include "sorting_algorithms.h"

// TODO
vector<int> count_sort(vector<int> nums){
    int max_num = nums[0];
    for (int num : nums) {
        if (num > max_num) {
            max_num = num;
        }
    }
    std::vector<int> count(max_num + 1, 0);
    for (int num : nums) {
        count[num]++;
    }
    std::vector<int> sorted(nums.size());
    int index = 0;
    for (int i = 0; i <= max_num; i++) {
        while (count[i] > 0) {
            sorted[index] = i;
            index++;
            count[i]--;
        }
    }
    return sorted;
}
