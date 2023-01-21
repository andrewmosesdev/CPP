#include <iostream>
using namespace std;

class Clock
{
private:
    int hours;
    int minutes;
    int seconds;
    bool is24Hour;

public:
    Clock(bool is24Hour)
    {
        this->is24Hour = is24Hour;
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    void addHour()
    {
        hours = (hours + 1) % (is24Hour ? 24 : 12);
    }

    void addMinute()
    {
        if (++minutes >= 60)
        {
            addHour();
            minutes = 0;
        }
    }

    void addSecond()
    {
        if (++seconds >= 60)
        {
            addMinute();
            seconds = 0;
        }
    }

    void displayTime()
    {
        cout << "*****************" << endl;
        cout << "* " << (is24Hour ? "24-Hour Clock" : "12-Hour Clock") << " *" << endl;
        cout << "*   ";
        if (!is24Hour)
        {
            cout << (hours == 0 ? 12 : hours) << ":";
        }
        else
        {
            cout << (hours < 10 ? "0" : "") << hours << ":";
        }
        cout << (minutes < 10 ? "0" : "") << minutes << ":";
        cout << (seconds < 10 ? "0" : "") << seconds;
        if (!is24Hour)
        {
            cout << (hours < 12 ? " AM" : " PM") << "  *" << endl;
        }
        else
        {
            cout << "    *" << endl;
        }
        cout << "*****************" << endl;
    }
};

void generateMenu()
{
    cout << "************************" << endl;
    cout << "* 1 - Add One Hour     *" << endl;
    cout << "* 2 - Add One Minute   *" << endl;
    cout << "* 3 - Add One Second   *" << endl;
    cout << "* 4 - Exit Program     *" << endl;
    cout << "************************" << endl;
}

int main()
{
    Clock clock12(false);
    Clock clock24(true);

    while (true)
    {
        generateMenu();

        int userChoice;
        cin >> userChoice;

        switch (userChoice)
        {
        case 1:
            clock12.addHour();
            clock24.addHour();
            break;
        case 2:
            clock12.addMinute();
            clock24.addMinute();
            break;
        case 3:
            clock12.addSecond();
            clock24.addSecond();
            break;
        case 4:
            return 0;
            break;
        default:
            cout << "Invalid Input, Please Try Again" << endl;
            break;
        }
        clock12.displayTime();
        clock24.displayTime();
    }
}
