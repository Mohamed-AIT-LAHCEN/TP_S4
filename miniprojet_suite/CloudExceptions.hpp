#include <iostream>
using namespace std;

// CloudException inherits from std::runtime_error
class CloudException : public runtime_error {
public:
    CloudException(const string& message)
        : runtime_error("Exception Capturée : " + message) {}
};

// AllocationException inherits from CloudException
class AllocationException : public CloudException {
public:
    AllocationException(const string& message)
        : CloudException(message) {}
};

class FileException : public CloudException {
    public:
    FileException(const string& message)
        : CloudException(message) {}
};