// Date 10/4/17
/* This program takes the input of a user that is less than 80 characters and removes all spaces and
   punctuation and reverses the order of the letters. If the order of the letters are the same forward
   as they were backward then its a palindrome! If not, its not a palindrome.

   ***Example of a palindrome --racecar--***

*/


#include <iostream>
#include <cstring>

using namespace std;

int main () {

  // array that holds input of user
  char userInput[80];
  cin.get(userInput, 80);
  cin.get();

  char copyArray[80];

  // take only alphanumeric characters from the input and put them into new array
  int insert = 0;
  for (int i = 0; i < strlen(userInput); i++) {
    if (!isspace(userInput[i]) && !ispunct(userInput[i])) {
      copyArray[insert] = userInput[i];
      insert++;
    }
  }
  // add null character at end of new array
  copyArray[insert] = '\0';

  // match case for all characters
  for (int i = 0; i < strlen(userInput); i++) {
    copyArray[i] = tolower(copyArray[i]);
  }
  
  cout << copyArray << endl;

  // array that will hold reverse order of copyArray
  char reverseArray[80];
  strcpy(reverseArray, copyArray);

  // add all elements of copyArray in reverse in reverseArray
  int count = 0;
  for (int j = strlen(copyArray) - 1; j > -1; j--) {
       reverseArray[count] = copyArray[j];
       count++;
  }

  cout << reverseArray << endl;

  // compare to see if the input is a palindrome or not
  if(strcmp(reverseArray, copyArray) == 0) {
    cout << "Palindrome!" << endl;
  } else {
    cout << "Not a palindrome." << endl;
  }
  
}
