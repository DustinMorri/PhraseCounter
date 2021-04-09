#include "easyregex.hpp"
std::string fileToString(std::string file){
	//Filename must include full path.
	//std::string exePath = args[0];
	//std::string currentDirectory = exePath.substr(0, exePath.rfind("programName"));
	std::ifstream in (file, std::ios::in);
	//If the file does not exist, throw error.
	if(in.fail()){
		throw "File does not exist.";
		return "";
	}
	//Otherwise, use the values found in the settings file.
	else{
		//Seek to the end of the file.
		in.seekg(0, std::ios::end);
		//Create a new std::string object the size of the file.
		std::string text;
		text.resize(in.tellg());
		//Go back to the beginning of the file.
		in.seekg(0, std::ios::beg);
		//Read in all the bytes to the std::string.
		in.read(&text[0], text.size());
		//Close the file.
		in.close();
		//Return the string.
		return text;
	}
}
std::deque<std::deque<std::string>> findAll(std::string s,std::regex e){
	std::sregex_iterator rit (s.begin(),s.end(),e);
	std::sregex_iterator rend;
	std::deque<std::deque<std::string>> matches;
	while (rit!=rend) {
		std::deque<std::string> subMatches;
		std::smatch sm = *rit;
		for(size_t i=0;i<sm.size();i++){
			subMatches.push_back(sm[i]);
		}
		matches.push_back(subMatches);
		++rit;
	}
	return matches;
}