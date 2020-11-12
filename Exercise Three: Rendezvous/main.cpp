#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <chrono>

/*! \class Main
 *  \brief An Implementation of a Rendezvous using Semaphores
 *  \author Liliana O'Sullivan
 *  \author Joseph Kehoe
 *  \date 2nd November 2020
 *  \copyright MIT License
*/

/*! displays a message that is split in to 2 sections to show how a rendezvous works*/
void taskOne(std::shared_ptr<Semaphore> firstSem, std::shared_ptr<Semaphore> secondSem, int delay)
{
  std::this_thread::sleep_for(std::chrono::seconds(delay));
  std::cout << "Task One has arrived! " << std::endl;
  firstSem->Signal();
  secondSem->Wait();
  std::cout << "Task One has left!" << std::endl;
}
/*! displays a message that is split in to 2 sections to show how a rendezvous works*/
void taskTwo(std::shared_ptr<Semaphore> firstSem, std::shared_ptr<Semaphore> secondSem, int delay)
{
  std::this_thread::sleep_for(std::chrono::seconds(delay));
  std::cout << "Task Two has arrived " << std::endl;
  secondSem->Signal();
  firstSem->Wait();
  std::cout << "Task Two has left " << std::endl;
}

int main(void)
{
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem1(new Semaphore);
  std::shared_ptr<Semaphore> sem2(new Semaphore);
  int taskOneDelay = 5;
  int taskTwoDelay = 1;
  /**< Launch the threads  */
  threadOne = std::thread(taskTwo, sem1, sem2, taskTwoDelay);
  threadTwo = std::thread(taskOne, sem1, sem2, taskOneDelay);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
