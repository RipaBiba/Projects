/***** Group 24 *****/

/***** Group Members:
    01.Name: Sharmin Islam
       ID: 2018-3-60-078
    02.Name: Tanjina Akter Ripa
       ID: 2018-3-60-024
*****/

#include<bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> vec;
int target, size, temp;

bool isMultHelper(vector<int>& vec, vector<int>& DP, int currentValue, int target)
 {
   if(currentValue == target) return true;
   else if(currentValue > target) return false;

   if(DP.at(currentValue)) return false;
   DP.at(currentValue) = 1;

   bool possible = false;
   for(int i = 0; i < vec.size(); i++) {
      if(isMultHelper(vec, DP, currentValue * vec.at(i), target)) {
         possible = true;
      }
   }

   return possible;
}

bool isMultPossible(vector<int>& vec, int target)
{
   vector<int> DP(target + 1, 0);
   return isMultHelper(vec, DP, 1, target);
}

bool isSumHelper(vector<int>& vec, vector<int>& DP, int currentValue, int target)
{

   if(currentValue == target) return true;
   else if(currentValue > target) return false;

   if(DP.at(currentValue)) return false;
   DP.at(currentValue) = 1;

   bool possible = false;
   for(int i = 0; i < vec.size(); i++) {
      if(isSumHelper(vec, DP, currentValue + vec.at(i), target)) {
         possible = true;
      }
   }

   return possible;
}

bool isSumPossible(vector<int>& vec, int target)
{
    vector<int> DP(target + 1, 0);
    return isSumHelper(vec, DP, 0, target);
}

int MENU()
{
    int n;
    cout << "\n~~**SUB__SET**~~\n" << endl;
    cout << "_____MENU_____" << endl;
    cout << "\n1. Check Sum.\n2. Check Multiplication.\n3. Check Sum & Multiplication.\n4. Exit.\n" << endl;
    cout << "Enter your Choice: ";
    cin >> n;
    return n;
}

void Sum()
{
    cout << "\nPlease give the size of the number set: " << endl;
    cin >> size;

    cout << "\nPlease give unique numbers for the number set: " << endl;
    for(int i = 0; i < size; ++i)
    {
        cin >> temp;
        vec.push_back(temp);
    }

    cout << "\nPlease give the target number: " << endl;
    cin >> target;

    if(isSumPossible(vec,target))
    {
        cout << "\nSum Possible!\n" << endl;
    }
    else
    {
        cout << "\nSum not Possible!\n" << endl;
    }
}

void Multi()
{
    cout << "\nPlease give the size of the number set: " << endl;
    cin >> size;

    cout << "\nPlease give unique numbers for the number set: "<< endl;
    for(int i = 0; i < size; ++i)
    {
        cin >> temp;
        vec.push_back(temp);
    }

    cout << "\nPlease give the target number: " << endl;
    cin >> target;

    if(isMultPossible(vec, target))
    {
        cout << "\nMultiplication Possible!\n" << endl;
    }
    else
    {
        cout << "\nMultiplication not Possible!\n" << endl;
    }
}

void Sum_Multi()
{
    cout << "\nPlease give the size of the number set: " << endl;
    cin >> size;

    cout << "\nPlease give unique numbers for the number set: " << endl;
    for(int i = 0; i < size; ++i) {
        cin >> temp;
        vec.push_back(temp);
    }

    cout << "\nPlease give the target number: " << endl;
    cin >> target;

    if(isSumPossible(vec,target))
    {
        cout << "\nSum Possible!\n" << endl;
    }
    else
    {
        cout << "\nSum not Possible!\n" << endl;
    }

    if(isMultPossible(vec, target))
    {
        cout << "\nMultiplication Possible!\n" << endl;
    }
    else
    {
        cout << "\nMultiplication not Possible!\n" << endl;
    }
}

int main() {
    cout << "\t~~~WELCOME~~~" << endl;
    int choice;
    while (true)
    {
        choice = MENU();
        if (choice == 1)
        {
            Sum();
        }
        else if (choice == 2)
        {
            Multi();
        }
        else if (choice == 3)
        {
            Sum_Multi();
        }
        else if (choice == 4)
        {
            cout << "\nCome Again......\nThank You!\n" << endl;
            break;
        }
    }

   return 0;
}

