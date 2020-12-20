// n! = n * (n - 1) * (n - 2) * ... * 2 * 1
// O(n)
int factorial(unsigned int i)
{
    if (i <= 1)
        return (1);
    return (i * factorial(i - 1));
}