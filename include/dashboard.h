#ifndef __DASHBOARD__
#define __DASHBOARD__

#include "item.h"
#include <vector>
#include <cstdint>

enum DashboardType {
    ToDoList,
    ProductivityChart
};

class Dashboard {
public:
    void add_item();
    void remove_item();

private:
    const struct {
        std::string name;
        std::string desc;

        DashboardType type;
    } params;

    std::vector<Item> items;

    [[nodiscard]] Item get_item_from_user() const;
};

#endif
