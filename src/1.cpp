#include <iostream>
#include <string>
#include <fstream>

int first_last_number(const std::string & str){
	int first = 0;
	int last = 0;
    bool isFirst = true;
	for(auto && ch : str){
		if(std::isdigit(ch)){
			if(isFirst) 
                first = ch - '0';
            isFirst = false;
            last = ch - '0';
		}
	}
	return first*10 + last;
}

int main() {
    std::ifstream input("input.txt");
    if(!input.is_open()){
        return 1;
    }
    int sum = 0;
    std::string str;
    while(!input.eof()){
        input >> str;
        sum += first_last_number(str);
    }
    std::cout << sum << '\n';
	return 0;
	
}