#include "functions.h"


string to_upper(string str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
	}
	return str;
}