#pragma once
#include <iostream>
using namespace std;

enum Staff {Manager, Supervisor, Worker};
struct JobRequest
{
	Staff staffPerson;
	int jobid;
	int jobTime;
};

int operator < (const JobRequest& a, const JobRequest& b)
{
	return a.staffPerson < b.staffPerson;
}

void PrintJobInfo(JobRequest PR)
{
	switch (PR.staffPerson)
	{
	case Manager:cout << "Manager   "; break;
	case Supervisor:cout << "Supervisor   "; break;
	case Worker:cout << "Worker   "; break;
	}
	cout << PR.jobid << "   " << PR.jobTime << endl;
}

#include <iomanip>
void PrintJobSummary(int jobServiceUse[])
{
	cout << "\nTotal Support Usage \n";
	cout << "  Manager    " << setw(3) << jobServiceUse[0] << endl;
	cout << "  Supervisor    " << setw(3) << jobServiceUse[1] << endl;
	cout << "  Worker    " << setw(3) << jobServiceUse[2] << endl;
}