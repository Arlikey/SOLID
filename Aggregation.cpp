#include <iostream>
using namespace std;

struct IWorker {
	virtual void DoWork() = 0;
};

class Worker : public IWorker {
public:
	void DoWork() override { cout << "Worker : DoWork\n"; };
};

class SeasonedWorker : public IWorker {
public:
	void DoWork() override { cout << "SeasonedWorker : DoWork\n"; };
};

class Manager {
private:
	IWorker* worker;
public:
	Manager(IWorker* inj_worker) : worker(inj_worker) {};
	~Manager() { delete worker; };
	void DoSomething() { worker->DoWork(); };
};

int main() {

	Manager manager1(new Worker());
	manager1.DoSomething();

	Manager manager2(new SeasonedWorker());
	manager2.DoSomething();

	return 0;
}