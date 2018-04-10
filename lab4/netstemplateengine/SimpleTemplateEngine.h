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
        View(std::string template_str);

        std::string Render(const std::unordered_map<std::string, std::string> &model) const;

    private:
        std::string template_;
    };
}

#endif //JIMP_EXERCISES_VIEW_H
