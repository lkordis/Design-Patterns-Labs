#ifndef ABSTRACT_CLASS
    #define ABSTRACT_CLASS

    class AbstractDatabase 
    {
        public:
            virtual void getData() = 0;
            virtual int assertIfGetDataCalled() = 0;
    };

#endif