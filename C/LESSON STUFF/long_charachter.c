#include <stdio.h>
#include <wchar.h>

int main() {
    wchar_t unicodeChar = L'你'; //unicode for 'you' in chinese
    wprintf(L"Unicode char: %lc\n", unicodeChar);
    return 0;
}
