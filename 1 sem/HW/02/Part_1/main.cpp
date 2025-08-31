#include <iostream>

using namespace std;

int countDigits(int num) {
    int result = 0;
    do {
        num /= 10;
        result++;
    } while (num != 0);
    return result;
}

int main() {
    const int N = 10;
    int nums[N];
    cout << "Enter nums (" << N << " elements):\n";
    for (int &num: nums)
        cin >> num;

    for (int i = 1; i < N; ++i) {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && countDigits(nums[j]) > countDigits(key)) {
            nums[j + 1] = nums[j];
            nums[j] = key;
            j--;
        }
    }

    for (const auto &elem: nums) {
        cout << elem << " ";
    }
    return 0;
}
