#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "utils.hh"

int constexpr LOWER_BOUND = 234208;
int constexpr UPPER_BOUND = 765869;

bool two_same_adjacent_digits(int number) {
    auto const number_str = std::to_string(number);
    for (std::size_t i = 0; i < number_str.size() - 1; i++) {
        if (number_str.at(i) == number_str.at(i + 1)) return true;
    }
    return false;
}

bool only_two_same_adjacent_digits(int number) {
    auto only_two = false;
    auto const number_str = std::to_string(number);
    for (std::size_t i = 0; i < number_str.size() - 1; i++) {
        if (number_str.at(i) == number_str.at(i + 1)) {
            if (i == 0 || number_str.at(i) != number_str.at(i - 1)) {
                if (i == number_str.size() - 2 || number_str.at(i) != number_str.at(i + 2))
                    only_two = true;
            }
        }
    }
    return only_two;
}

bool never_decreasing(int number) {
    auto const number_str = std::to_string(number);
    for (std::size_t i = 1; i < number_str.size(); i++) {
        auto const n2 = static_cast<int>(number_str.at(i)) - 48;
        auto const n1 = static_cast<int>(number_str.at(i - 1)) - 48;

        if (n2 < n1) return false;
    }

    return true;
}

int part_one() {
    int count = 0;
    for (int i = LOWER_BOUND; i <= UPPER_BOUND; i++) {
        if (two_same_adjacent_digits(i) && never_decreasing(i)) count++;
    }
    return count;
}

int part_two() {
    int count = 0; 
    for (int i = LOWER_BOUND; i <= UPPER_BOUND; i++) {
        if (only_two_same_adjacent_digits(i) && never_decreasing(i)) count++;
    }

    return count;
}

int main() {
    auto const p1_ans = part_one();
    auto const p2_ans = part_two(); 
    std::cout << "Part 1: " << p1_ans << std::endl;
    std::cout << "Part 2: " << p2_ans << std::endl;
}