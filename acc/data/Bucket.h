#pragma once

#include <iostream>

namespace AwesomeCoinbaseCharts::Data {
    typedef struct Bucket {
        unsigned long int dateInSeconds;
        double dayMinPrice;
        double dayMaxPrice;
        double openingPrice;
        double closingPrice;
    } *BucketPtr;

    class BucketCollection {

    public:
        BucketCollection();
        static BucketCollection* fromJson(const char* json);
    };
}
