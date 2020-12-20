// O(n)
void printInt(unsigned int number, const int base)
{
    char *conversion = "0123456789ABCDEF";
    char digit = number % base;
    if (number /= base)
        printInt(number, base);
    printf("%c", conversion[digit]);
}