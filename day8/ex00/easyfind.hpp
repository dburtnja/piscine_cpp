//
// Created by denys on 07.07.19.
//

#pragma once

#include <algorithm>

template <typename T>
int easyfind(const T &container, int value) {
    auto result = std::find(container.begin(), container.end(), value);
    if (result != container.end())
        return std::distance(container.begin(), result);
    return -1;
}