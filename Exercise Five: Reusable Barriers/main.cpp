#include "Barrier.h"
#include <iostream>
#include <thread>
#include <vector>

static const int num_threads = 100;
int sharedVariable = 0;

/*! \class main
 *  \brief An implementation and usage of a reusable barrier using semaphores
 *  \author Liliana O'Sullivan
 *  \author Joseph Kehoe
 *  \date 17nd November 2020
 *  \copyright MIT License
*/

/*! \fn barrierTask
	\brief An example of using a reusable barrier. Displays a message that is split in to 2 sections to show how a rendezvous and work
*/
void barrierTask(std::shared_ptr<Barrier> theBarrier, int numLoops)
{
	for (int i = 0; i < numLoops; ++i)
	{
		//Do first bit of task
		std::cout << "A" << i;
		//Barrier
		theBarrier->phaseOne();
		//Do second half of task
		std::cout << "B" << i;
		theBarrier->phaseTwo();
	}
}

int main(void)
{
	std::vector<std::thread> vt(num_threads);
	std::shared_ptr<Barrier> aBarrier(new Barrier(num_threads));
	/**< Launch the threads  */
	int i = 0;
	for (std::thread &t : vt)
	{
		t = std::thread(barrierTask, aBarrier, 10);
	}
	/**< Join the threads with the main thread */
	for (auto &v : vt)
	{
		v.join();
	}
	std::cout << sharedVariable << std::endl;
	return 0;
}
