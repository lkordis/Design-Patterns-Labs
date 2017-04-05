#ifndef BASE_CLASS
    #define BASE_CLASS

    class Base
    {
    public:
        virtual ~Base(){ };
        virtual int solve() = 0;
    };

#endif