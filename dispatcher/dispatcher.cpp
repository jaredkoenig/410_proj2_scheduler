/* Dispatcher.cpp
 *
 *  Created on: 9/27/2020
 *  Author: Jared Koenig
 */

#include "../includes/dispatcher.h"
#include "../includes/PCB.h"

/*
 * checks CPU for any processes and returns it
 * if there are no processes on the CPU then this
 * returns an uninitialized PCB.
 */
PCB Dispatcher::get_from_CPU() {
	if (isValidJobOnCPU()) {
		Dispatcher::is_valid_job_on_cpu = false;
		return Dispatcher::cpu->get_process_off_core();
	}
	return PCB();
}

//place the current process on the CPU for execution
void Dispatcher::put_on_CPU(PCB &process) {
	if (!isValidJobOnCPU()) {
		is_valid_job_on_cpu = true;
		cpu->put_process_on_core(process);
	}
}
//is CPU idle or working
bool Dispatcher::isValidJobOnCPU() {
	return Dispatcher::is_valid_job_on_cpu;
}
