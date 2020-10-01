/*
 *  Created on: 9/27/2020
 *  Author: Jared Koenig
 *
 */
#include "../includes/stats.h"
#include "../includes/constants.h"

/*
 * Initializes all of the values modeled after
 * the header files initialize that were provided.
 */
Stats::Stats(std::vector<PCB> &finished_vector) :
vec(&finished_vector),
av_wait_time(0),
av_turnaround_time(0),
av_response_time(0) {}


//Uses an advanced for loop (foreach loop) to go through vec, and then
//prints a single line for every process by processing in order:
//Required CPU time, arrived, started, and finally finished
//This will then print the given amount of lines correctly.
void Stats::showAllProcessInfo() {
	for (PCB p : *vec) {
		std::cout
				<< "Process " << std::to_string(p.process_number)
						<< " Required CPU time:"
						<< std::to_string(p.required_cpu_time) + " arrived:"
						<< std::to_string(p.arrival_time) + " started:"
						<< std::to_string(p.start_time) + " finished:"
						<< std::to_string(p.finish_time);
	}
}

/*
 * calculates the average response time by determining
 * how long the processor takes by taking the start time and
 * subtracting the arrival time, then averages the whole thing
 * by dividing the number of processes that occurred
 * This again uses an enhanced for loop.
 */
float Stats::get_av_response_time() {
	int totalTime = 0;
	int sze = vec->size();
	for (PCB p : *vec) {
		totalTime += p.start_time - p.arrival_time;
	}
	return (float)totalTime / sze;
}

/*
 * Does the same process as above but for turnaraound time
 * totals the turnaround time then divides by the amount
 * of processes to get the average.
 */
float Stats::get_av_turnaround_time() {
	int totalTime = 0;
	int s = vec->size();
	for (PCB p : *vec) {
		totalTime += p.finish_time - p.arrival_time;
	}
	return (float)totalTime / s;
}

/*
 * Does the same process as above but for wait time
 * totals the wait time then divides by the amount
 * of processes to get the average.
 */
float Stats::get_av_wait_time() {
	int totalTime = 0;
	int s = vec->size();
	for (PCB p : *vec) {
		totalTime += p.finish_time - p.arrival_time - p.required_cpu_time;
	}
	return (float)totalTime / s;
}

/*
 * This function stores the data here for outside access.
 */
void Stats::calcStats() {
	av_response_time = get_av_response_time();
	av_turnaround_time = get_av_turnaround_time();
	av_wait_time = get_av_wait_time();
}
