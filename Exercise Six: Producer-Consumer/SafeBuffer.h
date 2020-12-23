#include "Semaphore.h"

/*! \class SafeBuffer
 *  \brief An implementation of thread-safe buffer
 *  \author Liliana O'Sullivan
 *  \author Joseph Kehoe
 *  \date 18th December 2020
 *  \copyright MIT License
 */

class SafeBuffer
{
private:
    int array[100];
    int head;
    int tail;
    Semaphore m;

public:
    SafeBuffer() : head(0), tail(0), m(1){};

    void put(int i);
    int popStart();
};

/* SafeBuffer.h ends here */
