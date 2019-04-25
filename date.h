#pragma once
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Date {
public:
	Date() : year(0), month(0), day(0) {};
	// конструктор выбрасывает исключение, если его аргументы некорректны
	Date(int new_year, int new_month, int new_day) {
		year = new_year;
		if (new_month > 12 || new_month < 1) {
			throw logic_error("Month value is invalid: " + to_string(new_month));
		}
		month = new_month;
		if (new_day > 31 || new_day < 1) {
			throw logic_error("Day value is invalid: " + to_string(new_day));
		}
		day = new_day;
	}
	int GetYear() const {
		return year;
	}
	int GetMonth() const {
		return month;
	}
	int GetDay() const {
		return day;
	}
	friend bool operator != (const Date& lhs,const Date& rhs) 
	{
		return vector<int>{ rhs.GetYear(), rhs.GetMonth(), rhs.GetDay() }!=
			vector<int>{ lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()};
	}
	friend bool operator < (const Date& lhs, const Date& rhs) 
	{
		return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
			vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
	}
	friend bool operator > (const Date& lhs, const Date& rhs) 
	{
		return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >
			vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
	}
	friend bool operator == (const Date& lhs, const Date& rhs) 
	{
		return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} ==
			vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
	}
	friend bool operator <= (const Date& lhs, const Date& rhs) 
	{
		vector<int> lhs_d{ lhs.GetYear(), lhs.GetMonth(), lhs.GetDay() };
		vector<int> rhs_d{ rhs.GetYear(), rhs.GetMonth(), rhs.GetDay() };
		/*return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <=
			vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};*/
		return (lhs_d < rhs_d || lhs_d == rhs_d);
	}
	friend bool operator >= (const Date& lhs, const Date& rhs) 
	{
		vector<int> lhs_d{ lhs.GetYear(), lhs.GetMonth(), lhs.GetDay() };
		vector<int> rhs_d{ rhs.GetYear(), rhs.GetMonth(), rhs.GetDay() };
		//return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >=
		//	vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
		return (lhs_d > rhs_d || lhs_d == rhs_d);
	}
	friend ostream& operator<<(ostream& stream, const Date& date)
	{
		stream << setw(4) << setfill('0') << date.GetYear() <<
			"-" << setw(2) << setfill('0') << date.GetMonth() <<
			"-" << setw(2) << setfill('0') << date.GetDay();
		return stream;
	}

private:
	int year;
	int month;
	int day;
};

Date ParseDate(istream& is);



