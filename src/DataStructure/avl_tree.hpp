#ifndef ALGORITHM_AVL_TREE_HPP
#define ALGORITHM_AVL_TREE_HPP 1

/**
 * @brief AVL木
 * @docs docs/DataStructure/avl_tree.md
 */

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>

namespace algorithm {

template <typename T>
class AVL {
public:
    using value_type = T;
    using size_type = ssize_t;

private:
    struct Node {
        T value;
        size_type height;
        Node *children[2];
        Node *neighbors[2];
        Node() : Node(0, nullptr, nullptr) {}
        explicit Node(T value_, Node *pre, Node *next) : value(value_), height(1), children{nullptr, nullptr}, neighbors{pre, next} {}
    };

    class Iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
        friend class AVL;

    public:
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T *;
        using reference = T &;
        using iterator_category = std::bidirectional_iterator_tag;

    private:
        Node *p;

    public:
        Iterator() : p(nullptr) {}
        Iterator(Node *p_) : p(p_) {}
        Iterator(const Iterator &iter) : p(iter.p) {}

        const T &operator*() { return p->value; };
        Iterator &operator++() {
            p = p->neighbors[1];
            return *this;
        }
        Iterator &operator--() {
            p = p->neighbors[0];
            return *this;
        }
        Iterator operator++(int) {
            Iterator res = *this;
            ++(*this);
            return res;
        }
        Iterator operator--(int) {
            Iterator res = *this;
            --(*this);
            return res;
        }
        bool operator==(const Iterator &iter) { return p == iter.p; }
        bool operator!=(const Iterator &iter) { return p != iter.p; }
    };

public:
    using const_iterator = Iterator;
    using iterator = const_iterator;

private:
    size_type m_sz;  // m_sz:=(要素数).
    Node *m_root;    // m_root:=(根のポインタ).
    const_iterator m_begin, m_end;

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
    bool add(Node **node, const T &value, Node *neighbors[2]) {
        if(!(*node)) {
            *node = new Node(value, neighbors[0], neighbors[1]);
            neighbors[0]->neighbors[1] = neighbors[1]->neighbors[0] = *node;
            m_sz++;
            return true;
        }
        if(value == (*node)->value) return false;
        int l = (value < (*node)->value ? 0 : 1);
        int r = 1 - l;
        neighbors[r] = *node;
        auto res = add(&(*node)->children[l], value, neighbors);
        if(res) {
            (*node)->height = calc_height(*node);
            modify_tree(node);
        }
        return res;
    }
    bool sub(Node **node, const T &value) {
        if(!(*node)) return false;
        if(value == (*node)->value) {
            if((*node)->height == 1) {
                (*node)->neighbors[0]->neighbors[1] = (*node)->neighbors[1];
                (*node)->neighbors[1]->neighbors[0] = (*node)->neighbors[0];
                delete *node;
                *node = nullptr;
                m_sz--;
                return true;
            }
            int l = ((*node)->children[0] ? 0 : 1);
            Node *next_node = (*node)->neighbors[l];
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
    const_iterator find(Node *node, const T &value) const {
        if(!node) return cend();
        if(node->value == value) return const_iterator(node);
        if(value < node->value) return find(node->children[0], value);
        return find(node->children[1], value);
    }
    const_iterator lower_bound(Node *node, const T &value) const {
        assert(node);
        if(value < node->value) {
            if(!node->children[0]) return const_iterator(node);
            return lower_bound(node->children[0], value);
        }
        if(node->value == value) return const_iterator(node);
        if(!node->children[1]) return const_iterator(node->neighbors[1]);
        return lower_bound(node->children[1], value);
    }
    const_iterator upper_bound(Node *node, const T &value) const {
        assert(node);
        if(value < node->value) {
            if(!node->children[0]) return const_iterator(node);
            return upper_bound(node->children[0], value);
        }
        if(!node->children[1]) return const_iterator(node->neighbors[1]);
        return upper_bound(node->children[1], value);
    }

public:
    AVL() : m_sz(0), m_root(nullptr), m_begin(new Node()), m_end(new Node()) {
        m_begin.p->neighbors[1] = m_end.p;
    }

    size_type size() const { return m_sz; }
    iterator begin() const { return cbegin(); }
    iterator end() const { return cend(); }
    const_iterator cbegin() const {
        const_iterator iter = m_begin;
        return ++iter;
    }
    const_iterator cend() const { return m_end; }
    bool insert(const T &value) {
        Node *neighbors[2] = {m_begin.p, m_end.p};
        return add(&m_root, value, neighbors);
    }
    bool erase(const T &value) { return sub(&m_root, value); }
    const_iterator find(const T &value) const { return find(m_root, value); }
    const_iterator lower_bound(const T &value) const {
        if(!m_root) return cbegin();
        return lower_bound(m_root, value);
    }
    const_iterator upper_bound(const T &value) const {
        if(!m_root) return cbegin();
        return upper_bound(m_root, value);
    }
};

}  // namespace algorithm

#endif
