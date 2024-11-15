#include <stdio.h>

//ENDIANNESS can be used to figure out if you're on\ a
//Network device or a computer etc.

int main()
{
    int x = 0x12345678;
    char *ptr = (char*)&x;
    printf("First byte: 0x%x\n", ptr[4]);
    return 0;
}

/*will return '78' at ptr[0] then 56 at ptr[1] 34 at ptr[2] 12 at ptr[3]
storing back to front basically. Little endian*/