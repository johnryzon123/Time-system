#include "util.h"
//Function to do base10(decimal) => base16(hexadecimal)
void dectohex(int dec, char hex[]){
    if (dec == 0){
        hex[0] = '0';
        hex[1] = '\0';
        return;
    }
    char hexmap[] = "0123456789ABCDEF";//The hexmap is all the hex charaters
    //Loop
    for (int i = 0; i < 8; i++){
        //The bit masking way to turn base10 to 16
        int shift = 28 - (i * 4);
        int map_key = (dec >> shift) & 0xF;
        hex[2+i] = hexmap[map_key];
    }
    //Add a null terminator at the end
    hex[10] = '\0';
    return;
}
