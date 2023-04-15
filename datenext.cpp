#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
using namespace std;

class date
{
private:
    int day,month,year;
public:


    void chuanhoa();
    //friend int CheckDayOfmonth();
    //bool checkleap(int x);
    void command(int x);
    friend istream &operator >> (istream &input, date &x)
    {
    input >> x.day >> x.month >> x.year;
    return input;
    }
    friend ostream &operator << (ostream &output, date x)
    {
    output<<x.day<<" "<<x.month<<" "<<x.year<<endl;
    return output;
    }


};
bool checkleap(int x)
{
    if( (x%4==0 && x%100!=0)|| x%400==0 )
        return 1;

    return 0;
}

int CheckDayOfmonth(int month,int year)
{
    if(month==4||month==6||month==9||month==11)
        return 30;
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        return 31;
    if(month==2 && checkleap(year)==1 )
        return 29;
    if(month==2 && checkleap(year)==0 )
        return 28;
    return -1;
}



void date::command(int x)
{
    if(x==1)
    {
        int t,temp;
        temp = day;
        cin>>t;
        while(t>0)
        {
            temp=day;
            int k = CheckDayOfmonth(month,year);
            if( (day+t)<= k )
            {
                day +=t;
                break;
            }

            if(day <= k  )//means day+t >k
            {
                day =k;
                t -= day-temp;
                if(day==k && t>0)
                {
                    day=1;
                    --t;
                    ++month;
                    if(month>12)
                    {
                        ++year;
                    }
                    month = month%12;
                    if(month==0)
                    {
                        month=12;

                    }

                }
            }


        }
    }
    if(x==2)
    {
        int t,temp,k;
        temp = day;
        cin>>t;
        while(t>0)
        {
            temp=day;
            k = CheckDayOfmonth(month,year);

            if( (day-t) >=1 )
            {
                day -=t;
                break;
            }

            if(day >=1  )//means day-t<1
            {

                day=1;
                t -= temp-day;

                if(day==1 && t>0)
                {
                    --month;
                    day=(CheckDayOfmonth(month,year));
                    --t;

                    if(month ==0)
                    {
                        month = 12;
                        --year;
                    }
                }
            }//


        }
    }
    if(x==3)
    {
        date b;
        int d=0;
        cin>>b;

        if(b.year == year && b.month == month && b.day == day)
            cout<<0;
        else if(b.year == year && b.month == month)
            cout<< abs(b.day - day);
        else if( b.year == year)
        {
            if(b.month > month)
            {
                d = (b.day-1)+(CheckDayOfmonth(month,year)-day);
                for(int i = month+1; i<b.month; i++)
                    d+= CheckDayOfmonth(i,year)-1;
                d+= b.month - month;
                cout<<d;
            }
            else
            {
               d = (day-1)+(CheckDayOfmonth(b.month,year)-b.day);
                for(int i = b.month+1; i<month; i++)
                    d+= CheckDayOfmonth(i,year)-1;
                d+= month - b.month;
                cout<<d;
            }
        }
        else if(b.year !=year)
        {

            if(b.year > year)
            {
                if(b.month !=1){
                d = (b.day-1)+30;
                for(int i = b.month+1; i<b.month; i++)
                    d+= CheckDayOfmonth(i,b.year)-1;
                d+= b.month - 1;
                }
                else
                {
                    d= b.day -1;

                }

                if(month==12)
                {
                    d+= 31-day;
                }
                else
                {
                    d+=30+ CheckDayOfmonth(month,year)-day;
                    for(int i=month+1; i<12;i++)
                        d+= CheckDayOfmonth(i,year)-1;
                    d+= 12-month;
                }
                d+=1;
                cout<<d;
            }
            else
            {
                if(month !=1){
                d = (day-1)+30;
                for(int i = month+1; i<month; i++)
                    d+= CheckDayOfmonth(i,year)-1;
                d+= month - 1;
                }
                else
                {
                    d= day -1;

                }

                if(b.month==12)
                {
                    d+= 31-b.day;
                }
                else
                {
                    d+=30+ CheckDayOfmonth(b.month,b.year)-b.day;
                    for(int i=b.month+1; i<12;i++)
                        d+= CheckDayOfmonth(i,b.year)-1;
                    d+= 12-b.month;
                }
                d+=1;
                cout<<d;
            }

        }
    }
}

void date::chuanhoa()
{
this->day = abs(day);
this->month = abs(month);
this->year = abs(year);
this->month = (this->month) % 12; if (this->month == 0) this->month = 12;
if (this->day > CheckDayOfmonth(month,year))
{
     this->day = 1;
}

}
/*
void date::command(int x) {
    int t, k;
    switch(x) {
        case 1:
            cin >> t;
            while(t > 0) {
                k = CheckDayOfmonth(month, year);
                if(day + t <= k) {
                    day += t;
                    break;
                } else {
                    t -= k - day + 1;
                    day = 1;
                    ++month;
                    if(month > 12) {
                        ++year;
                        month = 1;
                    }
                }
            }
            break;
        case 2:
            cin >> t;
            while(t > 0) {
                if(day - t >= 1) {
                    day -= t;
                    break;
                } else {
                    t -= day - 1;
                    --month;
                    if(month < 1) {
                        --year;
                        month = 12;
                    }
                    day = CheckDayOfmonth(month, year);
                }
            }
            break;
        case 3:
            date b;
            cin >> b;
            if(b.year == year && b.month == month) {
                cout << abs(b.day - day);
            } else {
                int days = CheckDayOfmonth(month, year) - day;
                for(int m = month + 1; m <= 12; ++m) {
                    days += CheckDayOfmonth(m, year);
                }
                for(int y = year + 1; y < b.year; ++y) {
                    days += checkleap(y) ? 366 : 365;
                }
                for(int m = 1; m < b.month; ++m) {
                    days += CheckDayOfmonth(m, b.year);
                }
                days += b.day - 1;
                cout << days;
            }
            break;
    }
}
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    date a;
    int x;
    cin>>a;
    a.chuanhoa();
    while(true)
    {
        cin>>x;
        if(x==3)
        {
            a.command(x);
            return 0;
        }
        else
            a.command(x);

    }

    return 0;
}
