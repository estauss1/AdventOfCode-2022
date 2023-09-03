#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <variant>

using std::cout; using std::endl;
using std::ifstream; using std::getline;
using std::string;

int roundScore(char opponent, char player);

int main(){
  ifstream rpsInput("input");
  if(!rpsInput.is_open()){
    cout << "failed to open rps input file.\n";
    return 1;
  }

  string line;
  getline(rpsInput, line);
  char opponent = '\0', player = '\0';
  int totalScore = 0, numOfRounds = 0;
  while(!rpsInput.eof()){
    opponent = line[0];
    player = line[2];
    totalScore += roundScore(opponent, player);
    ++numOfRounds;
    getline(rpsInput, line);
  }
  
  cout << "using the elf's method, you scored " << totalScore << " points after "
       << numOfRounds << " rounds of rock paper scissors." << endl;
  
  rpsInput.close();
  if(rpsInput.is_open()){
    cout << "failed to close rpsinput file." << endl;
    return 2;
  }
  
  return 0;
}

int roundScore(char opponent, char player){
  
  int score = 0;
  if(player == 'X'){
    score += 1;
    //determine outcome of round 
    switch(opponent){
      case 'A':
        score += 3;
        break;
      case 'B':
        //doesnt gain points from loss
        break;
      case 'C':
        score += 6;
        break;
      default:
        cout << "opponent choice not a valid choice.\n";
        exit(EXIT_FAILURE); 
    }
  }
  else if(player == 'Y'){
    score += 2;
    switch(opponent){
      case 'A':
        score += 6;
        break;
      case 'B':
        score += 3; 
        break;
      case 'C':
        //loss 
        break;
      default:
        cout << "opponent choice not a valid choice.\n";
        exit(EXIT_FAILURE); 
    }
  }
  else if(player == 'Z'){
    score += 3;
    switch(opponent){
      case 'A':
        //loss 
        break;
      case 'B':
        score += 6; 
        break;
      case 'C':
        score += 3; 
        break;
      default:
        cout << "opponent choice not a valid choice.\n";
        exit(EXIT_FAILURE); 
    }
  }
  else{
    cout << "Player choice was not a valid choice.\n";
    exit(EXIT_FAILURE);
  }

  return score;
}
