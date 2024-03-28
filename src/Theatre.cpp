/*
 * Theatre.cpp
 *
 *  Created on: Mar 28, 2024
 *      Author: keith
 */

#include "Theatre.h"

Theatre::Theatre(int capacity):capacity(capacity),cur_numpeople(0) {}


bool Theatre::enter(int numbpeople){
	std::lock_guard<std::mutex> lck(m);
	if(cur_numpeople+numbpeople>capacity)
		return false;

	cur_numpeople+=numbpeople;
	return true;
}

