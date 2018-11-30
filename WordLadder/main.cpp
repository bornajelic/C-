#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <set>
#include <iterator>
#include <stack>
#include <queue>


bool neighbour(std::string& wordFromStack, std::string& wordFromDictionary);
std:: string &stringTransformation(std::string& str);
void wordLadder(std::string& first, std::string& second, std::set<std::string>&dictionary);


int main() {

    std::cout << "Welcome to Word Ladder\n" <<
    "Please provide full name of a file, including extention\n\n";
    //dictionary.txt

    std:: string fileName;
    std:: string firstWord;
    std:: string secondWord;


    //Set insertion
    std::set<std::string> dictionary;
    std::string word;
    std::ifstream input;


    while(true) {

        std::getline(std::cin, fileName);
        input.open(fileName);
        if(input.good()) {
            break;
        }else {
            std::cout << "wrong file,please try again\n";
        }
    }
    copy(std::istream_iterator<std::string>(input),std::istream_iterator<std::string>(), std::inserter(dictionary,dictionary.end()));



    //provjeriti jeli rijec postoji u dictionary-u
    while(true) {

    std::cout<<"Enter first word or press ENTER to exit!\n";
    std::getline(std::cin,firstWord);
    if(firstWord.empty()) {
       exit(1);
    }
    std::cout<<"Enter second word or press ENTER to exit!\n";
    std::getline(std::cin,secondWord);
    if(secondWord.empty()) {
       exit(1);
    }

    firstWord = stringTransformation(firstWord);
    secondWord = stringTransformation(secondWord);

    if(dictionary.find(firstWord)!= dictionary.end() && dictionary.find(secondWord) != dictionary.end()) {
        if(firstWord.length() == secondWord.length()){
            break;
        }
       std:: cout << "\n Word are not of equal lenght\n";
    } else {
        std:: cout << "\nWords are not in dictionary\n";
    }

    }
    std::cout << "final words : \n";
    std::cout << "Words : " << firstWord <<" "<<secondWord << "\n";

    wordLadder(firstWord,secondWord,dictionary);
}


std:: string &stringTransformation(std::string& str) {

    std::transform(str.begin(),str.end(),str.begin(),::tolower);
        return str;
}

void wordLadder(std::string& first, std::string& second, std::set<std::string>&dictionary) {


    std::queue< std::stack <std::string> > theQueue;
    std::stack< std::string > theStack;
    std::set < std::string> processedWords;
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    theStack.push(first);
    processedWords.insert(first);
    theQueue.push(theStack);


    while(!theQueue.empty()) {
        std::stack<std::string> tmpStack = theQueue.front();
        theQueue.pop();
        std::string wordFromStack = tmpStack.top(); //testiramo ovu rijec

        for(unsigned int i = 0; i < wordFromStack.length(); i++) {
            std::string tmpString = wordFromStack;
                for(char c : alphabet) {
                    tmpString[i] = c;
                    std::cout << tmpString << "\n";

                        //if tmpStr exist in file and if it is a "neighbour" word
                        if(dictionary.find(tmpString) != dictionary.end() && neighbour(wordFromStack,tmpString)) {
                           //if tmpString wasnt in ladder
                            if(!(processedWords.find(tmpString) != processedWords.end())) {
                                processedWords.insert(tmpString); //add it into ladder
                                if(tmpString == second) {

                                    std::cout << second << " " ;
                                    while(!tmpStack.empty()) {
                                        std:: cout <<tmpStack.top() << " ";
                                        tmpStack.pop();
                                    }
                                    return;
                                } else {
                                    std::stack<std::string> copyStack = tmpStack;
                                    copyStack.push(tmpString);
                                    theQueue.push(copyStack);


                                }
                            }
                        }



                }
        }

    }


}

bool neighbour(std::string& wordFromStack, std::string& wordFromDictionary) {

    if(wordFromDictionary.length() != wordFromStack.length()) {
        return false;
    }

    int counter = 0;
    for(unsigned int i = 0; i < wordFromDictionary.length(); i++) {
        if(wordFromStack[i] != wordFromDictionary[i]) {
            counter++;
        }
    }
    return counter == 1 ? true : false;
}


