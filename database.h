#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <functional>
#include <algorithm>
#include <iterator>
#include "date.h"

using namespace std;

class Database
{
public:
	Database() {};
	void Add(const Date& date, const string& event);
	//pair<Date, string> Last(const Date& date) const;
	string Last(const Date& date) const;
	template <typename Func>
	int RemoveIf(Func _pred)
	{
		int cnt = 0;
		for (auto i = storage_sort.begin(); i != storage_sort.end();)
		{
			Date day = i->first;
			auto it_begin = stable_partition(indexes.at(i->first).begin(), indexes.at(i->first).end(), [i, _pred](const auto & s) {
				bool rez = _pred(i->first, *s);
				return !rez; 
				});
			cnt += indexes.at(i->first).end() - it_begin;
			for (auto it = it_begin; it != indexes.at(i->first).end(); it++)
			{
				i->second.erase(*it);
			}
			indexes.at(i->first).erase(it_begin, indexes.at(i->first).end());
			if (i->second.empty())
			{
				indexes.erase(i->first);
				i = storage_sort.erase(i);
			}
			else {
				i++;
			}
		}
		return cnt;
	}
	template <typename Func>
	vector<string> FindIf(Func _pred) const
	{
		vector<string> rez;
		for (const auto& it : storage_sort)
		{
			Date day = it.first;
			auto it_find = find_if(it.second.begin(), it.second.end(), [day, _pred](const string & str) {return _pred(day, str); });//TODO возможно тут переделать надо
			for (const auto& it_ev : it.second)
			{
				if (_pred(it.first, it_ev))
				{
					stringstream str;
					str << it.first << " " << it_ev;
					rez.push_back(str.str());
				}
			}
		}
		return rez;
	}
	void Print(ostream& out) const;


private:
	map<Date, set<string>> storage_sort;
	map<Date, deque<set<string>::const_iterator>> indexes;
};

ostream& operator<<(ostream& out, const pair<Date, string>& p);

