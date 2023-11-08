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

        std::string S;
        std::cin >> S;

        char winner = S.back();

        if (N == 1) {
            std::cout << winner << std::endl;
            continue;
        }

        auto solve_for_x = [](int X, std::string& S, char winner) {
            int count[2] = {0, 0};
            int points[2] = {0, 0};

            for (auto const &c : S) {
                if (++points[c - 'A'] == X) {
                    points[0] = points[1] = 0;
                    ++count[c - 'A'];
                }
            }

            // std::cout << X << " " << count[0] << " " << count[1] << " " << winner << std::endl;
            return count[winner - 'A'] > count[(winner - 'A')^1];
        };

        bool solved = false;
        for (int X = 1; X <= N; ++X) {
            if (solve_for_x(X, S, winner)) {
                std::cout << winner << std::endl;
                solved = true;
                break;
            }
        }

        if (!solved) {
            std::cout << "?" << std::endl;
        }
    }

    return 0;
}