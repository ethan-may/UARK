#ifndef TIMER_H
#define TIMER_H

//-----------------------------------------------------------
//  Author:  Ethan May
//-----------------------------------------------------------
#include <sys/time.h>
#include <ctime>
#include <cmath>
#include <iostream>
using namespace std;

class Timer
{
public:
   // Methods
   Timer();
   void start_timer();
   void end_timer();
   float elapsed_cpu();
   float elapsed_time();

private:
   // Object Attributes
   bool start_flag; 
   bool end_flag; 
   clock_t start_clock;
   clock_t end_clock;
   timeval start_timeval;
   timeval end_timeval;
};

#endif