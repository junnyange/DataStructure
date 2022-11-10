
//컴퓨터공학과 2021112045 허준상

#include "logbook.h"

Logbook::Logbook(int month, int year)
{
    logMonth = month;
    logYear = year;
    memset(entries, 0, sizeof(entries)); //배열을 0으로 초기화 하는 함수! memset!
}

void Logbook::putEntry(int day, int value)
{
    entries[day-1] = value;
}

int Logbook::getEntry(int day) const
{
    return entries[day-1];
}

int Logbook::getMonth() const
{
    return logMonth;
}

int Logbook::getYear() const
{
    return logYear;
}

int Logbook::getDaysInMonth() const
{
    //31days 1,3,5,7,8,10,12
    //30days 4,6,9,11
    //28or29days 2 
    if (logMonth == 1 || logMonth == 3 || logMonth == 5 || logMonth == 7 || logMonth == 8 || logMonth == 10 || logMonth == 12)
        return 31;
    else if (logMonth == 4 || logMonth == 6 || logMonth == 9 || logMonth == 11)
        return 30;
    else
    {
        if (isLeapYear() == true)
            return 29;
        else
            return 28;
    }

}

bool Logbook::isLeapYear() const
{
    //LeapYear : 해가 4의 배수이면서 100의 배수가 아니면 윤년, 해가 400의 배수이면 윤년
    if ((logYear % 4 == 0 && logYear % 100 != 0) || logYear % 400 == 0)
        return true;
    else
        return false;
}

// In-lab operations
void Logbook::displayCalendar() const
{
    int count = 0;
    cout << "\t\t\t" << logMonth << " / " << logYear << "\n";
    cout << "Sun\t" << "Mon\t" << "Tue\t" << "Wed\t" << "Thu\t" << "Fri\t" << "Sat\t" << "\n";
    for (int i = 0; i < getDayOfWeek(1); i++)
    {
        cout << "\t";
        count++; //공백도 날짜에 포함해주어야함
    }
    for (int j = 1; j <= getDaysInMonth(); j++)
    {
        cout << j << " " << entries[j - 1] << "\t";
        count++;
        if (count == 7) //7이면 한칸내림
        {
            cout << "\n";
            count = 0;
        }
    }
}

int Logbook::getDayOfWeek(int day) const
{
    int nYears = logYear - 1901;
    int nLeapYears = 0;
    int nDaysToMonth = 0;

    for (int i = 1901; i < logYear; i++)
    {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
            nLeapYears++;
    }

    for (int j = 1; j < getMonth(); j++)
    {
        if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12)
            nDaysToMonth += 31;
        else if (j == 4 || j == 6 || j == 9 || j == 11)
            nDaysToMonth += 30;
        else
        {
            if (isLeapYear()==true)
                nDaysToMonth += 29;
            else
                nDaysToMonth += 28;
        }
    }

    int dayOfWeek = (1 + nYears + nLeapYears + nDaysToMonth + day) % 7;

    return dayOfWeek;
}