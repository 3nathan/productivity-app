#include "chart.h"
#include "item.h"

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

void Chart::remove_item(const Item* _item) {}

void Chart::update_levels() {
    // bfs through to find
}
