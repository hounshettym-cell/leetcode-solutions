#include <string>
#include <vector>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int n = static_cast<int>(num1.size());
        int m = static_cast<int>(num2.size());

        std::vector<int> result(n + m, 0);

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';

                int product = digit1 * digit2;

                int pos1 = i + j;
                int pos2 = i + j + 1;

                int sum = product + result[pos2];

                result[pos2] = sum % 10;
                result[pos1] += sum / 10;
            }
        }

        std::string ans = "";

        for (int digit : result) {
            if (ans.empty() && digit == 0) {
                continue;
            }

            ans += static_cast<char>(digit + '0');
        }

        return ans;
    }
};