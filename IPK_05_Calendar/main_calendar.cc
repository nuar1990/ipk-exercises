/*
 * main_calendar.cc
 *
 *  Created on: Dec 4, 2017
 *      Author: nuar
 */
#include "date.h"

int main(){
	std::cout<<"Welcome to the rudimentary interface for some linear calendar functions: "<<std::endl;
	std::cout<<"Starting Date:";
	Date test=Date(2000,2,29);
	std::cout<<test<<std::endl;
	std::cout<<"Adding (1)365;(2)366;(3)30 days: "<<std::endl;
	test.addDays(365);
	std::cout<<"(1) "<<test<<std::endl;
	test.addDays(366);
	std::cout<<"(2) "<<test<<std::endl;
	test.addDays(30);
	std::cout<<"(3) "<<test<<std::endl;
	std::cout<<"Adding (1)2; (2)1; (3)32 Months: "<<std::endl;
	test.addMonths(2);
	std::cout<<"(1) "<<test<<std::endl;
	test.addMonths(1);
	std::cout<<"(2) "<<test<<std::endl;
	test.addMonths(32);
	std::cout<<"(3) "<<test<<std::endl;
	std::cout<<"Adding (1)1; (2)2; (3)1 Year: "<<std::endl;
	test.addYears(1);
	std::cout<<"(1) "<<test<<std::endl;
	test.addYears(2);
	std::cout<<"(2) "<<test<<std::endl;
	test.addYears(1);
	std::cout<<"(3) "<<test<<std::endl;


	std::cout<<"Compare Date: ";
	Date test2=Date(1904,2,29);
	std::cout<<test2<<std::endl;
	int difference=test.daysAfter(test2);
	std::cout<<"There are "<<difference<<" days between "<<test<<" and "<<test2<<std::endl;
	std::cout<<"check result under:"<<std::endl;
	std::cout<<"https://www.timeanddate.com/date/durationresult.html?d1=29&m1=2&y1=1904&d2=28&m2=2&y2=2008&ti=on"<<std::endl;
	return 0;
}


