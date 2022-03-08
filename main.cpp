#include<iostream>
#include<cstring>
#include<fstream>
#include<cmath>
#include<string>
#include "Country.h"
using namespace std;
int counter, numLines = 0;
long popul;
string filepath, name, cap;
char letter;
ifstream nationFile;
char c_name[255], c_cap[255], c_u[255];
string *str1, *str2;
const int FILE_PATH_SZ = 512;
Country ** g_countryArray;
int i = 0, g_arrSz;
void FreeArray() {
 int i;
 for (i = 0; i < numLines; i++)
 {
  delete g_countryArray[i];
  g_countryArray[i] = NULL;
 }
 delete[] g_countryArray;
 g_countryArray = NULL;
}

int main() {
 char letter;
 string str;
 int count = 0, pop;
// enum choice { a, b, c, d };
 do {
  string gogo;
  ifstream yoFile;
  cout << "Please make a selection: " << endl;
  cout << "a) Read a text file" << endl;
  cout << "b) Remove countries starting with letter " << endl;
  cout << "c) Print all data to console " << endl;
  cout << "d) Quit " << endl;
  cin >> letter;
  switch (letter) {
  case 'a': {
//   cout << "a) Read a text file" << endl;
   cout << "Please enter a file path for an input text file: ";
   cin >> filepath;
   
   nationFile.open(filepath);
   if (nationFile.is_open())
   {
    if (g_countryArray != NULL)  // delete the allocated pointers
    {
     FreeArray();
     numLines = 0;   //reset the counter
    }
    
    char str[255];
    while (nationFile.peek() != EOF) {
     nationFile.getline(str, 255);
//     cout << numLines << " " << str << endl;
     ++numLines;
    }
    g_countryArray = new Country*[numLines];
    nationFile.close();
    nationFile.clear(std::ios_base::goodbit);
   }
   else
   {
    cerr << "Error opening file" << endl;
    exit(1);
   }
   nationFile.open(filepath);
   i = 0;
   for (i = 0; i < numLines; i++) {
    nationFile.get(c_name, 225, ',');
//    cout << "name is: " << c_name ;
    nationFile.ignore();
    nationFile.get(c_cap, 225, ',');
//    cout << "cap is: " << c_cap ;
    nationFile.ignore();
    nationFile.get(c_u, 225);
//    cout << "population is: " << c_u << endl;
    nationFile.ignore();
    popul = stol(c_u); //convert string -> long
    g_countryArray[i] = new Country(c_name, c_cap, popul);
   }
   cout << "Loaded file and read " << numLines << " countries." << endl << endl;
   nationFile.close();
   nationFile.clear(std::ios_base::goodbit);
   break;
  }
  case 'b': {
   char initial;
   string x;
   int j = 0; // variable to count the deletion ...
   cout << "Remove countries starting with letter: ";
   cin >> initial;
   for (i = 0; i < numLines; i++)
   {
    // cout << endl << i << " lloking " << endl;
    if (g_countryArray[i] != NULL) // new added
    {
     // cout << i << " != NULL" << endl;
     x = g_countryArray[i]->GetCountryName();
     // cout << i << " " << x << " " << toupper(initial) << " AND " << toupper(x.at(0)) << endl;
     if (toupper(initial) == toupper(x.at(0)))   // the matched country
     {
     // cout << "FOUND " << i << " " << x << " " <<  toupper(initial) << " AND " << toupper(x.at(0)) << endl;
     // cout <<  "Delete Country [" << i << "]" << g_countryArray[i]->GetCountryName() << endl;
     delete g_countryArray[i]; // deletion the value which pointed by this element
      g_countryArray[i] = NULL; // set this pointer to NULL(nowhere) as marked of deleted.
      j++;
     }
    }
   }
   cout << "Removed ";
   cout << j << " countr" << (j < 2 ? "y" : "ies") << endl << endl ;
   break;
  }
  case 'c': {
//   cout << "c) Print all data to console " << endl;
   int i, j;
   cout << endl;
   for (i = 0, j = 0; i < numLines; i++)
   {
    if (g_countryArray[i] != NULL)
    {
     j++;
     cout << " " << g_countryArray[i] ->GetCountryName();
     cout << " " << g_countryArray[i]->GetCapital();
     cout << " " << g_countryArray[i] ->GetSurfaceArea();
     cout << endl;
    }
   }
   cout << "\nListed ";
   cout << j << " countr" << (j < 2 ? "y" : "ies") << endl << endl;
   break;
  }
  case 'd': {
   cout << "d) Quit " << endl;
   break;
  }
  }
 } while (letter != 'd');
 FreeArray();
 return 0;
}
