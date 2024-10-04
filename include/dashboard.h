#ifndef __DASHBOARD__
#define __DASHBOARD__

#include "item.h"
#include <cstdint>

enum Type {
    List,
    Gantt
};

class Dashboard {
public:
    virtual void add_item() = 0;
    virtual void add_item(const Item _item) = 0;
    virtual void remove_item(const Item* _item) = 0;

protected:
    [[nodiscard]] Item get_item_from_user() const;

private:
    const struct {
        std::string name;
        std::string desc;

        Type type;
    } params;
};

#endif
