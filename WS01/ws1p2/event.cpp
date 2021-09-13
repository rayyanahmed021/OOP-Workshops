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
		m_description = nullptr;
		m_time = g_sysClock;
	}

	void Event::display()
	{
		static int counter = 1;
		int time = 0;

		std::cout << std::setw(2) << std::right << counter++ << ". ";
		if (m_description != nullptr)
		{
			std::cout << std::setw(2) << std::right << std::setfill('0') << m_time / 3600 << ":";
			time = m_time % 3600;
			std::cout << std::setw(2) << std::right << std::setfill('0') << int(time / 60) << ":";
			time %= 60;
			std::cout << std::setw(2) << std::right << std::setfill('0') << time << " => " << m_description << std::endl;
			std::cout.fill(' ');
		}
		else
		{
			std::cout << "| No Event |" << std::endl;
		}


	}

	void Event::set(char* eve)
	{
		if (eve && eve[0] != '\0')
		{
			delete[] m_description;
			m_description = new char[strlen(eve) + 1];
			strcpy(m_description, eve);
		}
		else
		{
			m_description = nullptr;
			m_time = g_sysClock;
		}
	}
	Event::~Event()
	{
		delete[] m_description;
		m_description = nullptr;
	}
}