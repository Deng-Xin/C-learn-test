/*************************************************************************************
 * Filename     : 左闭右开.cpp
 * Author       : XIN
 * Description  : 给定一个排序数组和一个目标值,在数组中找到目标值,并返回其索引。
 *                如果目标值不存在于数组中,返回它将会被顺序插入的位置。
 *                假设数组中无重复元素。
 *                采用二分法,左闭右开区间处理。
 * Date         : 2021-03-03 14:29:37
 * LastEditTime : 2021-03-03 14:29:56
 * Version      :
 * History      :
 *************************************************************************************/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n; // 我们定义target在左闭右开的区间里，[left, right)  这是
        while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target) {
                right = middle; // target 在左区间，因为是左闭右开的区间，nums[middle]一定不是我们的目标值，所以right = middle，在[left, middle)中继续寻找目标值
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，在 [middle+1, right)中
            } else { // nums[middle] == target
                return middle; // 数组中找到目标值的情况，直接返回下标
            }
        }
        // 分别处理如下四种情况
        // 目标值在数组所有元素之前，此时区间为 [0,0)，所以可以return right
        // 目标值等于数组中某一个元素 return middle
        // 目标值插入数组中的位置 [left, right) ，return right 即可
        // 目标值在数组所有元素之后的情况 [left, right)，return right 即可
        return right;
    }
};