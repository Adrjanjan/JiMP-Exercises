//
// Created by adrja on 22.03.2018.
//

#include "MinimalTimeDifference.h"

namespace minimaltimedifference {

    unsigned int ToMinutes(std::string time_HH_MM) {

        unsigned int hours = 0, minutes = 0;
        if (time_HH_MM[1] == ':') {
            hours = static_cast<unsigned int>(60 * (time_HH_MM[0] - '0'));
            minutes = static_cast<unsigned int> (10 * (time_HH_MM[2] - '0') + (time_HH_MM[3] - '0'));
        } else {
            hours = static_cast<unsigned int> (60 * (10 * (time_HH_MM[0] - '0') + (time_HH_MM[1] - '0')));
            minutes = static_cast<unsigned int>( 10 * (time_HH_MM[3] - '0') + (time_HH_MM[4] - '0'));
        }
        return hours + minutes;

    }

    unsigned int MinimalTimeDifference(std::vector<std::string> times) {

        unsigned int minimial_difference = INT32_MAX;
        unsigned int x;
        for (int i = 0; i < times.size() - 1; ++i) {
            for (int j = i + 1; j < times.size(); ++j) {
                x = static_cast<unsigned int>(abs(ToMinutes(times[i]) - ToMinutes(times[j])));
                if (x < minimial_difference) {
                    minimial_difference = x;
                }
                if (24 * 60 - x < minimial_difference) {
                    minimial_difference = 24 * 60 - x;
                }
            }
        }
        return minimial_difference;
    }

}