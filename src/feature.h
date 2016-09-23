#ifndef __FEATURE_H__
#define __FEATURE_H__

#include "interval.hpp"
#include "global.h"

#include <string>
#include <iostream>
#include <climits>


class Feature : public Interval<Feature>
{
public:

    std::string parent_name = ".";
    std::string name        = ".";
    long parent_length      = LONG_MAX;
    char strand             = '.';

    Feature()
    {
#ifdef DEBUG
cerr << "+Feature()\n";
#endif
    }

    Feature(
        const char* t_parent_name,
        long        t_start,
        long        t_stop,
        const char* t_name,
        long        t_parent_length,
        char        t_strand='+'
    )
        :
        Interval(t_start, t_stop),
        parent_name(t_parent_name),
        name(t_name),
        parent_length(t_parent_length),
        strand(t_strand)
    {
#ifdef DEBUG
fprintf(stderr, "+Feature(const char*, long, long, const char*, long, char)\n");
#endif 
    }

    ~Feature() {
#ifdef DEBUG
fprintf(stderr, "-Feature\n");
#endif 
    };
};

#endif
