/*
 * SchedulerSTRR.cpp
 *
 *  Created on: 9/27/2020
 *      Author: Jared Koenig
 */


#include "../includes/scheduler_RR.h"

bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p) {
	if((p.required_cpu_time - p.remaining_cpu_time) % time_slice == 0)
	{
		return true;
	}
	else if ( p.remaining_cpu_time <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//RR - preemptive - no sorting of ready_q needed.
void Scheduler_RR::sort() {
}
