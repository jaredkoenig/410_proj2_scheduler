/* scheduler_SRTF.cpp
 *
 *  Created on: 9/27/2020
 *      Author: Jared Koenig
 */

#include "../includes/scheduler_SRTF.h"

#include <algorithm>
//override base class behaviour if necessary, otherwise call it
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	sort();
	if (p.remaining_cpu_time <= 0 ||
			(!Scheduler::ready_q->empty() &&
			  Scheduler::ready_q->front().remaining_cpu_time < p.remaining_cpu_time))
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool sort_c_time(const PCB &valA, const PCB &valB) {
	return valA.remaining_cpu_time > valB.remaining_cpu_time;
}
//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort() {
	std::vector<PCB> vec;
	while (!ready_q->empty()) {
			vec.push_back(ready_q->front());
			ready_q->pop();
	}
	std::sort(vec.begin(),vec.end(), sort_c_time);
	while(!vec.empty()){
		ready_q->push(vec.back());
		vec.pop_back();
	}
}
