#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 思路
// 
// 我们可以枚举字符串中的每一个位置作为右端点，然后找到其最远的左端点的位置
// 满足该区间内除了出现次数最多的那一类字符之外，剩余的字符（即非最长重复字符）数量不超过 k 个
// 这样我们可以想到使用双指针维护这些区间，每次右指针右移，
// 如果区间仍然满足条件，那么左指针不移动，否则左指针至多右移一格，保证区间长度不减小。
// 虽然这样的操作会导致部分区间不符合条件，即该区间内非最长重复字符超过了 k个
// 但是这样的区间也同样不可能对答案产生贡献。当我们右指针移动到尽头，
// 左右指针对应的区间的长度必然对应一个长度最大的符合条件的区间
// 
// 总结
// 1.替换应该想到首先选定一个区间，然后找到区间内重复出现的次数最多的字符
//   考虑这个问题，利用hash表存储每个字符在当前区间内出现的次数，注意区间更新时，hash表的更新
// 2.区间动，应该想到滑动窗口和利用双指针维护滑动窗口
// 3.这样做法的正确性：左指针至多右移一格，保证了窗口大小一直为最大值。
//   因为前面存在一个最大值，右指针右移一格，左指针左移一格，因此窗口目前虽然保证的不是目前的最大值，但是却是前面出现过的最大值。
// 4.每次计算区间内除了重复字符个数外，剩下的字符的个数，如果满足<k，则右指针可以继续往右移动一次
//   否则左指针移动

// https://leetcode-cn.com/problems/longest-repeating-character-replacement/solution/ti-huan-hou-de-zui-chang-zhong-fu-zi-fu-eaacp/

class Solution {
public:
    int characterReplacement(string s, int k) {
        
    }
};