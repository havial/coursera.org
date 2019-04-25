#pragma once

#include "date.h"
#include <memory>

using namespace std;

enum Comparison{
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

enum LogicalOperation{
	And,
	Or
};



class Node{
public:
	virtual bool Evaluate(const Date &date,const std::string &event)=0;
};

class EmptyNode: public Node{
public:
	bool Evaluate(const Date &date,const std::string &event) override;
};

class DateComparisonNode : public Node{
public:
	DateComparisonNode(Comparison cmp, Date dt) :Comp(cmp), data(dt) {};
	bool Evaluate(const Date &date,const std::string &event) override;
	Comparison Comp;
	Date data;

};

class EventComparisonNode : public Node{
public:
	EventComparisonNode(Comparison cmp, std::string str) : Comp(cmp), Event(str) {};
	bool Evaluate(const Date &date,const std::string &event) override;
	std::string Event;
	Comparison Comp;
};

class LogicalOperationNode: public Node{
public:
	LogicalOperationNode(LogicalOperation lo,shared_ptr<Node> nd1,shared_ptr<Node> nd2):operation(lo),left(nd1),right(nd2){}
	bool Evaluate(const Date &date,const std::string &event) override;
private:
	LogicalOperation operation;
	std::shared_ptr<Node> left;
	std::shared_ptr<Node>  right;
};
