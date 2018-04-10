//
// Created by adrja on 02.04.2018.
//

#include "SimpleTemplateEngine.h"
#include <utility>
#include <regex>
#include <iostream>

nets::View::View(std::string template_str) {
    template_ = std::move(template_str);

}

std::string nets::View::Render(const std::unordered_map<std::string, std::string> &model) const {
    std::regex capture_point_pattern{"(\\{\\{\\w+\\}\\})"};
    std::string temp;
    std::smatch capture_points;
    std::string rendered = template_;
    bool found;

    rendered = template_;
    while (std::regex_search(rendered, capture_points, capture_point_pattern)) {
        found = false;
        for (auto &n : model) {
            temp = "{{" + n.first + "}}";
            if (capture_points[0] == temp) {
                found = true;
                rendered.replace(capture_points.position(), capture_points.length(), n.second);
            }
        }
        if (!found) {
            rendered.replace(capture_points.position(), capture_points[0].length(), "");
        }
    }
    return rendered;
}
