/*
 * Theatre.h
 *
 *  Created on: Mar 28, 2024
 *      Author: keith
 */
#include <mutex>
#ifndef THEATRE_H_
#define THEATRE_H_

class Theatre {
public:
	Theatre(int capacity);

	bool enter(int numbpeople=1);
	int howmany(){return cur_numpeople;}
private:
	//total people that it can handle
	int capacity;

	//how many are in it now
	int cur_numpeople;
	std::mutex m;
};

#endif /* THEATRE_H_ */
