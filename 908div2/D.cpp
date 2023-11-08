#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T;
    std::cin >> T;

    while(T--) {
        int N, M;
        std::cin >> N >> M;

        std::vector<int> An(N);
        std::vector<int> Bm(M);
        for (auto &a : An) {
            std::cin >> a;
        }
        for (auto &b : Bm) {
            std::cin >> b;
        }
        std::sort(Bm.begin(), Bm.end());

        std::reverse(An.begin(), An.end());
        while(!An.empty()) {
            while (!Bm.empty() && Bm.back() > An.back()) {
                std::cout << Bm.back() << " ";
                Bm.pop_back();
            }
            std::cout << An.back() << " ";
            An.pop_back();
        }
        while(!Bm.empty()) {
            std::cout << Bm.back() << " ";
            Bm.pop_back();
        }
        std::cout << std::endl;
    }

    return 0;
}