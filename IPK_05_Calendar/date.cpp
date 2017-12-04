/*
 * Date.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: nuar
 */

#include "date.h"

Date::Date():aDay(0),aMonth(0),aYear(0){}

Date::Date(int year,int month, int day):aDay(day),aMonth(month),aYear(year){
if(!this->valid()){
	std::cout<<"Not a valid date"<<std::endl;
}
}

Date::~Date() {}

std::vector<std::pair<int,int>> Date::library()const{
	std::vector<std::pair<int,int>> dayMonth;
	dayMonth.push_back(std::make_pair(31,1));
	dayMonth.push_back(std::make_pair(28,2));
	dayMonth.push_back(std::make_pair(31,3));
	dayMonth.push_back(std::make_pair(30,4));
	dayMonth.push_back(std::make_pair(31,5));
	dayMonth.push_back(std::make_pair(30,6));
	dayMonth.push_back(std::make_pair(31,7));
	dayMonth.push_back(std::make_pair(31,8));
	dayMonth.push_back(std::make_pair(30,9));
	dayMonth.push_back(std::make_pair(31,10));
	dayMonth.push_back(std::make_pair(30,11));
	dayMonth.push_back(std::make_pair(31,12));
	return dayMonth;
}

bool Date::isLeapYear(int year) const{
	bool is_leap_year=0;
	if(year%4==0) 	is_leap_year=1;
	if(year%100==0)	is_leap_year=0;
	if(year%400==0)	is_leap_year=1;
	return is_leap_year;
}

bool Date::valid() const{
	bool valid=0;
	if(this->aMonth>0 && this->aMonth<=12){
		if(this->aDay<=31&& this->aDay>=0){
			if(this->aDay<=28){
				valid=1;
			}
			if(this->aDay==29){
				if(this->aMonth==2 && this->isLeapYear(this->aYear)==1){
					valid=1;
				}
				if(this->aMonth!=2){
					valid=1;
				}

			}
			if(this->aDay==30){
				if(this->aMonth!=2) valid=1;
			}
			if(this->aDay==31){
				if(	this->aMonth==1 || this->aMonth==3 || this->aMonth==5  ||
					this->aMonth==7 || this->aMonth==8 || this->aMonth==10 || this->aMonth==12){
					valid=1;
				}
			}
		}
	}
	return valid;
}

void Date::addDays(int days){
	std::vector<std::pair<int,int>> dayMonth=library();
	//First determining how many days of the year have passed
	int dayOfYear=0;
	for(int i=0;i<this->aMonth-1;i++){
		if(isLeapYear(this->aYear) && i==1){
			dayOfYear++;
		}
		dayOfYear+=dayMonth[i].first;
	}
	//Determining  where new date is supposed to be relating to the current status
	dayOfYear+=days+this->aDay;

	//determining year, where the new data should be implemented
	while(dayOfYear>=366){
		if(isLeapYear(this->aYear)){
			dayMonth[1].first=29;
			if(dayOfYear==366){
				this->aMonth=12;
				this->aDay=31;
			}
			else{
				this->aYear++;
				dayOfYear-=366;
			}
		}
		else{
			dayMonth[1].first=28;
			this->aYear++;
			dayOfYear-=365;
		}
		if(isLeapYear(this->aYear)){
			dayMonth[1].first=29;;
		}
		else{
			dayMonth[1].first=28;
		}
	}
	//Now determining (by iteration) where new data is by subtracting number compared to the library
	for(int i=0;i<12;i++){
		if(dayOfYear<=dayMonth[i].first){
			this->aMonth=dayMonth[i].second;
			this->aDay=dayOfYear;
			break;
		}
		else{
			dayOfYear-=dayMonth[i].first;
		}
	}
}

void Date::addMonths(int months){
	std::vector<std::pair<int,int>> dayMonth=library();
	//Det year of new date
	div_t divresult= div(months,12);
	this->aYear+=divresult.quot;

	//Det month of new Date
	for(int i=0;i<months;i++){
		if(this->aMonth==12)this->aYear++;
		this->aMonth=(this->aMonth+1)%12;
	}
	//Det wether day exists in Date, otherwise correcting to lower number
	if(this->aDay>dayMonth[this->aMonth-1].first){
		if(isLeapYear(this->aYear) && this->aMonth==2){
			this->aDay=29;
		}
		else{
			this->aDay=dayMonth[this->aMonth-1].first;
		}
	}
}

void Date::addYears(int years){
	std::vector<std::pair<int,int>> dayMonth=library();
	//adding years
	for(int i=0;i<years;i++){
		this->aYear++;
	}
	//det wether day exists in month, /w correction
	if(this->aDay>dayMonth[this->aMonth-1].first){
		if(isLeapYear(this->aYear) && this->aMonth==2){
			this->aDay=29;
		}
		else{
			this->aDay=dayMonth[this->aMonth-1].first;
		}
	}
}

int Date::daysAfter(const Date& other)const{
	std::vector<std::pair<int,int>> dayMonth=library();

	//total days in this year calc
	int dayOfYear=0;
	for(int i=0;i<this->aMonth-1;i++){
		if(isLeapYear(this->aYear)&& i==1){
			dayOfYear++;
		}
		dayOfYear+=dayMonth[i].first;
	}
	dayOfYear+=this->aDay;


	//adding year difference
	int diff=0;
	int yearDif=abs(this->year()-other.year());
	for(int i=0;i<yearDif;i++){
		//intial check wether leap year needs to be considered in the root year
		if(i==0	&&	isLeapYear(this->aYear)	&&	this->aMonth<3) diff+=366;
		if(i==0 &&	isLeapYear(this->aYear)	&&	this->aMonth>=3) diff+=365;
		//all in  between years
		if(i!=0 && isLeapYear(this->aYear+i)){
			diff+=366;
		}
		if(i!=0 && !isLeapYear(this->aYear+i)){
			diff+=365;
		}
	}
	//adding difference of target year months
	for(int i=0;i<other.month()-1;i++){
		//check for leap day
		if(isLeapYear(other.year()) && i==1){
			diff++;
		}
		//otherwise simply add days of the month
		diff+=dayMonth[i].first;
	}
	//finally adding the days of target date and subtracting target year total
	diff+=other.days();
	diff-=dayOfYear;
	return abs(diff);


	//end of total days calc
}

int Date::days()const{
	return this->aDay;
}

int Date::month()const{
	return this->aMonth;
}

int Date::year()const{
	return this->aYear;
}

std::ostream& operator<<(std::ostream& stream,const Date& date){
	stream	<<std::setfill('0')<<std::setw(2)<<date.days()<<"."
			<<date.month()<<"."<<std::setw(4)<<date.year();
	return stream;
}
