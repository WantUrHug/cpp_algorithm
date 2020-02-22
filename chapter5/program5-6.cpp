#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "job.h"

typedef JobRequest DataType;
#include "apqueue.h"

int main(void)
{
	PQueue jobPool;
	ifstream fin;

	//用来记录花费在不同类型员工上的服务计时
	int jobServiceUse[3] = { 0, 0, 0 };

	JobRequest PR;
	char ch;

	fin.open("job.dat", ios::in);
	if (!fin) {
		cerr << "Cannot open file 'job.dat'" << endl;
		//exit(1);
		return 2;
	}
	while (fin >> ch)
	{
		//cout << ch << endl;
		switch(ch)
		{
		case 'M':PR.staffPerson = Manager; break;
		case 'S':PR.staffPerson = Supervisor; break;
		case 'W':PR.staffPerson = Worker; break;
		default:break;
		}
		fin >> PR.jobid;
		fin >> PR.jobTime;
		jobPool.PQInsert(PR);
	}
	cout << "Category   Job ID   Job Time" << endl;
	while (!jobPool.PQEmpty())
	{
		PR = jobPool.PQDelete();
		PrintJobInfo(PR);
		jobServiceUse[int(PR.staffPerson)] += PR.jobTime;
	}
	PrintJobSummary(jobServiceUse);
	system("pause");
}