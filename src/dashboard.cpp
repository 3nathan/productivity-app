#include "dashboard.h"
#include "item.h"

void Dashboard::add_item() {
    Item _item {get_item_from_user()};
}

Item Dashboard::get_item_from_user() const {
    return Item {};
}
