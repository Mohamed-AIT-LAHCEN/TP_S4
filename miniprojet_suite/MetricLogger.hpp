#include <iostream>
#include <string>

template <typename T>
class MetricLogger {
public:
    void logToStream(const T& obj, std::ostream& stream, const std::string& label) {
        stream << "=== Metrics for " << label << " ===" << std::endl;
        stream << obj.getMetrics() << std::endl;
    }
};