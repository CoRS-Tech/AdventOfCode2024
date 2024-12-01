#include "Day1.h"

#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <format>

Day1::Day1() {
    input = Day1::read_file("./Inputs/Day1.txt");
    parse_input();
}

int Day1::part_1() {
    std::sort(keys.begin(), keys.end());
    std::sort(values.begin(), values.end());

    int totalDistance = 0;

    for (int i = 0; i < keys.size(); i++) {
        int nxtK = keys[i];
        int nxtV = values[i];
        int distance = std::abs(nxtK - nxtV);

        std::cout << std::format("Pair: ({}, {}), distance: {}\n", nxtK, nxtV, distance);

        totalDistance += distance;
    }

    return totalDistance;
}

int Day1::part_2() {
    int similarity = 0;

    for(size_t k = 0; k < keys.size(); k++) {
        auto key = keys[k];
        std::cout << "Key: " << key << "\n";

        int curr_rep = 0;
        std::string valuesStr;

        for(size_t v = 0; v < values.size(); v++) {
            auto value = values[v];

            if(key == value) {
                curr_rep++;
                valuesStr += format("[{}] {}, ", v, std::to_string(value));
            }
        }

        if(!valuesStr.empty()) {
            std::cout << format("[{}] Found match(es): {}\n", k, valuesStr);
        }

        int curr_sim = key * curr_rep;

        std::cout << std::format("Similarity for key ({}) is {}\n", key, curr_sim);
        similarity += curr_sim;
    }

    return similarity;
}

std::string Day1::read_file(const std::string& filePath) {
    std::ifstream file(filePath);
    std::ostringstream buffer;

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filePath);
    }

    buffer << file.rdbuf();
    return buffer.str();
}

void Day1::parse_input() {
    std::istringstream stream(input);
    std::string line;

    while (std::getline(stream, line)) {
        std::istringstream lineStream(line);
        int key, value;
        lineStream >> key >> value;

        keys.push_back(key);
        values.push_back(value);
    }
}
