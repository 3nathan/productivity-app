#include "chart.h"
#include "item.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

void Chart::add_item() {
    add_item(get_item_from_user());
}

void Chart::add_item(const Item _item) {
    auto item_ptr {new Item {_item}};

    if (_item.parents.empty()) {
        items.push_back(item_ptr);

        for (auto it {std::begin(_item.children)}; it != std::end(_item.children); ++it) {
            (*it)->parents.push_back(item_ptr);
        }
    }
    else {
        for (auto it {std::begin(_item.parents)}; it != std::end(_item.parents); ++it) {
            (*it)->children.push_back(item_ptr);
        }

        for (auto it {std::begin(_item.children)}; it != std::end(_item.children); ++it) {
            (*it)->parents.push_back(item_ptr);
        }

        update_levels();
    }
}

void Chart::remove_item(const Item* _item) {
    // need to check if this works
    std::vector<Item*> parents;

    if (_item->parents.empty()) {
        for (auto child_ptr {std::begin(_item->children)}; child_ptr != std::end(_item->children); ++child_ptr) {
            parents.clear();
            for (auto parent_ptr {std::begin((*child_ptr)->parents)}; parent_ptr != std::end((*child_ptr)->parents); ++parent_ptr) {
                if (*parent_ptr != _item) {
                    parents.push_back(*parent_ptr);
                }
            }
            (*child_ptr)->parents = parents;
            items.push_back(*child_ptr);
        }
    }
    else {
        // what is this going to do?
        // for each child node, replace the _item element in parent with all parents of _item
        // likewise for each parent node with all children of _item
        // remove 
    }

    delete _item;
    update_levels();
}

void Chart::update_levels() {
    // bfs through and update heirarchical level variable
    // need to check if this works
    std::unordered_map<Item*, bool> visited;
    std::vector<Item*> queue {items};
    std::vector<Item*> tmp_queue;
    uint8_t level {};

    while (queue.empty() == false) {
        tmp_queue.clear();
        for (auto it {std::begin(queue)}; it != std::end(queue); ++it) {
            if (!visited[*it]) {
                visited[*it] = true;
                (*it)->heirarchical_level = level;
                for (auto child_ptr {std::begin((*it)->children)}; child_ptr != std::end((*it)->children); ++child_ptr) {
                    if (!visited[*child_ptr]) {
                        tmp_queue.push_back(*child_ptr);
                    }
                }
            }
        }

        queue = tmp_queue;
        level++;
    }
}

std::unordered_map<uint8_t, uint8_t> Chart::get_num_items_on_level() const {
    // bfs through the list
    std::unordered_map<uint8_t, uint8_t> num_items;

    std::unordered_map<Item*, bool> visited;
    std::vector<Item*> queue {items};
    std::vector<Item*> tmp_queue;

    while (queue.empty() == false) {
        tmp_queue.clear();
        for (auto it {std::begin(queue)}; it != std::end(queue); ++it) {
            if (!visited[*it]) {
                visited[*it] = true;
                num_items[(*it)->heirarchical_level]++;

                for (auto child_ptr {std::begin((*it)->children)}; child_ptr != std::end((*it)->children); ++child_ptr) {
                    if (!visited[*child_ptr]) {
                        tmp_queue.push_back(*child_ptr);
                    }
                }
            }
        }

        queue = tmp_queue;
    }

    return num_items;
}

// what does this need to do?
//
// setup blank 'slate'
// setup positions (determined by level of item, and num items per level, and length of item name)
// for simplicity, all items will have length of 24 characters
//
// go through all parents and draw a line from the parent
// to the child
//
// blank out space for item name

void Chart::pretty_print() const {
    pretty_print(200, 80, 5);
}

void Chart::pretty_print(
    const uint8_t w,
    const uint8_t h,
    const uint8_t sep_lines
) const {
    char slate[w][h];

    
}
