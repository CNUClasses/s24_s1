
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include "Theatre.h"
using namespace std;

int numtickets=500000;
Theatre th1(numtickets/2);
Theatre th2(numtickets/2);
mutex m;
mutex m_cout;

void print(string s){
	lock_guard<mutex> lck(m_cout);
	cout<<s<<endl;
}

void agent(int id){
	//i sell tickets

	int j=0;
	print("Agent "+to_string(id)+" starting, numtickets="+to_string(numtickets));

	while(true){
		{
			lock_guard<mutex> lck(m);
			if(numtickets==0)
				break;
			numtickets--;
		}

		//sold a ticket enter the theatre
		if(!th1.enter(1))
			th2.enter(1);

		//simulating a time consuming operation
//		this_thread::sleep_for(chrono::milliseconds(1));

		j++;
		print("Agent "+to_string(id)+" sold one, numtickets="+to_string(numtickets));
	}
	print("Agent "+to_string(id)+" leaving, sold "+to_string(j)+" tickets");
}

int main() {
	thread t1(agent,1);
	thread t2(agent,2);
	thread t3(agent,3);
	thread t4(agent,4);
	{
		lock_guard<mutex> lck(m);
		print("We are multithreaded! (an example of braying about the inconsequential), numbtickets="+to_string(numtickets));
	}
	t4.join();
	t3.join();
	t1.join();
	t2.join();
	cout<<"All done, numbtickets="<<numtickets<<endl;
	cout<<"numb people in theatre 1="<<th1.howmany()<<endl;
	cout<<"numb people in theatre 2="<<th2.howmany()<<endl;

	return 0;
}
