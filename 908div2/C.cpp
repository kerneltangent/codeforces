#include <iostream>
#include <vector>
#include <set>


std::string verify_informant_claim(int n, int k, const std::vector<int>& b) {
    int s = 1;
    k = std::min(k, n);

    for (int i = 0; i < k; ++i) {
        int last_element = b[(s - 1 + n - 1) % n];

        if (last_element > n) {
            return "No";
        }

        s = (s - last_element + n) % n;
        if (s == 0) s = n;
    }
    return "Yes";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int T;
    std::cin >> T;

    while(T--) {
        int N, K;
        std::cin >> N >> K;

        std::vector<int> A(N);
        for(auto &a : A)
            std::cin >> a;

        std::cout << (verify_informant_claim(N, K, A)) << std::endl;
    }

    return 0;
}