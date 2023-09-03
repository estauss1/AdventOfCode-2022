#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace::std;

int main(){
  
  ifstream elfInventory("input");
  if(!elfInventory.is_open()){
    cout << "Error opening elf inventory file\n";
    return 1;
  }

  string caloriesStr;
  int invenTotal = 0;
  vector<int> vecTotals;
  while(!elfInventory.eof()){

    getline(elfInventory, caloriesStr);
    while( (caloriesStr != "" ) && !elfInventory.eof() ){
      invenTotal = invenTotal + stoi(caloriesStr);
      getline(elfInventory, caloriesStr);
    }
    vecTotals.push_back(invenTotal);
    invenTotal = 0; //reset for next elf inventory
  }
  
  make_heap(vecTotals.begin(), vecTotals.end());
  // part 1 answer
  cout << "The largest amount of calories held by an elf was: " << vecTotals.front() << " calories."
       << endl;

  //part 2: find total of top 3 elves with most calories
  int topThreeTotal = 0;
  for(int i = 0; i < 3; ++i){
    topThreeTotal = topThreeTotal + vecTotals.front();
    pop_heap(vecTotals.begin(), vecTotals.end());
    vecTotals.pop_back();
  }

  cout << "Total of top three elves with highest calorie inventories is: " << topThreeTotal
       << " calories." << endl;

  elfInventory.close();
  return 0;
}
