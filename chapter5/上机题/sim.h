#pragma once

enum EventType{arrival, departure};
//创建事件类
class Event
{
private:
	int time;
	EventType type;
	int customerID;
	int tellerID;
	int waittime;
	int servicetime;
public:
	Event(void);
	Event(int t, EventType et, int cn, int tn, int wt, int st);
	int GetTime(void) const;
	EventType GetEventType(void) const;
	int GetCustomerID(void) const;
	int GetTellerID(void) const;
	int GetWaitTime(void) const;
	int GetServiceTime(void) const;
};
Event::Event(void){}
Event::Event(int t, EventType et, int cn, int tn, int wt, int st):
	time(t),type(et),customerID(cn),tellerID(tn), waittime(wt),servicetime(st){}
int Event::GetTime(void) const
{
	return time;
}
EventType Event::GetEventType(void) const
{
	return type;
}
int Event::GetCustomerID(void) const
{
	return customerID;

}
int Event::GetTellerID(void) const
{
	return tellerID;
}
int Event::GetWaitTime(void) const
{
	return waittime;
}
int Event::GetServiceTime(void) const
{
	return servicetime;
}

int operator <(const Event&a, const Event&b)
{
	return a.GetTime() < b.GetTime();
}
typedef Event DataType;
#include "apqueue.h"
#include <iostream>
#include "chapter3/random.h"

//有关窗口信息的结构
struct TellerStats
{
	int finishService;
	int totalCustomerCount;
	int totalCustomerWait;
	int totalService;
};



class Simulation
{
private:
	int simulationLength;		//模拟的时长
	int numTellers;				//窗口数
	int nextCustomer;		
	int arrivalLow, arrivalHigh;//到达时间下限和上线
	int serviceLow, serviceHigh;//服务时间下限和上限
	TellerStats tstat[11];
	PQueue pq;
	RandomNumber rnd;
	int NextArrivalTime(void);
	int GetServiceTime(void);
	int NextAvalibleTeller(void);
public:
	Simulation(void);
	void RunSimulation(void);
	void PrintSimulationResults(void);
};

int Simulation::NextArrivalTime(void)
{
	return arrivalLow + rnd.Random(arrivalHigh - arrivalLow + 1);
}
int Simulation::GetServiceTime(void)
{
	return serviceLow + rnd.Random(serviceHigh - serviceLow + 1);
}
int Simulation::NextAvalibleTeller(void)
{
	int minfinish = simulationLength;
	int minfinishindex = rnd.Random(numTellers) + 1;
	for (int i = 1; i <= numTellers; i++)
	{
		if (tstat[i].finishService < minfinish)
		{
			minfinish = tstat[i].finishService;
			minfinishindex = i;
		}
		return minfinishindex;
	}
}
Simulation::Simulation(void)
{
	int i;
	Event firstevent;
	//初始化窗口信息参数
	for (i = 1; i <= 10; i++)
	{
		tstat[i].finishService = 0;
		tstat[i].totalCustomerCount = 0;
		tstat[i].totalCustomerWait = 0;
		tstat[i].totalService = 0;
	}
	nextCustomer = 1;
	//读入用户输入的模拟条件
	cout << "Enter the simulation time in minutes: ";
	cin >> simulationLength;
	cout << "Enter the time of bank tellers: ";
	cin >> numTellers;
	cout << "Enter the range of arrival times in minutes: ";
	cin >> arrivalLow >> arrivalHigh;
	cout << "Entet the range of service times in minutes: ";
	cin >> serviceLow >> serviceHigh;
	pq.PQInsert(Event(0, arrival, 1, 0, 0, 0));
}
void Simulation::RunSimulation(void)
{
	int nexttime, servicetime, tellerID, waittime;
	while (pq.PQEmpty())
	{
		Event e = pq.PQDelete();
		simulationLength = (e.GetTime() <= simulationLength) ? simulationLength : e.GetTime();

		nexttime = e.GetTime();
		if (nexttime > simulationLength)
			//可能的下一个顾客到达的时间迟于营业时间，处理已有事件，不添加新事件
			continue;
		else {
			nextCustomer++;
			Event newevent(nexttime, arrival, nextCustomer, 0, 0, 0);
			pq.PQInsert(newevent);
		}
		//顾客所需的服务时间
		servicetime = GetServiceTime();
		//提供此次服务的窗口
		tellerID = NextAvalibleTeller();

		if (tstat[tellerID].finishService == 0)
			tstat[tellerID].finishService = e.GetTime();
		waittime = tstat[tellerID].finishService - e.GetTime();

		tstat[tellerID].totalCustomerWait += waittime;
		tstat[tellerID].totalCustomerCount++;
		tstat[tellerID].totalService += servicetime;
		tstat[tellerID].finishService += servicetime;
		Event newevent(tstat[tellerID].finishService, departure, e.GetCustomerID(), tellerID, waittime, servicetime);
		pq.PQInsert(newevent);
	}
}
void Simulation::PrintSimulationResults(void)
{
	int cumCustomers = 0;
	int cumWait = 0;
	int tellerWork = 0;
	int tellerWorkPercent = 0;
	int i;
	for (i = 1; i < numTellers; i++)
	{
		cumCustomers += tstat[i].totalCustomerCount;
		cumWait += tstat[i].totalCustomerWait;
	}
	cout << endl;
	cout << "* * * * * * * * Simulation Summary * * * * * * * *" << endl;
	cout << "Simulation of " << simulationLength << " minutes" << endl;
	cout << "No. of Customers:  " << cumCustomers << endl;
	cout << "Average Customer Wait: ";
	//总的等待时间除以总服务的人数
	int avgCustWait = float(cumWait) / cumCustomers + 0.5;
	cout << avgCustWait << "minutes" << endl;
	for (i = 1; i <= numTellers; i++)
	{
		cout << "Teller #" << i << " % Working: ";
		//每个窗口工作时间除以总的上班时间，象征着工作效率
		tellerWork = float(tstat[i].totalService) / simulationLength;
		tellerWorkPercent = tellerWork * 100.0 + 0.5;
		cout << tellerWorkPercent << endl;
	}
}
