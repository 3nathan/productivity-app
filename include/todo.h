#ifndef __TODO__
#define __TODO__

#include "item.h"
#include "dashboard.h"
#include <vector>
#include <cstdint>

class Todo : Dashboard {
public:
    void add_item() override;
    void add_item(const Item _item) override;
    void remove_item(const Item* _item) override;

private:
    const struct {
        std::string name;
        std::string desc;

        Type type;
    } params;

    std::vector<Item> items;
};

#endif
