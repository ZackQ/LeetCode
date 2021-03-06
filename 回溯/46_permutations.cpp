#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int> &nums);
	void help(vector<int> &nums, vector<vector<int>> &ret, vector<int> &curr, int index);
};

// 暴力递归思路
// 加上回溯
// 先选定当前数组中某个值作为第一个值，然后接下去递归排列
// 返回时，需要把之前的值复原，不影响其他排列的递归
vector<vector<int>> Solution::permute(vector<int> &nums) {
	vector<vector<int>> ret;
	vector<int> curr;
	help(nums, ret, curr, 0);
	return ret;
}

void Solution::help(vector<int> &nums, vector<vector<int>> &ret, vector<int> &curr, int index) {
	// base condition
	if (index == nums.size() - 1) {
		curr.push_back(nums[index]);
		ret.push_back(curr);
		curr.pop_back();
		return;
	}
	// recursive condition
	for (int i = index; i <= nums.size() - 1; i++) {
		// 交换index处和i处的值，然后选择index处的值push到curr数组，继续递归
		// 返回后交换回原位置
		int temp = nums[index];
		nums[index] = nums[i];
		nums[i] = temp;
		curr.push_back(nums[index]);
		help(nums, ret, curr, index + 1);
		nums[i] = nums[index];
		nums[index] = temp;
		curr.pop_back();
	}
}
// 第二个版本，3个月后的简洁一些，进步一些的代码
class Solution {
public:
	vector<vector<int>> permute(vector<int> &nums);
};


inline void swap(vector<int>& nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void permute(vector<int>& nums, int idx, vector<vector<int>>& ans) {
	if (idx == nums.size()) {
		ans.push_back(nums);
		return;
	}
	for (int i = idx; i < nums.size(); i++) {
		swap(nums, idx, i);
		permute(nums, idx+1, ans);
		swap(nums, idx, i);
	}
}

vector<vector<int>> Solution::permute(vector<int> &nums) {
	vector<vector<int>> ans;
	if (nums.empty()) return ans;
	::permute(nums, 0, ans);
	return ans;
}

// 给出一种全排列方法，直接使用STL库
vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ret;
    if (nums.empty()) return ret;
    sort(nums.begin(), nums.end());
    do {
        ret.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    return ret;
}


int main(int argc, char *argv[]) {
	vector<int> nums = {1,2,3};
	Solution solu;
	auto ret = solu.permute(nums);
	for (auto &c : ret) {
		for (auto var : c) {
			cout << var << ' ';
		}
		cout << endl;
	}
	return 0;
}
