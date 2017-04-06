#include "abstractDatabase.hpp"
#include <assert.h>
#include "iostream"

class MockDatabase : public AbstractDatabase
{
    public:
        MockDatabase() : data(0) {};
        virtual void getData()
        {
            ++data;
            std::cout << data << "\n";
        };
        virtual int assertIfGetDataCalled()
        {
            return data!=0;
        };
    private:
        int data;
};