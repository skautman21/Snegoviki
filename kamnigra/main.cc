#include <iostream>
#include <iomanip>
#include <sstream>
#include <random>
#include <ctime>

int main() {

    int minm = 10;
    int maxm = 20;
    int val, a = 1, b, c = 3;
    std::minstd_rand gen(time(nullptr));
    val = minm + gen() % (maxm - minm + 1);
    std::cout << "Камней всего: " << val << std::endl;

    while (val != 0) {
        if (val >= 3) {
            for (int i=1; i<=3; i++)
            if (((val-1)-i)%4==0) {a=i; }
            if (val==3) {a=2; }

        } else {
            if (val==2) {a=1; }
        }

        std::cout << "Компьютер забрал: " << a << std::endl;
        val = val - a;
        if (val <= 0) {
            goto ex;
        }

        std::cout << "Камней осталось: " << val << std::endl;
        std::cin >> b;

        if (b >= 4 || b <= 0) {
            std::cout << "Больше 3 нельзя!" << std::endl;
            while (b >= 4 || b <= 0) {
                std::cin >> b;
            }
            val -= b;
        } else {
            val = val - b;
            if (val <= 0) {
                c = 0;
                goto ex;
            }
        }

    }
    ex:

    if (c == 0)
        std::cout << "Поражение! Компьютер победил" << std::endl;
    else

        std::cout << "Победа! Вы победили" << std::endl;

    return 0;
}
