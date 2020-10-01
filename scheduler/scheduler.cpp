/* scheduler.cpp
 *
 *  Created on: 9/27/2020
 *      Author: Jared Koenig
 */

#include "../includes/scheduler.h"
#include "../includes/dispatcher.h"

//add a process, either a new one or one that
//had been running on the CPU and has been preempted
void Scheduler::add(PCB p) {
	ready_q->push(p);
}

//get next process
PCB Scheduler::getNext() {
	if (!isEmpty()) {
		PCB front = ready_q->front();
		ready_q->pop();
		return front;
	}
	else{
		return PCB();
	}
}
//returns true if there are no  jobs in the readyQ
//false otherwise
bool Scheduler::isEmpty() {
	return ready_q->empty();
}

//if process has completed (used all its remaining_cpu_time) or
//if we are using a preemptive scheduling algorithm and the
//timeslice is over then its time to switch processes
//returns:
//true - switch processes
//false - do not switch
bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {
	if (p.remaining_cpu_time <= 0)
	{
		return true;
	}
	else if (preemptive == true &&(tick_count - p.start_time)> time_slice)
	{
		return true;
	}
	else
	{
		return false;
	}
}
