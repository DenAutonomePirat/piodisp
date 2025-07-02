#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

uint32_t char_to_bit(int in)
{
    switch (in)
    {
    case ' ':
        return 0x00000000;
    case '!':
        return 0x000000c1;
    case '"':
        return 0x00008001;
    case '#':
        return 0x00029585;
    case '$':
        return 0x000e9586;
    case '%':
        return 0x000e8d8c;
    case '&':
        return 0x0007b300;
    case '\'':
        return 0x00008000;
    case '(':
        return 0x00000208;
    case ')':
        return 0x00010800;
    case '*':
        return 0x00038e0c;
    case '+':
        return 0x00028404;
    case '-':
        return 0x00020004;
    case '.':
        return 0x00000040;
    case ',':
        return 0x00004000;
    // return 0x00000040;
    case '/':
        return 0x00000808;
    case '1':
        return 0x00006001;
    // return 0x00008400;
    // return 0x00000081;
    // return 0x00000089;
    case '2':
        return 0x000e9800;
    // return 0x00063107;
    case '3':
        return 0x00069400;
    // return 0x00000187;
    // return 0x00041187;
    case '4':
        return 0x000a8400;
    // return 0x00008085;
    // return 0x000a0085;
    case '5':
        return 0x000e1400;
    // return 0x00008186;
    // return 0x000e1302;
    case '6':
        return 0x000e3400;
    // return 0x00008586;
    // return 0x000e3186;
    case '7':
        return 0x00048400;
    // return 0x00000083;
    // return 0x00040083;
    case '8':
        return 0x000eb400;
    // return 0x00008587;
    // return 0x000e3187;
    case '9':
        return 0x000e9400;
    // return 0x00008187;
    // return 0x000e1187;
    case '0':
        return 0x000cb400;
    // return 0x00008583;
    // return 0x000c398b;
    case ':':
        return 0x00008400;
    case ';':
        return 0x00008800;
    case '<':
        return 0x00020208;
    case '=':
        return 0x00021104;
    case '>':
        return 0x00010804;
    case '?':
        return 0x00040447;
    case '@':
        return 0x000cb107;
    case 'A':
        return 0x000e2087;
    case 'B':
        return 0x00049587;
    case 'C':
        return 0x000c3102;
    case 'D':
        return 0x00049583;
    case 'E':
        return 0x000e3102;
    case 'F':
        return 0x000e2002;
    case 'G':
        return 0x000c3186;
    case 'H':
        return 0x000a2085;
    case 'I':
        return 0x00049502;
    case 'J':
        return 0x00003181;
    case 'K':
        return 0x000a2208;
    case 'L':
        return 0x00083100;
    case 'M':
        return 0x00092089;
    case 'N':
        return 0x00092281;
    case 'O':
        return 0x000c3183;
    case 'P':
        return 0x000e2007;
    case 'Q':
        return 0x000c3383;
    case 'R':
        return 0x000e2207;
    case 'S':
        return 0x000e1186;
    case 'T':
        return 0x00048402;
    case 'U':
        return 0x00083181;
    case 'V':
        return 0x00082808;
    case 'W':
        return 0x00082a81;
    case 'X':
        return 0x00010a08;
    case 'Y':
        return 0x000a1185;
    case 'Z':
        return 0x0004190a;
    case '[':
        return 0x00008502;
    case '\\':
        return 0x00010200;
    case ']':
        return 0x00049400;
    case '^':
        return 0x00000a00;
    case '_':
        return 0x00001100;
    case '`':
        return 0x00010000;
    case 'a':
        return 0x00023500;
    case 'b':
        return 0x000a3400;
    case 'c':
        return 0x00023000;
    case 'd':
        return 0x00000585;
    case 'e':
        return 0x00023800;
    case 'f':
        return 0x00028406;
    case 'g':
        return 0x000e9400;
    case 'h':
        return 0x000a2400;
    case 'i':
        return 0x00000400;
    case 'j':
        return 0x0000b400;
    case 'k':
        return 0x00008608;
    case 'l':
        return 0x00082000;
    case 'm':
        return 0x00022484;
    case 'n':
        return 0x00022400;
    case 'o':
        return 0x00023400;
    case 'p':
        return 0x000ea000;
    case 'q':
        return 0x000e8400;
    case 'r':
        return 0x00022000;
    case 's':
        return 0x000e1400;
    case 't':
        return 0x000a3000;
    case 'u':
        return 0x00003400;
    case 'v':
        return 0x00002800;
    case 'w':
        return 0x00002a80;
    case 'x':
        return 0x00010a08;
    case 'y':
        return 0x00008185;
    case 'z':
        return 0x00021800;
    case '{':
        return 0x00028502;
    case '|':
        return 0x00008400;
    case '}':
        return 0x00049404;
    case '~':
        return 0x0002080c;
    // Cyrillic capital letter A: 'А', U+0410, UTF-8: D090, Pronunciation: 'A' as in 'car'
    case 0x410:
        return 0x0000088d;
    // Cyrillic capital letter BE: 'Б', U+0411, UTF-8: D091, Pronunciation: 'B' as in 'bat'
    case 0x411:
        return 0x000e3186;
    // Cyrillic capital letter VE: 'В', U+0412, UTF-8: D092, Pronunciation: 'V' as in 'vet'
    case 0x412:
        return 0x000e318e;
    // Cyrillic capital letter GHE: 'Г', U+0413, UTF-8: D093, Pronunciation: 'G' as in 'go'
    case 0x413:
        return 0x000c2002;
    // Cyrillic capital letter DE: 'Д', U+0414, UTF-8: D094, Pronunciation: 'D' as in 'dog'
    case 0x414:
        return 0x000059c9;
    // Cyrillic capital letter IE: 'Е', U+0415, UTF-8: D095, Pronunciation: 'Ye' as in 'yes'
    case 0x415:
        return 0x000e3106;
    // Cyrillic capital letter IO: 'Ё', U+0401, UTF-8: D081, Pronunciation: 'Yo' as in 'yonder'
    case 0x401:
        return 0x000e3106; // Same as 'Е' (U+0415)
    // Cyrillic capital letter ZHE: 'Ж', U+0416, UTF-8: D096, Pronunciation: 'Zh' as in 'measure'
    case 0x416:
        return 0x00018e08;
    // Cyrillic capital letter ZE: 'З', U+0417, UTF-8: D097, Pronunciation: 'Z' as in 'zoo'
    case 0x417:
        return 0x00061187;
    // Cyrillic capital letter I: 'И', U+0418, UTF-8: D098, Pronunciation: 'Ee' as in 'see'
    case 0x418:
        return 0x00082889;
    // Cyrillic capital letter KA: 'К', U+041A, UTF-8: D09A, Pronunciation: 'K' as in 'kite'
    case 0x41A:
        return 0x000a2208;
    // Cyrillic capital letter EL: 'Л', U+041B, UTF-8: D09B, Pronunciation: 'L' as in 'lamp'
    case 0x41B:
        return 0x00000889;
    // Cyrillic capital letter EM: 'М', U+041C, UTF-8: D09C, Pronunciation: 'M' as in 'man'
    case 0x41C:
        return 0x00092089;
    // Cyrillic capital letter EN: 'Н', U+041D, UTF-8: D09D, Pronunciation: 'N' as in 'no'
    case 0x41D:
        return 0x000a2085;
    // Cyrillic capital letter O: 'О', U+041E, UTF-8: D09E, Pronunciation: 'O' as in 'more'
    case 0x41E:
        return 0x000c3183;
    // Cyrillic capital letter PE: 'П', U+041F, UTF-8: D09F, Pronunciation: 'P' as in 'pet'
    case 0x41F:
        return 0x000c2083;
    // Cyrillic capital letter ER: 'Р', U+0420, UTF-8: D0A0, Pronunciation: 'R' as in 'run' (rolled)
    case 0x420:
        return 0x000e2007;
    // Cyrillic capital letter ES: 'С', U+0421, UTF-8: D0A1, Pronunciation: 'S' as in 'see'
    case 0x421:
        return 0x000c3102;
    // Cyrillic capital letter TE: 'Т', U+0422, UTF-8: D0A2, Pronunciation: 'T' as in 'top'
    case 0x422:
        return 0x00048402;
    // Cyrillic capital letter EF: 'Ф', U+0424, UTF-8: D0A4, Pronunciation: 'F' as in 'fat'
    case 0x424:
        return 0x0009ae89;
    // Cyrillic capital letter SHA: 'Ш', U+0428, UTF-8: D0A8, Pronunciation: 'Sh' as in 'shut'
    case 0x428:
        return 0x0008a481;
    // Cyrillic capital letter SHCHA: 'Щ', U+0429, UTF-8: D0A9, Pronunciation: 'Shch' as in 'fresh cheese'
    case 0x429:
        return 0x0008a4c1;
    // Cyrillic capital letter U: 'У', U+0423, UTF-8: D0A3, Pronunciation: 'U' as in 'boot'
    case 0x423:
        return 0x000a1185;
    // Cyrillic capital letter CHE: 'Ч', U+0427, UTF-8: D0A7, Pronunciation: 'Ch' as in 'chat'
    case 0x427:
        return 0x000a0085;
    // Cyrillic capital letter YU: 'Ю', U+042E, UTF-8: D0AE, Pronunciation: 'Yu' as in 'universe'
    case 0x42E:
        return 0x000a2289;
    // Cyrillic capital letter YA: 'Я', U+042F, UTF-8: D0AF, Pronunciation: 'Ya' as in 'yard'
    case 0x42F:
        return 0x000e0887;
    default:
        return 0x00000001;
    }
}
// this function takes a string of 8 characters and converts each character to its corresponding bit representation
void vfd_put_8(char input[], uint32_t *dst)
{
    for (int i = 0; i < 8; ++i)
    {
        *(dst + i) = char_to_bit(*(input + i));
        // printf("%b", char_to_bit(*(input + i)));
    }
}

// Helper function to decode one UTF-8 code point from a string
// Returns the code point and advances the pointer
static uint32_t utf8_decode(const char **s)
{
    const unsigned char *p = (const unsigned char *)*s;
    uint32_t cp;
    if (p[0] < 0x80)
    {
        cp = p[0];
        *s += 1;
    }
    else if ((p[0] & 0xE0) == 0xC0)
    {
        cp = ((p[0] & 0x1F) << 6) | (p[1] & 0x3F);
        *s += 2;
    }
    else if ((p[0] & 0xF0) == 0xE0)
    {
        cp = ((p[0] & 0x0F) << 12) | ((p[1] & 0x3F) << 6) | (p[2] & 0x3F);
        *s += 3;
    }
    else if ((p[0] & 0xF8) == 0xF0)
    {
        cp = ((p[0] & 0x07) << 18) | ((p[1] & 0x3F) << 12) | ((p[2] & 0x3F) << 6) | (p[3] & 0x3F);
        *s += 4;
    }
    else
    {
        cp = '?'; // Invalid UTF-8
        *s += 1;
    }
    return cp;
}

// Updated function: takes a UTF-8 string and converts the first 8 code points to bit patterns
void vfd_put_8_utf8(const char *input, uint32_t *dst)
{
    for (int i = 0; i < 8; ++i)
    {
        if (*input == '\0')
        {
            dst[i] = char_to_bit(' '); // pad with space if string is short
        }
        else
        {
            uint32_t cp = utf8_decode(&input);
            // printf("%x ", cp);
            dst[i] = char_to_bit(cp);
        }
        // printf("\n");
    }
}
