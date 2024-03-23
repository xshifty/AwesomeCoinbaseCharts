#include "Bucket.h"

namespace AwesomeCoinbaseCharts::Data {
    BucketCollection::BucketCollection() = default;

    BucketCollection* BucketCollection::fromJson(const char *json) {
        return new BucketCollection();
    }
}
