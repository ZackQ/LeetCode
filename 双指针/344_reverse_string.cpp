class Solution {
public:
    string reverseString(string s) {
        if (s.size() <= 1)
            return s;
        int len = s.size();
        int i = 0; int j = len - 1;
        while (i < j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++, j--;
        }
        return s;
    }
};