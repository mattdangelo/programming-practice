//
// Created by Matt on 17/01/2021.
//

#include "result.h"

result::result(bool success, int first, int second, int third) {
    this->success = success;
    this->first = first;
    this->third = third;
    this->second = second;
}