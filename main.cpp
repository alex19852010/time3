#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main()
{
    bool on; // если в переменной значение 1 или больше еденицы то запускаем таймер
    tm t;
    cout << "enter time in MM:SS format:";
    cin >> get_time(&t, "%M:%S"); // вводим нужное значение в таймер

    while (1)
    {
        cout << "enter 1 to start counting:";
        cin >> on;
        if (on)
        {
            break;
        }
    }

    time_t now = time(nullptr); //текущее время
    time_t target = now + t.tm_min * 60 + t.tm_sec; // прибавляем к текущему времени значение нашего таймера
    cout << "countdown has started !!!" << endl;
    double check = 0; //если значение этой переменной отличается от разности target и now, то выводим зачение таймера
    while (now < target)
    {
        now = time(nullptr);
        double d = difftime(target, now);
        time_t f = (time_t)d;
        tm *local = localtime(&f);
        if (check != d)
        {
            cout << put_time(local, "%M:%S") << endl;
        }

        check = d;
    }

    cout << "DING! DING! DING!" << endl;

    return 0;
}
