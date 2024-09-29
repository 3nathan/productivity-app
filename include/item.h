#ifndef __ITEM__
#define __ITEM__

#include <string>
#include <vector>
#include <cstdint>

struct Item {
    std::string name;
    std::string desc;

    uint8_t duration;
    double set_time;
    double due_time;

    std::vector<Item*> children;
    std::vector<Item*> parents;

    uint8_t heirarchical_level;
};

#endif
