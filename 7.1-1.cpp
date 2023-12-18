// 7.1-1.cpp

#include <iostream>
#include<thread>
#include<chrono>

using namespace std::chrono_literals;

int count_clients = 0;

void Clients()
{
	while (count_clients < 10) {

		++count_clients;
		std::cout << "Client " << count_clients << " came" << std::endl;
		std::this_thread::sleep_for(1000ms);
	}

}

void Operator()
{
	while (count_clients > 0) {
		std::this_thread::sleep_for(2000ms);

		std::cout << "Client " << count_clients << " is completed" << std::endl;
		--count_clients;
	}
}

int main()
{
	std::thread t1(Clients);
	std::thread t2(Operator);
	t1.join();
	t2.join();
	return 0;
}
