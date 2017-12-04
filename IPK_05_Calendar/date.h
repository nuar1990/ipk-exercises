/*
 * Date.h
 *
 *  Created on: Dec 4, 2017
 *      Author: nuar
 */

#ifndef DATE_H_
#define DATE_H_
#include <vector>
#include <iostream>
#include <iomanip>

class Date {
private:
	int aDay,aMonth,aYear;
public:
	Date();
	Date(int year, int month, int day);
	std::vector<std::pair<int,int>> library()const;
	bool valid()const;
	bool isLeapYear(int year) const;
	void addDays(int days);
	void addMonths(int months);
	void addYears(int years);
	int days() const;
	int month() const;
	int year() const;
	int daysAfter(const Date& other) const;
	friend std::ostream& operator<<(std::ostream& stream,const Date& date);
	virtual ~Date();
};

#endif /* DATE_H_ */
