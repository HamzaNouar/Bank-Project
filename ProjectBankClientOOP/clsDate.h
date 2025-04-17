#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cctype>
#include "clsString.h";
using namespace std;

class clsDate
{
	short _Day = 0, _Month = 0, _Year = 0;
	string _Date;
	short _Hour = 0, _Min = 0, _Sec = 0;
public:

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}
	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}
	clsDate(string Date)
	{
		*this = StringToDate(Date);
	}
	clsDate(short DateOrderOfYear, short Year)
	{
		*this = GetDateFromDayOrderInYear(DateOrderOfYear, Year);
	}

	void SetDay(short Day)
	{
		_Day = Day;
	}
	short GetDay()
	{
		return _Day;
	}
	void SetMonth(short Month)
	{
		_Month = Month;
	}
	short GetMonth()
	{
		return _Month;
	}
	void SetYear(short Year)
	{
		_Year = Year;
	}
	short GetYear()
	{
		return _Year;
	}
	void SetDate(string Date)
	{
		_Date = Date;
	}
	string GetDate()
	{
		return _Date;
	}

	__declspec(property(get = GetDay, put = SetDay)) short Day;
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;
	__declspec(property(get = GetYear, put = SetYear)) short Year;
	__declspec(property(get = GetDate, put = SetDate)) string strDate;

	void Print()
	{
		cout << _Day << "/" << _Month << "/" << _Year << endl;
	}
	static clsDate GetSystemDate()
	{
		clsDate Date;
		time_t t = time(0);
		tm* now = localtime(&t);

		Date.Day = now->tm_mday;
		Date.Month = now->tm_mon + 1;
		Date.Year = now->tm_year + 1900;

		return Date;
	}
	static string GetSystemDateTimeString()
	{
		//system datetime string
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));

	}
	static clsDate StringToDate(string DateString)
	{
		clsDate Date;
		vector <string> vSplitDates;

		vSplitDates = clsString::Split(DateString, "/");

		Date.Day = stoi(vSplitDates[0]);
		Date.Month = stoi(vSplitDates[1]);
		Date.Year = stoi(vSplitDates[2]);


		return Date;
	}
	static string DateToString(clsDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}
	static bool IsLeapYear(int Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}
	bool IsLeapYear()
	{
		return IsLeapYear(Year);
	}
	static short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month > 12)
		{
			return 0;
		}

		short Arr31Days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Arr31Days[Month];
	}
	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(Month, Year);
	}
	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{
		clsDate Date;
		short RemainingDays = DateOrderInYear;
		short MonthsDays = 0;

		Date.Year = Year;
		Date.Month = 1;

		while (true)
		{
			MonthsDays = NumberOfDaysInAMonth(Date.Month, Year);

			if (RemainingDays > MonthsDays)
			{
				RemainingDays -= MonthsDays;
				Date.Month++;
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}

		return Date;

	}
	void GetDateFromDayOrderInYear(short DateOrderInYear)
	{
		*this = GetDateFromDayOrderInYear(DateOrderInYear, Year);
	}
	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}
	bool IsDateBeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}
	static bool IsLastDayInMonth(clsDate Date)
	{
		return Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year);
	}
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}
	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}
	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(Month);
	}
	static clsDate IncreaseDateByOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}

		return Date;
	}
	void IncreaseDateByOneDay()
	{
		*this = IncreaseDateByOneDay(*this);
	}
	static void SwapDate(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;

		TempDate.Day = Date1.Day;
		TempDate.Month = Date1.Month;
		TempDate.Year = Date1.Year;

		Date1.Day = Date2.Day;
		Date1.Month = Date2.Month;
		Date1.Year = Date2.Year;

		Date2.Day = TempDate.Day;
		Date2.Month = TempDate.Month;
		Date2.Year = TempDate.Year;

	}
	void SwapDate(clsDate& Date2)
	{
		SwapDate(*this, Date2);
	}
	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		short SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDate(Date1, Date2);
			SwapFlagValue = -1;
		}
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return (IncludeEndDay) ? ++Days * SwapFlagValue : Days * SwapFlagValue;
	}
	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}
	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
	}
	bool IsDateEqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}
	static short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;

		for (short i = 1; i < Month; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, Year);
		}

		TotalDays += Day;

		return TotalDays;
	}
	short NumberOfDaysFromTheBeginingOfTheYear()
	{
		return NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);
	}
	static clsDate DateAddDays(short Days, clsDate Date)
	{

		short DaysOrderInYear = NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
		short RemainingDays = DaysOrderInYear + Days;

		short MonthsDays = 0;
		Date.Month = 1;

		while (true)
		{
			MonthsDays = NumberOfDaysInAMonth(Date.Month, Date.Year);

			if (RemainingDays > MonthsDays)
			{
				RemainingDays -= MonthsDays;
				Date.Month++;

				if (Date.Month > 12)
				{
					Date.Month = 1;
					Date.Year++;
				}

			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}

		return Date;

	}
	void AddDays(short Days)
	{
		*this = DateAddDays(Days, *this);
	}
	static short DayOfWeekOrder(short Day, short Month, short Year)
	{
		int A = (14 - Month) / 12;
		int Y = Year - A;
		int M = Month + (12 * A) - 2;


		return (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + (31 * M / 12)) % 7;
	}
	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(Day, Month, Year);
	}
	static short DayOfWeekOrderr(clsDate Date)
	{
		return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	}
	short DayOfWeekOrderr()
	{
		return DayOfWeekOrderr(*this);
	}
	static string MonthShortName(short MonthNumber)
	{
		string ArrMonthName[13] = { "","Jan","Feb","Mar","Apr"
			,"May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

		return ArrMonthName[MonthNumber];
	}
	string MonthShortName()
	{
		return MonthShortName(Month);
	}
	static void PrintMonthCalendar(short Month, short Year)
	{

		short NumberOfDays = NumberOfDaysInAMonth(Month, Year);
		short current = DayOfWeekOrder(1, Month, Year);

		printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());

		short i = 0;
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
		for (i; i < current; i++)
		{
			printf("     ");
		}
		for (short j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);
			if (++i == 7)
			{
				i = 0;
				cout << endl;
			}
		}

		printf("\n  _________________________________\n");
	}
	void PrintMonthCalendar()
	{
		PrintMonthCalendar(Month, Year);
	}
	static void PrintYearCalendar(short Year)
	{

		printf("\n  _________________________________\n\n");
		printf("\t    Calendar %d", Year);
		printf("\n  _________________________________\n");

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}
	}
	void PrintYearCalendar()
	{
		PrintYearCalendar(Year);
	}
	static bool IsEndOfWeek(clsDate Date)
	{
		return (DayOfWeekOrderr(Date) == 0);

	}
	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}
	static bool IsWeekEnd(clsDate Date)
	{
		return (DayOfWeekOrderr(Date) == 6 || DayOfWeekOrderr(Date) == 5);

	}
	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}
	static bool IsBusinessDay(clsDate Date)
	{
		return !IsWeekEnd(Date);
	}
	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}
	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 6 - DayOfWeekOrderr(Date);
	}
	short DaysUntilTheEndOfWeek()
	{
		return DaysUntilTheEndOfWeek(*this);
	}
	static short DaysUntilTheEndOfMonth(clsDate Date)
	{
		clsDate EndOfMonthDate;
		EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
		EndOfMonthDate.Month = Date.Month;
		EndOfMonthDate.Year = Date.Year;

		return GetDifferenceInDays(Date, EndOfMonthDate, true);
	}
	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}
	static short DaysUntilTheEndOfYear(clsDate Date)
	{
		clsDate EndOfYearDate;
		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date.Year;

		return GetDifferenceInDays(Date, EndOfYearDate, true);
	}
	short DaysUntilTheEndOfYear()
	{
		return DaysUntilTheEndOfYear(*this);
	}
	static short NumberOfHoursInAMonth(short Year, short Month)
	{
		return NumberOfDaysInAMonth(Year, Month) * 24;
	}
	short NumberOfHoursInAMonth()
	{
		return NumberOfHoursInAMonth(_Year, _Month);
	}
	static int NumberOfMinuteInAMonth(short Year, short Month)
	{
		return  NumberOfHoursInAMonth(Year, Month) * 60;
	}
	int NumberOfMinuteInAMonth()
	{
		return NumberOfMinuteInAMonth(_Year, _Month);
	}
	static int NumberOfSecondsInAMonth(short Year, short Month)
	{
		return NumberOfMinuteInAMonth(Year, Month) * 60;

	}
	int NumberOfSecondsInAMonth()
	{
		return NumberOfSecondsInAMonth(_Year, _Month);
	}
	static short NumberOfDaysInAYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}
	short NumberOfDaysInAYear()
	{
		return NumberOfDaysInAYear(_Year);
	}
	static short NumberOfHoursInAYear(short Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	}
	short NumberOfHoursInAYear()
	{
		return NumberOfHoursInAYear(_Year);
	}
	static int NumberOfMinuteInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}
	int NumberOfMinuteInAYear()
	{
		return NumberOfMinuteInAYear(_Year);
	}
	static int NumberOfSecondsInAYear(short Year)
	{
		return NumberOfMinuteInAYear(Year) * 60;

	}
	int NumberOfSecondsInAYear()
	{
		return NumberOfSecondsInAYear(_Year);
	}
	static clsDate IncreaseDateByXDays(short Days, clsDate Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}
	void IncreaseDateByXDays(short Days)
	{
		*this = IncreaseDateByXDays(Days, *this);
	}
	static clsDate IncreaseDateByOneWeek(clsDate Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}
	void IncreaseDateByOneWeek()
	{
		*this = IncreaseDateByOneWeek(*this);
	}
	static clsDate IncreaseDateByXWeeks(short Weeks, clsDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void IncreaseDateByXWeeks(short Weeks)
	{
		*this = IncreaseDateByXWeeks(Weeks, *this);
	}
	static clsDate IncreaseDateByOneMonth(clsDate Date)
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}

		return Date;
	}
	void IncreaseDateByOneMonth()
	{
		*this = IncreaseDateByOneMonth(*this);
	}
	static clsDate IncreaseDateByXMonths(short Months, clsDate Date)
	{

		for (short i = 1; i <= Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void IncreaseDateByXMonths(short Months)
	{
		*this = IncreaseDateByXMonths(Months, *this);
	}
	static clsDate IncreaseDateByOneYear(clsDate Date)
	{
		Date.Year++;
		return Date;
	}
	void IncreaseDateByOneYear()
	{
		*this = IncreaseDateByOneYear(*this);
	}
	static clsDate IncreaseDateByXYears(short Years, clsDate Date)
	{

		for (short i = 1; i <= Years; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	void IncreaseDateByXYears(short Years)
	{
		*this = IncreaseDateByXYears(Years, *this);
	}
	static clsDate IncreaseDateByXYearsFaster(short Years, clsDate Date)
	{
		Date.Year += Years;
		return Date;
	}
	void IncreaseDateByXYearsFaster(short Years)
	{
		*this = IncreaseDateByXYearsFaster(Years, *this);
	}
	static clsDate IncreaseDateByOneDecade(clsDate Date)
	{
		Date.Year += 10;
		return Date;
	}
	void IncreaseDateByOneDecade()
	{
		*this = IncreaseDateByOneDecade(*this);
	}
	static clsDate IncreaseDateByXDecades(short Decades, clsDate Date)
	{
		for (short i = 1; i <= Decades * 10; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	void IncreaseDateByXDecades(short Decades)
	{
		*this = IncreaseDateByXDecades(Decades, *this);
	}
	static clsDate IncreaseDateByXDecadesFaster(short Decades, clsDate Date)
	{
		Date.Year += Decades * 10;
		return Date;
	}
	void IncreaseDateByXDecadesFaster(short Decades)
	{
		*this = IncreaseDateByXDecadesFaster(Decades, *this);
	}
	static clsDate IncreaseDateByOneCentury(clsDate Date)
	{
		Date.Year += 100;
		return Date;
	}
	void IncreaseDateByOneCentury()
	{
		*this = IncreaseDateByOneCentury(*this);
	}
	static clsDate IncreaseDateByOneMillennium(clsDate Date)
	{
		Date.Year += 1000;
		return Date;
	}
	void IncreaseDateByOneMillennium()
	{
		*this = IncreaseDateByOneMillennium(*this);
	}
	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Month = 12;
				Date.Day = 31;
				Date.Year--;

			}
			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
			}
		}
		else
		{
			Date.Day--;
		}

		return Date;
	}
	void DecreaseDateByOneDay()
	{
		*this = DecreaseDateByOneDay(*this);
	}
	static clsDate DecreaseDateByXDays(short Days, clsDate Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseDateByXDays(short Days)
	{
		*this = DecreaseDateByXDays(Days, *this);
	}
	static clsDate DecreaseDateByOneWeek(clsDate Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseDateByOneWeek()
	{
		*this = DecreaseDateByOneWeek(*this);
	}
	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void DecreaseDateByXWeeks(short Weeks)
	{
		*this = DecreaseDateByXWeeks(Weeks, *this);
	}
	static clsDate DecreaseDateByOneMonth(clsDate Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
		}
		return Date;
	}
	void DecreaseDateByOneMonth()
	{
		*this = DecreaseDateByOneMonth(*this);
	}
	static clsDate DecreaseDateByXMonths(short Months, clsDate Date)
	{

		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void DecreaseDateByXMonths(short Months)
	{
		*this = DecreaseDateByXMonths(Months, *this);
	}
	static clsDate DecreaseDateByOneYear(clsDate Date)
	{
		Date.Year--;
		return Date;
	}
	void DecreaseDateByOneYear()
	{
		*this = DecreaseDateByOneYear(*this);
	}
	static clsDate DecreaseDateByXYears(short Years, clsDate Date)
	{

		for (short i = 1; i <= Years; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}
	void DecreaseDateByXYears(short Years)
	{
		*this = DecreaseDateByXYears(Years, *this);
	}
	static clsDate DecreaseDateByXYearsFaster(short Years, clsDate Date)
	{
		Date.Year -= Years;
		return Date;
	}
	void DecreaseDateByXYearsFaster(short Years)
	{
		*this = DecreaseDateByXYearsFaster(Years, *this);
	}
	static clsDate DecreaseDateByOneDecade(clsDate Date)
	{
		Date.Year -= 10;
		return Date;
	}
	void DecreaseDateByOneDecade()
	{
		*this = DecreaseDateByOneDecade(*this);
	}
	static clsDate DecreaseDateByXDecades(short Decades, clsDate Date)
	{
		for (short i = 1; i <= Decades * 10; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}
	void DecreaseDateByXDecades(short Decades)
	{
		*this = DecreaseDateByXDecades(Decades, *this);
	}
	static clsDate DecreaseDateByXDecadesFaster(short Decades, clsDate Date)
	{
		Date.Year -= Decades * 10;
		return Date;
	}
	void DecreaseDateByXDecadesFaster(short Decades)
	{
		*this = DecreaseDateByXDecadesFaster(Decades, *this);
	}
	static clsDate DecreaseDateByOneCentury(clsDate Date)
	{
		Date.Year -= 100;
		return Date;
	}
	void DecreaseDateByOneCentury()
	{
		*this = DecreaseDateByOneCentury(*this);
	}
	static clsDate DecreaseDateByOneMillennium(clsDate Date)
	{
		Date.Year -= 1000;
		return Date;
	}
	void DecreaseDateByOneMillennium()
	{
		*this = DecreaseDateByOneMillennium(*this);
	}
	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		short DaysCount = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				DaysCount++;

			DateFrom = IncreaseDateByOneDay(DateFrom);


		}
		return DaysCount;
	}
	short CalculateVacationDays(clsDate DateTo)
	{
		return CalculateVacationDays(*this, DateTo);
	}
	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short Days)
	{
		short WeekendCounter = 0;

		for (short i = 1; i <= Days; i++)
		{
			if (IsWeekEnd(DateFrom))
				WeekendCounter++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}
		for (short i = 1; i <= WeekendCounter; i++)
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DateFrom;
	}
	void CalculateVacationReturnDate(short Days)
	{
		*this = CalculateVacationReturnDate(*this, Days);
	}
	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}
	bool IsDateAfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}
	enum enDateCompare { Before = -1, Equal = 0, After = 1 };
	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1AfterDate2(Date1, Date2))
			return enDateCompare::After;

		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		return enDateCompare::Equal;

	}
	static bool IsValideDate(clsDate Date)
	{
		if (Date.Day < 1 || Date.Day > 31)
			return false;

		if (Date.Month < 1 || Date.Month > 12)
			return false;

		if (Date.Month == 2)
		{
			if (IsLeapYear(Date.Year))
			{
				if (Date.Day > 29)
					return false;
			}
			else
			{
				if (Date.Day > 28)
					return false;
			}
		}

		if (Date.Day > NumberOfDaysInAMonth(Date.Month, Date.Year))
			return false;

		return true;
	}
	bool IsValideDate()
	{
		return IsValideDate(*this);
	}
	static string FormatDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormattedDateString = "";

		FormattedDateString = clsString::ReplaceWord(DateFormat, "dd", to_string(Date.Day));
		FormattedDateString = clsString::ReplaceWord(FormattedDateString, "mm", to_string(Date.Month));
		FormattedDateString = clsString::ReplaceWord(FormattedDateString, "yyyy", to_string(Date.Year));

		return FormattedDateString;
	}
	string FormatDate(string DateFormat = "dd/mm/yyyy")
	{
		return FormatDate(*this, DateFormat);
	}

};

