//g++64 -g -o phraseCount -std=c++17 -Wall phraseCount.cpp easyregex.cpp -lmingw32
//phraseCount 2 5 < in.txt > out.txt
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include "easyregex.hpp"

int main(int argc,char** args){
	using namespace std;
	//Take the wordLimit argument.
	unsigned short wordLimit = atoi(args[2]);
	//Read the entire input file into a string.
	istreambuf_iterator<char> begin(cin), end;
	string file(begin, end);
	//Put all of the words in order of appearance in a vector.
	vector<string> words;
	for(deque<string> m : findAll(file,regex("[A-Za-z0-9_'-]+"))){
		//Make sure every word is lower case.
		std::transform(m[0].begin(), m[0].end(), m[0].begin(), ::tolower);
		words.emplace_back(m[0]);
	}
	//Don't call .size() more than once.
	size_t numberOfWords = words.size() - 1;
	//For every number of words that can be in a phrase as selected by the user,
	for(unsigned short i = stoi(args[1]); i <= wordLimit; i++){
		map<string,unsigned short> phrases;
		size_t numberOfPhrases = 0;
		//Go through each word in the file.
		for(unsigned short j = 0; j < numberOfWords - i; j++){
			//Make a phrase.
			string phrase;
			for(unsigned short k = 0; k < i; k++) phrase += words[j+k]+" ";
			phrases.emplace(phrase,1);
			//If the phrase was not already in there,
			if(numberOfPhrases != phrases.size()){
				numberOfPhrases++;
			}else{
				phrases[phrase]++;
			}
		}
		typedef pair<string,unsigned short> phrase;
		//We have to switch from a deque to a vector because you can only sort with a random access iterator.
		vector<phrase> phraseVector;
		for(phrase p : phrases) phraseVector.push_back(p);
		//Sort the phrases by how many times they appear.
		sort(phraseVector.begin(),phraseVector.end(),[=](phrase& a,phrase& b)->bool{
			return a.second > b.second;
		});
		for(phrase p : phraseVector){
			p.first.pop_back();
			cout << p.first << "," << p.second << endl;
		}
		cout << endl;
	}
}