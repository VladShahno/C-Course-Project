#pragma once
#include<iostream>
#include<chrono>
using namespace std;

											/*Class CTimer to count the execution time of program code */

class CTimer
{
public:
											/* Constructor's */

	// Default constructor
	CTimer();

	// Destructor
	~CTimer();

private:
										/* Class members */

	std::chrono::time_point<std::chrono::steady_clock> m_start, m_end;

};