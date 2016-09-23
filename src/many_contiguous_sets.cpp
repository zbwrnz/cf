#include "many_contiguous_sets.h"

void ManyContiguousSets::link_contiguous_blocks(
    Block* b,
    long k,
    size_t& setid
)
{
    auto iter = inv.rbegin();
    for (; b != nullptr; b = b->next()) {
        for (iter = inv.rbegin(); ; iter++) {
            if (iter == inv.rend()) {
                // if block fits in no set, create a new one
                inv.push_back(new ContiguousSet(b));
                break;
            }
            // if block successfully joins a set
            else if ((*iter)->add_block(b, k)) {
                break;
            }
            // if set terminates
            else if (ContiguousSet::strictly_forbidden((*iter)->ends[1], b, k)) {
                inv.push_back(new ContiguousSet(b));
                break;
            }
        }
    }

    for(auto c : inv){
        setid++;
        c->id = setid;
        c->over->id = setid;
    }
}
