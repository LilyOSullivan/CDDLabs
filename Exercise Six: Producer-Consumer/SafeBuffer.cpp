#include "SafeBuffer.h"

/*! \fn put
	\brief Adds data to the buffer
*/
void SafeBuffer::put(int c)
{
    m.Wait();
    array[head] = c;
    ++head;
    m.Signal();
}

/*! \fn popStart
	\brief Removes a value from the buffer and returns it
*/
int SafeBuffer::popStart()
{
    m.Wait();
    int c = array[tail];
    ++tail;
    m.Signal();
    return c;
}
