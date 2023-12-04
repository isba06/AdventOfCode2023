#include <iostream>
#include <string>
#include <fstream>
#include <vector>

const static std::vector<std::string> word_digits =  {"", "one", "two", "three",
                                                  "four", "five", "six",
                                                  "seven", "eight", "nine"};
                                                  
int first_last_evaluate(std::pair<int, int> first, std::pair<int, int> last,
                        int first_positions[], int last_positions[]) {

  for(int i = 1; i < 10; ++i) {
      if(first_positions[i] != -1 && first_positions[i] < first.first){
        first.first = first_positions[i];
        first.second = i;
      }
      if(last_positions[i] != -1 && last_positions[i] > last.first){
        last.first = last_positions[i];
        last.second = i;
      }
  }
  
  return first.second * 10 + last.second;
}

int first_last_number(const std::string & str){
  std::pair<int, int> first{-1, 0}, last{-1, 0}; //pos, value
  int pos = 0;
  bool isFirst = true;
  
  for(auto && ch : str) {
    if(std::isdigit(ch)){
      if(isFirst) {
        first.first = pos;
        first.second = ch - '0';
        isFirst = false;
      }
      last.first = pos;
      last.second = ch - '0';
    }
    ++pos;
  }
  int first_positions[10];
  for(int i = 1; i < word_digits.size(); ++i) {
    first_positions[i] = static_cast<int>(str.find(word_digits[i]));
  }
  
  int last_positions[10];
  for(int i = 1; i < word_digits.size(); ++i) {
    last_positions[i] = static_cast<int>(str.rfind(word_digits[i]));
  }
  return first_last_evaluate(first, last, first_positions, last_positions);
}

int main() {
  std::ifstream input("../inputs/input.txt");
  if(!input.is_open()){
    return 1;
  }
  int sum = 0;
  std::string str;
  int index = 1;
  while(!input.eof()){
    input >> str;
    int val = first_last_number(str);
    sum += val;
  }
  std::cout << sum << '\n';
  return 0;

}


