#include"CTimer.h"

										/*Class CTimer to calculate the execution time of program code */

						/* Constructor's */

// Default constructor
CTimer::CTimer()
{
	m_start = chrono::high_resolution_clock::now(); // time value of m_start at the beginning of code execution 
}

// Destructor
CTimer::~CTimer()
{
	m_end = std::chrono::high_resolution_clock::now(); // time value of m_end at the end of code execution
	std::chrono::duration<float> duration = m_end - m_start; // the difference between the beginning  of the code execution and the end 
	cout << " Duration = " << duration.count() << " s " << endl; // time of object destruction = time execution of code 
}