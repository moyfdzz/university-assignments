#include <iostream>
using namespace std;

int main()
{
  int number;
  
  cin >> number;
  
  for (int i = 0; i <= number; i++){
       
        for (int r = 1; r <= number-i; r++)
        {
            cout << " ";
        }
        
    for (int j = 1; j <= 2*i-1; j++){
      cout << "*";
    }
    cout << endl;
  }
  
  for (int i = number - 1; i != 0; i--)
  {
        for (int r = 1; r <= number-i; r++)
        {
            cout << " ";
        }
        
        for (int j = 1; j <= 2*i-1; j++){
            cout << "*";
        }
        cout << endl;
  }
    cout<<endl;
    return 0;
}