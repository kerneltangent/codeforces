#include <unordered_map>
#include <iostream>
#include <vector>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int T;
    std::cin >> T;

    while(T--) {
        int N;
        std::cin >> N;

        std::vector<int> A(N);
        std::vector<int> count(101, 0);
        for(int i = 0; i < N; ++i) {
            std::cin >> A[i];
            ++count[A[i]];
        }

        int use_count = 0;
        for(auto &a : count) {
            if (a > 1) {
                ++use_count;
            }
        }

        if (use_count < 2) {
            std::cout << -1 << std::endl;
            continue;
        }

        int m_ptr = 0;
        int mask[3] = {3, 4, 5};
        std::vector<bool> used(101, false);
        std::vector<int> ass_val(101, 3);
        for (auto &a : A) {
            if (!used[a] && count[a] > 1) {
                ass_val[a] = mask[(m_ptr++) % 2];
                used[a] = true;
            } else if (count[a] < 2) {
                ass_val[a] = mask[0];
            }
        }

        std::vector<int> ans;
        for(auto &a : A)
            used[a] = false;
        for (auto &a : A) {
            int i = (ass_val[a] - 1) / 2;
            int j = ass_val[a] - i;
            ans.push_back((used[a] ? j : i));
            used[a] = true;
        }

        for (auto &a : ans) {
            std::cout << a << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}