#ifndef ALGORITHM_AVL_TREE_HPP
#define ALGORITHM_AVL_TREE_HPP 1

/**
 * @brief AVL木
 * @docs docs/DataStructure/avl_tree.md
 */

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>

namespace algorithm {

template <typename T>
class AVL {
public:
    using value_type = T;
    using size_type = int32_t;

private:
    struct Node {
        T value;
        size_type height;
        Node *children[2];
        explicit Node(T value_) : value(value_), height(1), children{nullptr, nullptr} {}
    };

    size_type m_sz;  // m_sz:=(要素数).
    Node *m_root;    // m_root:=(根のポインタ).

    size_type calc_height(Node *node) const {
        if(!node) return 0;
        size_type res = 1;
        res = std::max(res, (node->children[0] ? node->children[0]->height : 0) + 1);
        res = std::max(res, (node->children[1] ? node->children[1]->height : 0) + 1);
        return res;
    }
    size_type deviation(Node *node) const {
        assert(node);
        size_type l = (node->children[0] ? node->children[0]->height : 0);
        size_type r = (node->children[1] ? node->children[1]->height : 0);
        return l - r;
    }
    void rotate(Node **node, bool is_right) {
        assert(*node);
        int l = (is_right ? 0 : 1);
        int r = 1 - l;
        assert((*node)->children[l]);
        Node *left = (*node)->children[l];
        (*node)->children[l] = left->children[r];
        (*node)->height = calc_height(*node);
        left->children[r] = *node;
        left->height = calc_height(left);
        *node = left;
    }
    void modify_tree(Node **node) {
        assert(*node);
        size_type bias = deviation(*node);
        assert(std::abs(bias) <= 2);
        if(std::abs(bias) <= 1) return;
        bool is_right = (bias >= 0);
        int l = (is_right ? 0 : 1);
        size_type bias2 = deviation((*node)->children[l]);
        assert(std::abs(bias2) <= 1);
        if(bias2 == (is_right ? -1 : 1)) rotate(&(*node)->children[l], !is_right);
        rotate(node, is_right);
    }
    bool add(Node **node, T value, bool enable_duplication) {
        if(!(*node)) {
            *node = new Node(value);
            m_sz++;
            return true;
        }
        if(value == (*node)->value and !enable_duplication) return false;
        int l = (value < (*node)->value ? 0 : 1);
        auto res = add(&(*node)->children[l], value, enable_duplication);
        if(res) {
            (*node)->height = calc_height(*node);
            modify_tree(node);
        }
        return res;
    }
    bool sub(Node **node, T value) {
        if(!(*node)) return false;
        if(value == (*node)->value) {
            if((*node)->height == 1) {
                delete *node;
                *node = nullptr;
                m_sz--;
                return true;
            }
            int l = ((*node)->children[0] ? 0 : 1);
            int r = 1 - l;
            Node *next_node = (*node)->children[l];
            while(next_node->children[r]) next_node = next_node->children[r];
            (*node)->value = next_node->value;
            sub(&(*node)->children[l], (*node)->value);
            (*node)->height = calc_height(*node);
            modify_tree(node);
            return true;
        }
        int l = (value < (*node)->value ? 0 : 1);
        auto res = sub(&(*node)->children[l], value);
        if(res) {
            (*node)->height = calc_height(*node);
            modify_tree(node);
        }
        return res;
    }
    bool find(Node *node, T value) const {
        if(!node) return false;
        if(node->value == value) return true;
        if(value < node->value) return find(node->children[0], value);
        return find(node->children[1], value);
    }
    void print(std::ostream &os, Node *node, bool &first) const {
        if(!node) return;
        print(os, node->children[0], first);
        os << (first ? "" : " ") << node->value << "-" << node->height;
        first = false;
        print(os, node->children[1], first);
    }

public:
    AVL() : m_sz(0), m_root(nullptr) {}

    size_type size() const { return m_sz; }
    bool add(T value, bool enable_duplication = false) { return add(&m_root, value, enable_duplication); }
    bool sub(T value) { return sub(&m_root, value); }
    bool find(T value) const { return find(m_root, value); }
    void print(std::ostream &os) const {
        bool first = true;
        os << "[";
        print(os, m_root, first);
        os << "]";
    }

    friend std::ostream &operator<<(std::ostream &os, const AVL &ob) {
        ob.print(os);
        return os;
    }
};

}  // namespace algorithm

#endif
