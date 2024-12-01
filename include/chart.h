#ifndef __CHART__
#define __CHART__

#include "item.h"
#include "dashboard.h"
#include <vector>
#include <unordered_map>

class Chart : Dashboard {
public:
    void add_item() override;
    void add_item(const Item _item) override;
    void remove_item(const Item* _item) override;
    void pretty_print() const override;

private:
    const struct {
        std::string name;
        std::string desc;

        Type type;
    } params;

    std::vector<Item*> items;

    void update_levels();

    void pretty_print(
        const uint8_t w,
        const uint8_t h,
        const uint8_t sep_lines
    ) const;

    std::unordered_map<uint8_t, uint8_t> get_num_items_on_level() const;
    std::pair<uint8_t, uint8_t> item_location(const Item*, const uint8_t items_on_level) const;
};

#endif
