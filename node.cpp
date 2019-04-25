#include "node.h"

bool EmptyNode::Evaluate(const Date &date,const std::string &event){
	return true;
}

bool DateComparisonNode::Evaluate(const Date &date,const std::string &event){
	switch(Comp){
	case Comparison::Equal:
		return data == date;
	case Comparison::Greater:
		return date > data;
	case Comparison::GreaterOrEqual:
		//return date >= data;
		return (date > data || date == data);
	case Comparison::Less:
		return date < data;
	case Comparison::LessOrEqual:
		//return date <= data;
		return (date < data || date == data);
	case Comparison::NotEqual:
		return date != data;
	}
	return false;
}

bool EventComparisonNode::Evaluate(const Date &date,const std::string &event){
	switch(Comp){
		case Comparison::Equal:
			return event == Event;
		case Comparison::Greater:
			return event > Event;
		case Comparison::GreaterOrEqual:
			//return event >= Event;
			return (event > Event || event == Event);
		case Comparison::Less:
			return event < Event;
		case Comparison::LessOrEqual:
			//return event <= Event;
			return (event < Event || event == Event);
		case Comparison::NotEqual:
			return event != Event;
		}
		return false;
}

bool LogicalOperationNode::Evaluate(const Date &date,const std::string &event){
	return operation == LogicalOperation::And ? left->Evaluate(date,event) && right->Evaluate(date,event):
								left->Evaluate(date,event) || right->Evaluate(date,event);
}
