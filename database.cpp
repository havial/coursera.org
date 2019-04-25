#include "database.h"




void Database::Add(const Date& date, const string& event)
{
	if (event.empty()) return;
	auto it = storage_sort[date].insert(event);
	if (it.second) indexes[date].push_back(it.first);
}

//pair<Date, string> Database::Last(const Date& date) const
//{
//	if (storage_nosort.empty())throw invalid_argument("");
//	else
//	{
//		auto it_rez = storage_nosort.upper_bound(date);
//		if (it_rez != storage_nosort.begin())
//		{
//			it_rez--;
//			if (!it_rez->second.empty())
//			{
//				string rez = *index.at(it_rez->first).back();
//				return  make_pair(it_rez->first, rez);
//			}
//		}
//	}
//	throw invalid_argument("");
//}

string Database::Last(const Date& date) const
{
	string rez;
	if (storage_sort.empty())throw invalid_argument("");
	else
	{
		auto it_rez = storage_sort.upper_bound(date);
		auto it_rez1 = storage_sort.lower_bound(date);
		if (it_rez1 != it_rez)
		{
			stringstream str;
			str << it_rez1->first << " " << *indexes.at(it_rez1->first).back();
			return str.str();
		}
		if (it_rez1 != storage_sort.begin())
		{
			it_rez1--;
			if (!it_rez1->second.empty())
			{
				stringstream str;
				str << it_rez1->first << " " << *indexes.at(it_rez1->first).back();
				return  str.str();
			}
		}
	}
	throw invalid_argument("");
}

void Database::Print(ostream& out) const
{
	for (auto& event : storage_sort)
	{
		for (auto s : indexes.at(event.first))
		{
			out << event.first << " " << (*s) << endl;
		}
	}

}

ostream& operator<<(ostream& out, const pair<Date, string>& p)
{
	out << p.first << " " << p.second;
	return out;
}
