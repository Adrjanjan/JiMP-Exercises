//
// Created by adrja on 21.04.2018.
//


#include "Zipper.h"

using ::datastructures::Zipper;

std::pair<std::string, int> datastructures::ZipperIterator::operator*() const {
    return std::make_pair((*zipped_it_.first), *(zipped_it_.second));
}

datastructures::ZipperIterator &datastructures::ZipperIterator::operator++() {
    ++zipped_it_.first;
    ++zipped_it_.second;
    return *this;
}

bool datastructures::ZipperIterator::operator!=(const datastructures::ZipperIterator &other) const {
    return !(zipped_it_.first == other.zipped_it_.first && zipped_it_.second == other.zipped_it_.second);
}

datastructures::ZipperIterator::ZipperIterator(std::vector<std::string>::iterator is, std::vector<int>::iterator ii) {
    zipped_it_.first = is;
    zipped_it_.second = ii;
}

Zipper datastructures::Zipper::zip(const std::vector<std::string> &vs, const std::vector<int> &vi) {
    Zipper zip = Zipper();
    zip.zipped_.first = vs;
    zip.zipped_.second = vi;

    if (vs.size() == vi.size()) return zip;

    bool first_longer = vs.size() > vi.size();
    if (first_longer) {
        while (first_longer) {
            zip.zipped_.second.emplace_back(0);
            first_longer = zip.zipped_.first.size() > zip.zipped_.second.size();
        }
    } else {
        while (!first_longer) {
            zip.zipped_.first.emplace_back("");
            first_longer = zip.zipped_.first.size() >= zip.zipped_.second.size();
        }
    }

    return zip;
}

datastructures::ZipperIterator datastructures::Zipper::begin() {
    ZipperIterator zip_it = ZipperIterator(zipped_.first.begin(), zipped_.second.begin());
    return zip_it;
}

datastructures::ZipperIterator datastructures::Zipper::end() {
    ZipperIterator zip_it = ZipperIterator(zipped_.first.end(), zipped_.second.end());
    return zip_it;
}

