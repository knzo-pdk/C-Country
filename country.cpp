#include <string>
#include <iostream>
#include "Country.h"
#include <cstring>
using namespace std;
Country::Country(const char* country, const char* capital, long pop)
{
     name_ = new char(strlen(country) + 1);
     capital_ = new char(strlen(capital) + 1);
     strncpy(name_, country, strlen(country) + 1);
     strncpy(capital_, capital, strlen(capital) + 1);
     surfaceArea_ = pop;
}
Country::~Country() { 
     delete[] name_;     //delete the allocated memory
     delete[] capital_;   //delete the allocated memory
}
char* Country::GetCountryName() { return (name_); }
char* Country::GetCapital() { return(capital_); }
long Country::GetSurfaceArea() { return(surfaceArea_); }
