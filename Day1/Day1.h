#include <string>
#include <tuple>
#include <vector>

#ifndef ADVENTOFCODE_DAY1_H
#define ADVENTOFCODE_DAY1_H


#endif //ADVENTOFCODE_DAY1_H

class Day1 {

public:
    Day1();
    int part_1();
    int part_2();

private:
    std::string input;
    std::vector<int> keys;
    std::vector<int> values;

    static std::string read_file(const std::string& filePath);

    void parse_input();
};