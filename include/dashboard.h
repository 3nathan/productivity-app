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
    virtual void pretty_print() const = 0;

protected:
    [[nodiscard]] Item get_item_from_user() const;

    void print_connecting_lines(
        const uint8_t n_upper,
        const uint8_t n_lower,
        const uint8_t n_lines = 3
    ) const;

/* private: */
/*     const struct { */
/*         std::string name; */
/*         std::string desc; */

/*         Type type; */
/*     } params; */
};

#endif
