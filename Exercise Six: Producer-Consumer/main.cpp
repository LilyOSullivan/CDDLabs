#include <iostream>
#include <thread>
#include <vector>
#include "SafeBuffer.h"

static const int num_threads = 100;
unsigned int x = 0;

/*! \class main
 *  \brief An implementation the producer consumer problem
 *  \author Liliana O'Sullivan
 *  \author Joseph Kehoe
 *  \date 18th December 2020
 *  \copyright MIT License
*/

/*! \fn producer
	\brief A function to produce numbers and place them into the buffer
*/
void producer(std::shared_ptr<SafeBuffer> theBuffer,
              std::shared_ptr<Semaphore> m,
              std::shared_ptr<Semaphore> signalling)
{
    m->Wait();
    ++x;
    theBuffer->put(x);
    signalling->Signal();
    m->Signal();
}

/*! \fn consumer
	\brief A function that consumed the numbers created by the producer
*/
void consumer(std::shared_ptr<SafeBuffer> theBuffer,
              std::shared_ptr<Semaphore> m,
              std::shared_ptr<Semaphore> signalling)
{
    signalling->Wait();
    m->Wait();
    std::cout << theBuffer->popStart() << std::endl;
    m->Signal();
    signalling->Signal();
}

int main(void)
{
    std::vector<std::thread> vP(num_threads);
    std::vector<std::thread> vC(num_threads);
    std::shared_ptr<SafeBuffer> aBuffer(new SafeBuffer);
    std::shared_ptr<Semaphore> m(new Semaphore(1));
    std::shared_ptr<Semaphore> signalling(new Semaphore(0));

    for (std::thread &t : vP)
    {
        t = std::thread(producer, aBuffer, m, signalling);
    }
    for (std::thread &t : vC)
    {
        t = std::thread(consumer, aBuffer, m, signalling);
    }
    for (auto &v : vP)
    {
        v.join();
    }
    for (auto &v : vC)
    {
        v.join();
    }
}
