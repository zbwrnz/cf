#ifndef __INTERVAL_RESULT_HPP__
#define __INTERVAL_RESULT_HPP__

#include <vector>

// Forward declaration
template <class T> class IntervalTree; 

/** A container for results from searches for overlaps
 *
 * bool inbetween - TRUE if the query overlaps nothing
 */
template <class T>
class IntervalResult
{
public:
    std::vector<T*> iv;
    IntervalTree<T>* tree;
    bool inbetween;
    bool leftmost;
    bool rightmost;

    IntervalResult(){
        tree      = NULL;
        inbetween = false;
        leftmost  = false;
        rightmost = false;
    };

    void print()
    {
        printf("inbetween=%i leftmost=%i rightmost=%i\n", inbetween, leftmost, rightmost);
    }
};

#endif