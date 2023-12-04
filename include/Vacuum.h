#ifndef VACUUM_H
#define VACUUM_H

class Vacuum{
    private:
        bool binIsFull;

    public:
        Vacuum();
        //This will return bool
        void getBinIsFull();
        void setBinIsFull();
};

#endif