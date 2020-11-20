/*! \class Barrier
 *  \brief An implementation of a reusable barrier using semaphores
 *  \author Liliana O'Sullivan
 *  \author Joseph Kehoe
 *  \date 17nd November 2020
 *  \copyright MIT License
*/
#include "Semaphore.h"
#include "Barrier.h"
#include <iostream>

int count = 0;
int nThreads;
Semaphore *mutex;
Semaphore *turnStile1;
Semaphore *turnStile2;

/*! \fn Barrier 
	\brief Constructor of the barrier. This is used to set the mutex and two turnstiles
*/
Barrier::Barrier(int numThreads)
{
    nThreads = numThreads;

    mutex = new Semaphore(1);
    turnStile1 = new Semaphore(0);
    turnStile2 = new Semaphore(1);
}

/*! \fn ~Barrier
	\brief Destructor used to delete the semaphores pointed to by three created pointers.
*/
Barrier::~Barrier()
{
    delete mutex;
    delete turnStile1;
    delete turnStile2;
}

/*! \fn phaseOne
	\brief First phase of the barrier. This is used when waiting for all the threads to arrive.
*/
void Barrier::phaseOne()
{
    mutex->Wait();
    ++count;
    if (count == nThreads)
    {
        turnStile2->Wait();
        turnStile1->Signal();
    }
    mutex->Signal();

    turnStile1->Wait();
    turnStile1->Signal();
}

/*! \fn phaseTwo
	\brief Second phase of the reusable barrier. This is waiting for the threads to finish executing. 
*/
void Barrier::phaseTwo()
{
    mutex->Wait();
    --count;
    if (count == 0)
    {
        turnStile1->Wait();
        turnStile2->Signal();
    }
    mutex->Signal();

    turnStile2->Wait();
    turnStile2->Signal();
}
/*! \fn wait
	\brief Usage of the reusable barrier
*/
void Barrier::wait()
{
    phaseOne();
    phaseTwo();
}
