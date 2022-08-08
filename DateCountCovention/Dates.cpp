#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

typedef int Date;		//Assume YYYYMMDD format
enum Month {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
string MonthText[] { "January", "February", "March", "April", "May", "June", 
					"July", "August", "September", "October", "November", "December" };
enum DayOfWeek {SUN, MON, TUE, WED, THU, FRI, SAT};
int DaysOfMonth_Nonleap[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int DaysOfMonth_Leap[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string DayOfWeekText[]{ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

int main() {
	Date dt;
	int year, month, day;
	string dtText;
	string::const_iterator it;
	vector<int> holidays;

	// TODO: Accept a date in string format (YYYYMMDD), validate the entry is a valid date
	//        Vaid date is between 20000101 and 21001231 inclusive
	//        Allow re-entry if date is not valid (notice that a user could input a non-integer)
	bool not_valid_date = true;
	bool leap_year = false;

	while(not_valid_date)
	{
		//getline(cin, dtText);
		cin >> dtText;
	
		if(dtText.size() != 8)
			{continue;}

		it = dtText.begin();
		year = month = day = 0;

		if(*it != '2')
			{continue;}
		else
		{
			year = (static_cast<int>(*it)-48)*1000;
			++it;
		}
		
		if(*it != '1' && *it != '0')
			{continue;}
		else
		{
			year = year+(static_cast<int>(*it)-48)*100;
			++it;
		}
		
		if(*it < '0' || *it > '9')
			{continue;}
		else
		{
			year = year+(static_cast<int>(*it)-48)*10;
			++it;
		}

		if(*it < '0' || *it > '9')
			{continue;}
		else
		{
			year = year+(static_cast<int>(*it)-48);
		}
		
		if(year<2000 || year>2100)
			{continue;}
		else	
		{++it;}

		if(year%4 == 0)
		{
			if(year%100 == 0 && year%400 != 0)
				{leap_year = false;}
			else
				{leap_year = true;}
		}

		if(*it != '0' && *it != '1')
			{continue;}
		else
		{
			month = month+(static_cast<int>(*it)-48)*10;
			++it;
		}

		if(*it < '0' && *it > '9')
			{continue;}
		else
		{
			month = month+(static_cast<int>(*it)-48);
		}
		
		if(month<1 || month>12)
        {continue;}

        else
        {++it;}

		if(leap_year == true)
		{
			if(*it < '0' || *it > '3')
			{continue;}
			else
			{
				day = day+(static_cast<int>(*it)-48)*10;
				++it;
			}

			if(*it < '0' || *it > '9')
			{continue;}
			else
			{
				day = day+(static_cast<int>(*it)-48);
			}

			if ( day < 1 || day > DaysOfMonth_Leap[month-1] )
			{continue;}
			else
			{not_valid_date = false;}
		}
		
		else if(leap_year == false)
		{
			if(*it < '0' || *it > '3')
			{continue;}
			else
			{
				day = day+(static_cast<int>(*it)-48)*10;
				++it;
			}

			if(*it < '0' || *it > '9')
			{continue;}
			else
			{
				day = day+(static_cast<int>(*it)-48);
			}

			if ( day < 1 || day > DaysOfMonth_Nonleap[month-1] )
			{continue;}
			else
			{not_valid_date = false;}
		}
	}
	dt = year*10000 + month*100 + day;

	// TODO: Print out the date
	//       Sample outputs "1st January 2000", "2nd January 2015, 3rd February 2015, 4th July 2001, ...
    switch(day)
    {
        case 1:
        case 21:
        case 31:
            cout << day << "st " << MonthText[month-1] << " " << year << endl;
            break;
        case 2:
        case 22:
            cout << day << "nd " << MonthText[month-1] << " " << year << endl;
			break;
        case 3:
        case 23:
            cout << day << "rd " << MonthText[month-1] << " " << year << endl;
			break;
		default:
		    cout << day << "th " << MonthText[month-1] << " " << year << endl;
			break;
    }

	// TODO: Given 1-JAN-2000 is a SAT, print out the day of the week (e.g. MON, TUE, ...)
	//       Sample output "This is a Monday", "This is a Tuesday", ...
		int count_day  = 0;

		///calculate the years difference
		count_day = (year-2000)*365 + (year-2000 +3)/4; 

		//calculate the months difference
		if(leap_year == true)
		{
			for(int count_month = 0; count_month != month-1; ++count_month)
				count_day = count_day + (DaysOfMonth_Leap[count_month]-01) + 1;
		}
		
		else if (leap_year == false)
		{
			for(int count_month = 0; count_month != month-1; ++count_month)
				count_day = count_day + (DaysOfMonth_Nonleap[count_month]-01) + 1;
		}

		///calculte the days differnece
		count_day = count_day + (day-1);

		cout << "This is a " << DayOfWeekText[(count_day+6)%7] << endl;

	// TODO: Write a loop to input holidays (int YYYYMMDD) into a vector<int> "holidays".
	//       Assume all holidays entered are valid dates. No checking required.
	//       Enter '0' to end the input
	//       Print out the list of entered holidays.
	//       Sample output: 20150928, 20151001, 20151021, 20151225, 20151226
	bool end_holiday_loop = true;
	do
	{	
		cin >> dt;
		if( dt != 0)
		{holidays.push_back(dt);}
		else if (dt == 0)
		{end_holiday_loop = false;}
	}
	while(end_holiday_loop);

	if(holidays.empty() == false)
	{	
		vector<int>::iterator holiday_iterator = holidays.begin();
		for(; holiday_iterator != (holidays.end()-1); ++holiday_iterator)
		{cout << *holiday_iterator << ", ";}
		
		cout << *holiday_iterator << endl;
	}

	// TODO: Adjust the entered date using the Modified Following Business Convention
	//       Definition of Modified Following
	//       http://www.nasdaq.com/investing/glossary/m/modified-following-businessday-convention
	//       Print out the adjusted date (format YYYYDDMM)
	//       Sample output: "Modified Following Adjusted Date is 20150925"

	dt = year*10000 + month*100 + day;
	//holiday, week, bound
	//forward
	bool move_to_next_day = false;
	bool move_to_previous_day = false;

	//creat variable for testing
	int test_dt = dt;
	int test_year = year;
	int test_month = month;
	int test_day = day;
	int test_day_of_week = (count_day+6);

	do
	{
		move_to_next_day = false;
		vector<int>::iterator holiday_iterator = holidays.begin();
		for(; holiday_iterator != holidays.end(); ++holiday_iterator)
		{
			if(*holiday_iterator == test_dt)
			{
				move_to_next_day = true;
				break;
			}
		}

		if(DayOfWeekText[test_day_of_week%7] == "Sunday" || DayOfWeekText[test_day_of_week%7] == "Saturday")
		{move_to_next_day = true;}
		
		//check out of bound
		bool out_of_bound = false;
		if(leap_year == true)
		{
			if( test_day > DaysOfMonth_Leap[month-01])
			{out_of_bound = true;}
		}

		else if(leap_year == false)
		{
			if( test_day > DaysOfMonth_Nonleap[month-01])
			{out_of_bound = true;}
		}

		if(out_of_bound == true)
		{
			move_to_next_day = true;
			break;
		}

		if(move_to_next_day == true)
		{
			++test_dt;
			++test_day_of_week;
			++test_day;
		}
	}
	while(move_to_next_day);

	//if moving forward out of bound, move backward then.
	if(move_to_next_day == true)
	{	//re-initialse the variable
		test_dt = dt;
		test_year = year;
		test_month = month;
		test_day = day;
		test_day_of_week = (count_day+6);
		do
		{ 
			move_to_previous_day = false;

			vector<int>::iterator holiday_iterator = holidays.begin();
			for(; holiday_iterator != holidays.end(); ++holiday_iterator)
			{
				if(*holiday_iterator == test_dt)
				{
					move_to_previous_day = true;
					break;
				}
			}
			if(DayOfWeekText[test_day_of_week%7] == "Sunday" || DayOfWeekText[test_day_of_week%7] == "Saturday")
			{move_to_previous_day = true;}

			if(move_to_previous_day == true)
			{
				--test_dt;
				--test_day_of_week;
				--test_day;
			}
		}
		while(move_to_previous_day);
	}


	cout << "Modified Following Adjusted Date is " << test_dt << endl;

	return 0;
}