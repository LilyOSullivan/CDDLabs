#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>
/*! \class Signal
 *  \brief An Implementation of Threads Using Semaphores
 *  \details Uses C++11 features such as mutex and condition variables to implement Semaphores in thread functions
 *  \author Joseph Kehoe
 *  \author Liliana O'Sullivan
 *  \date 27th October 2020
 *  \copyright MIT License.
*/

/*! displays a message first*/
void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay){ //Delay is no longer being used
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  theSemaphore->Signal();
}
/*! displays a message second*/
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}
/* <-- A ! should be here after the star.
* \brief          Main Function.
* \note           Where the program starts
* \details        I wrote this as
*                 a test for myself
*                 to test
*                 doxygnen
*                 comments.
* \param[in]      var1            Description of variable one, if I had any (Input)
* \param[in]      var2            Description of variable two, if I had any
* \param[out]     var3            Description of variable three, an output (Eg: via a pointer
*                                 to a variable)

* \return         This function will always return 0 unless of a unsuccessful execution
                  Possible Values:
                  - 0
                  - 1
*/
int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  int taskOneDelay=5;
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem,taskOneDelay);
  std::cout << "Launched from the main\n";
   /**< Wait for the threads to finish */
  threadOne.join();
  threadTwo.join();
  return 0;
}
