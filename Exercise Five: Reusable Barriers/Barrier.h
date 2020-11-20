/* Barrier.h --- Barrier.h
 * 
 * Filename: Barrier.h
 * Description: 
 * Author: Joseph
 * Maintainer: 
 * Created: Tue Jan  8 12:12:03 2019 (+0000)
 * Version: 
 * Package-Requires: ()
 * Last-Updated: Tue Jan  8 12:15:54 2019 (+0000)
 *           By: Joseph
 *     Update #: 2
 * URL: 
 * Doc URL: 
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change Log:
 * 
 * 
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Code: */
#pragma once
class Barrier
{
  int numThreads;

public:
  /*! \fn Barrier 
    \brief Constructor of the barrier. This is used to set the mutex and two turnstiles
  */
  Barrier(int numThreads);
  /*! \fn ~Barrier
    \brief Destructor used to delete the semaphores pointed to by three created pointers.
  */
  virtual ~Barrier();
  /*! \fn wait
    \brief Usage of the reusable barrier
  */
  void wait();

  /*! \fn phaseOne
    \brief First phase of the barrier. This is used when waiting for all the threads to arrive.
  */
  void phaseOne();
  /*! \fn phaseTwo
    \brief Second phase of the reusable barrier. This is waiting for the threads to finish executing. 
  */
  void phaseTwo();
};

/* Barrier.h ends here */
