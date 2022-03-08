class Country
{
private:
 char* name_;
 char* capital_;
 long surfaceArea_;
public:
 Country(const char* country, const char* capital, long pop);
 ~Country();
 char* GetCountryName();
 char* GetCapital();
 long GetSurfaceArea();
 //tName(string str) { name_ = str; return; };
};