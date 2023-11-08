#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int T;
    std::cin >> T;

    while (T--) {
        int M;
        std::cin >> M;

        std::vector<long long> N(M), L(M), R(M), S(M);
        std::vector<std::vector<long long>> a(M), c(M);

        long long sum = 0, suml = 0, sumr = 0;

        for (int idx = 0; idx < M; ++idx) {
            std::cin >> N[idx] >> L[idx] >> R[idx];
            sum += N[idx];
            suml += L[idx];
            sumr += R[idx];

            a[idx].resize(N[idx]);
            c[idx].resize(N[idx]);
            
            for (auto &value : a[idx]) {
                std::cin >> value;
            }

            S[idx] = 0;
            for (auto &cost : c[idx]) {
                std::cin >> cost;
                S[idx] += cost;
            }
        }

        if (sumr - suml > sum) {
            std::cout << "0\n";
            continue;
        }

        std::map<long long, long long> sumaa;
        std::map<long long, std::vector<std::pair<int, int>>> indexes;

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N[i]; ++j) {
                sumaa[a[i][j]] += R[i];
                indexes[a[i][j]].emplace_back(i, j);
            }
        }

        long long mincost = LLONG_MAX;
        for (long long l = suml; l <= sumr; ++l) {
            long long extra = 0, forced = 0;
            extra += sumr - sumaa[l];
            
            for (const auto &[idx, vdx] : indexes[l]) {
                long long free_cost = S[idx] - c[idx][vdx];
                if (free_cost < L[idx]) {
                    extra += L[idx];
                    forced += L[idx] - free_cost;
                } else {
                    extra += std::min(free_cost, R[idx]);
                }
            }
            mincost = std::min(mincost, forced + std::max(0LL, l - extra));
        }
        std::cout << mincost << '\n';
    }

    return 0;
}
