#include "date.h"


Date ParseDate(istream& is)
{
	string date;
	is >> date;
	istringstream date_stream(date);
	bool ok = true;

	int year;
	ok = ok && (date_stream >> year);
	ok = ok && (date_stream.peek() == '-');
	date_stream.ignore(1);

	int month;
	ok = ok && (date_stream >> month);
	ok = ok && (date_stream.peek() == '-');
	date_stream.ignore(1);

	int day;
	ok = ok && (date_stream >> day);
	ok = ok && date_stream.eof();

	if (!ok) {
		throw logic_error("Wrong date format: " + date);
	}
	return Date(year, month, day);
}
