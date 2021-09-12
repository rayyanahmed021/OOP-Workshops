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
#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

extern unsigned int g_sysClock;
#define MAX_DESC 127


namespace sdds
{
	class Event
	{
		char m_description[MAX_DESC + 1];
		unsigned int m_time; //seconds
	public:
		Event();
		void display();
		void set(char* event = nullptr);
		Event& operator = (const Event* eve);
	};
}
#endif // !SDDS_EVENT_H