#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>
#include <algorithm>



void solve(int pin, int userGuess){
  int y = 10;
  int w;
  vector<int>master;
  int correct_place = 0;
  int correct_digit = 0;
  int incorrect_digit = 0;
  int usersGuess[4];
  while (y != 0){
   for (int j = 0; j < 4; j++){
      w = pin%10;
      usersGuess[j] = userGuess%10;
      master.push_back(w);
      userGuess = userGuess/10;
      pin = pin/10;
  }
   for (int i = 0; i < 4; i++){
      int x = usersGuess[i];
    if (x == master[i]){
        correct_place += 1;
    }else if(find(master.begin(), master.end(), x) != master.end()){
       correct_digit += 1;}
    else{
         incorrect_digit += 1;}
  }
    if (correct_place == 4){
        cout<< "Number of digits in correct place: " << correct_place << endl;
        cout<< "Congratulations!!"<<endl;
        break;
   }else{
      cout<< "Number of digits in correct place: " << correct_place << endl;
      cout<< "Number of digits correct but not incorrect place: " << correct_digit << endl;
      cout<< "Number of digits not correct: " << incorrect_digit << endl;
      y--;
      correct_digit = 0;
      correct_place = 0;
      incorrect_digit = 0;
      cout<< "Chances left: "<<y<<endl;
      cout << "please enter a pin : ";
      cin >>userGuess;
     }
     if (y == 0){
        cout<< "you lose"<<endl;
     }
  }
}


int main(){
    srand(time(0));
    int x;
    x = 1000 + (rand() % 1001);
    cout<<x<<endl;
    int userGuess;
    cout << "please enter a pin : ";
    cin >>userGuess;
    solve(x, userGuess);
return 0;
}
