#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int constexpr ADD_OP = 1;
int constexpr MULT_OP = 2;
int constexpr HALT_OP = 99;

int constexpr target_output = 19690720;

int perform_op(std::vector<int> input, int noun = 12, int verb = 2) {
    std::size_t idx = 0;
    input[1] = noun;
    input[2] = verb;
    while (true) {
        int op = input[idx];
        int res;
        
        if (op == HALT_OP) { 
            break;
        } else if (op == ADD_OP) {
            res = input[input[idx + 1]] + input[input[idx + 2]];
        } else { // mult op 
            res = input[input[idx + 1]] * input[input[idx + 2]];
        }
        
        input[input[idx + 3]] = res;
        idx += 4;
    }

    return input[0];
}

int part_one(std::vector<int>& input) {
    return perform_op(input);
}

int part_two(std::vector<int>& input) {
    for (std::uint32_t noun = 0; noun < 100; noun++) {
        for (std::uint32_t verb = 0; verb < 100; verb++) {
            if (perform_op(input, noun, verb) == target_output) {
                return 100 * noun + verb;
            }
        }
    }
}

int main() {
    std::vector<int> input = {1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,1,10,19,1,6,19,23,2,23,6,27,2,6,27,31,2,13,31,35,1,10,35,39,2,39,13,43,1,43,13,47,1,6,47,51,1,10,51,55,2,55,6,59,1,5,59,63,2,9,63,67,1,6,67,71,2,9,71,75,1,6,75,79,2,79,13,83,1,83,10,87,1,13,87,91,1,91,10,95,2,9,95,99,1,5,99,103,2,10,103,107,1,107,2,111,1,111,5,0,99,2,14,0,0};
    
    auto const p1_start = std::chrono::steady_clock::now();
    auto const p1_ans = part_one(input);
    auto const p1_end = std::chrono::steady_clock::now();

    auto const p2_start = std::chrono::steady_clock::now();
    auto const p2_ans = part_two(input);
    auto const p2_end = std::chrono::steady_clock::now();

    auto const p1_time_ms = std::chrono::duration <double, std::milli>(p1_end - p1_start).count();
    auto const p2_time_ms = std::chrono::duration <double, std::milli>(p2_end - p2_start).count();

    std::cout << "Part 1: " << p1_ans << "\tExecuted in ( with -O3 ): " << p1_time_ms <<  " ms" << std::endl;
    std::cout << "Part 2: " << p2_ans << "\tExecuted in ( with -O3 ): " << p2_time_ms << " ms" << std::endl;

    return 0;
}