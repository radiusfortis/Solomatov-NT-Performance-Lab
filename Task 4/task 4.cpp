#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{    

    ifstream file(argv[1]);
    vector<int> nums;
    int num;
    while (file >> num) {
        nums.push_back(num);
    }
    file.close();
    sort(nums.begin(), nums.end());
    int median = nums[nums.size() / 2];
    int moves = 0;
    for (int n : nums) {
        moves += abs(n - median);
    }

    if (moves <= 20) {
        cout << moves << endl;
    } else {
        cout << "20 hodov nedostatochno dlya privedeniya vseh elementov massiva k odnomu chislu" << endl;
    }
    return 0;
}
