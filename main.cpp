#include "classBigDecInt.h"
int main() {
    cout << "\n\t\t\t\t\t [===== Class Big Decimal Integer =====]" << endl;
    BigDecimalInt num1("+45454634646464646"), num2("+64554557878851241452");
    BigDecimalInt res = num1.operator+(num2);
    cout << "\nThe result : ";
    cout << res ;
}
