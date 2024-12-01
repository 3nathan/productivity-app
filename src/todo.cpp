#include "todo.h"
#include "item.h"
#include "dashboard.h"
#include <iostream>

void Todo::add_item() {
    add_item(get_item_from_user());
}

void Todo::add_item(const Item _item) {
    items.push_back(_item);
}

void Todo::remove_item(const Item* _item) {
    auto it = std::begin(items) + (_item - &items[0]);

    items.erase(it);
}

void Todo::pretty_print() const {
    for (auto it {std::begin(items)}; it != std::end(items); ++it) {
        std::cout << it->name << std::endl;
        
        if (std::next(it) != std::end(items)) {
            std::cout << "\n\n\n";
        }
    }
}
