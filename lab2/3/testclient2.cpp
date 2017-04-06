#include "client2.hpp"
#include "mockDatabase.hpp"
#include "abstractDatabase.hpp"

#include "iostream"
#include <assert.h>
#include "cstdlib"

void assertGetDataWasCalled(AbstractDatabase* pdb)
{
    assert(pdb->assertIfGetDataCalled());
};

int main()
{
    //construct database
    MockDatabase* pdb = new MockDatabase();

    //construct test object
    //(dependency injection)
    Client2 client(pdb);
    
    //test behaviour # 1
    client.transaction();
    assertGetDataWasCalled(pdb);
    //test behaviour # 2
};