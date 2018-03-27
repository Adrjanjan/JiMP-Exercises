//
// Created by adrja on 22.03.2018.
//

#include "SmartTree.h"


namespace datastructures {

    std::unique_ptr<SmartTree> CreateLeaf(int value) {
        std::unique_ptr<SmartTree> leaf(new SmartTree);
        leaf->value = value;
        leaf->left = nullptr;
        leaf->right = nullptr;
        leaf->parent = nullptr;

        return std::move(leaf);

    }

    std::unique_ptr<SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree,
                                               std::unique_ptr<SmartTree> left_subtree) {

        tree->left = std::move(left_subtree);
        return std::move(tree);
    }

    std::unique_ptr<SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree,
                                                std::unique_ptr<SmartTree> right_subtree) {
        tree->right = std::move(right_subtree);
        return std::move(tree);
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {

        if (unique_ptr != nullptr) {
            if (unique_ptr->left != nullptr) {
                PrintTreeInOrder(unique_ptr->left, out);
            }
            (*out) << (unique_ptr->value) << ", ";

            if (unique_ptr->right != nullptr) {
                PrintTreeInOrder(unique_ptr->right, out);
            }
        }
    }

    void MakeEncode(const std::unique_ptr<SmartTree> &tree, std::string *encoded) {

        if (tree != nullptr) {
            (*encoded) += "[" + std::to_string(tree->value) + " ";
            MakeEncode(tree->left, encoded);
            tree->left = nullptr;
            (*encoded) += "] ";
            MakeEncode(tree->right, encoded);
            tree->right = nullptr;
        } else {
            (*encoded) += "none ";
        }
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree) {
        std::string encoded_tree{};
        MakeEncode(tree, &encoded_tree);
        return encoded_tree;
    }

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree) {

        std::string left{}, right{}, value{};
        int i = 1, count = 1;

        while (tree[i] != ' ' && tree[i] != ']')
            [

            ]

        while (count != 0) {
            left += tree[i];
            if (tree[i] == '[') ++count;
            if (tree[i] == ']') --count;
            left += tree[i++];
        }
        for (i; i < tree.length(); ++i) {
            right += tree[i];
        }
        if (value == "none") {
            return nullptr;
        }
        ++i;


    }
}