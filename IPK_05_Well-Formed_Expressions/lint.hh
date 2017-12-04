/*
 * lint.hh
 *
 *  Created on: Dec 4, 2017
 *      Author: nuar
 */

#ifndef LINT_HH_
#define LINT_HH_

#include <iostream>
#include <stack>

class lint {
public:
	lint();
	bool check_parentheses(std::string symbols);
	virtual ~lint();
};

#endif /* LINT_HH_ */
