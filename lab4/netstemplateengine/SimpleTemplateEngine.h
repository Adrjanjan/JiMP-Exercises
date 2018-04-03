//
// Created by adrja on 02.04.2018.
//

#ifndef JIMP_EXERCISES_VIEW_H
#define JIMP_EXERCISES_VIEW_H

#include <string>
#include <unordered_map>

namespace nets {
    class View {
    public:
        std::string Render(const std::unordered_map<std::string, std::string> &model) const;

    private:
    };
}

#endif //JIMP_EXERCISES_VIEW_H
