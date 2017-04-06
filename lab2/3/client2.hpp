#include "abstractDatabase.hpp"

class Client2 
{
    AbstractDatabase* myDatabase;
    public:
        Client2(AbstractDatabase* db):myDatabase(db){};
    public:
        void transaction () 
        {
            myDatabase->getData();
        };
};