/*
====================================
Name: Rayyan Ahmed
Date: 11/09/2021
Email: rahmed102@myseneca.ca
Student ID: 140961202
=====================================
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "event.h"

unsigned int g_sysClock = 0;
namespace sdds
{

	Event::Event()
	{
		m_description[0] = '\0';
		m_time = g_sysClock;
	}

	void Event::display()
	{
		static int counter = 1;
		int time = 0;

		std::cout << std::setw(2) << std::right << counter++ << ". ";
		if (m_description[0] != '\0')
		{
			std::cout << std::setw(2) << std::right << std::setfill('0') << m_time / 3600 << ":";
			time = m_time % 3600;
			std::cout << std::setw(2) << std::right << std::setfill('0') << time / 60 << ":";
			time %= 60;
			std::cout << std::setw(2) << std::right << std::setfill('0') << time << " => " << m_description << std::endl;
			std::cout.fill(' ');
		}
		else
		{
			std::cout << "| No Event |" << std::endl;
		}


	}

	void Event::set(char* event)
	{
		if (event)
		{
			//this->set(event); //set event
			*this = new Event();
			strcpy(m_description, event);
		}
		else
		{
			m_description[0] = '\0';
			m_time = 0;
		}
	}

	Event& Event::operator=(const Event* eve)
	{
		if (this != eve)
		{
			strcpy(m_description, eve->m_description);
			m_time = eve->m_time;
		}
		return *this;
	}
}