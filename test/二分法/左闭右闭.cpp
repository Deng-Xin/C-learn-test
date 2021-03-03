/*************************************************************************************
 * Filename     : 左闭右闭.c
 * Author       : XIN
 * Description  : 给定一个排序数组和一个目标值,在数组中找到目标值,并返回其索引。
 *                如果目标值不存在于数组中,返回它将会被顺序插入的位置。
 *                假设数组中无重复元素。
 *                采用二分法,左闭右闭区间处理。
 * Date         : 2021-03-03 14:27:23
 * LastEditTime : 2021-03-03 14:29:16
 * Version      :
 * History      :
 *************************************************************************************/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1; // 我们定义target在左闭右闭的区间里，[left, right]，这个区间的定义就是我们的不变量，接下来，要在下面的循环中，坚持这个不变量，我们就知道其中的边界条件应该怎么判断了
        while (left <= right) { // 为什么是<=呢，因为当left==right，区间[left, right]依然有效
            int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target 在左区间，因为我们的区间是左闭右闭的区间，nums[middle]一定不是我们的目标值，所以在right = middle - 1在[left, middle - 1]区间中继续寻找目标值
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，所以[middle + 1, right]
            } else { // nums[middle] == target
                return middle;
            }
        }
        // 分别处理如下四种情况
        // 目标值在数组所有元素之前，此时区间为[0, -1]，所以return right + 1
        // 目标值等于数组中某一个元素  return middle;
        // 目标值插入数组中的位置，一定是我们查找的范围 [left, right]之后，return  right + 1
        // 目标值在数组所有元素之后的情况，也是我们查找的范围 [left, right]之后， return right + 1
        return right + 1;
    }
};