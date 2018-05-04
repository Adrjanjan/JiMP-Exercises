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
    std::regex capture_point_pattern{R"(\{\{([^{|}]+)\}\})"};

    std::smatch capture_points, temp_capt_pts;
    std::string rendered = template_;
    std::string temp, final;

    while (std::regex_search(rendered, capture_points, capture_point_pattern)) {

        final += capture_points.prefix();
        temp = capture_points.str();

        if (std::regex_search(temp, temp_capt_pts, capture_point_pattern)) {
            auto it = model.find(temp_capt_pts[1]);
            if (it != model.end()) {
                final += it->second;
            }
        }
        rendered = capture_points.suffix();
    }
    final += rendered;

    return final;
}

