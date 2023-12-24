#include <iostream>
#include <string>
#include <unordered_map>
 
bool Ransom(std::string ransomLetter, std::string paper){ 
	std::unordered_map<char, int> LCP;

	for(char letter : paper) { 
	LCP[letter]++; 
	} 

	for(char letter : ransomLetter) {

		auto Pi = LCP.find(letter);

		if(Pi != LCP.end() && Pi->second > 0) {
		Pi->second--;
		} else {
		return false;
		}
	}
	return true;
}

int main() {
	std::cout << std::boolalpha; // Для вывода булевых значений как true/false а не 1/0
   
	std::string ransomLetter;
	std::string paper;
	
	std::cin >> ransomLetter >> paper;
    
	std::cout << "\n" << Ransom(ransomLetter, paper) << std::endl;
    
    return 0;
}
