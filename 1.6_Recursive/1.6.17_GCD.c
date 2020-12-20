// Euclid Algorithm
// GCD(n, m) == GCD(m, n mod m)
int GCD(int m, int n)
{
    if (m < n)
        return (GCD(n, m));
    if (m % n == 0)
        return (n);
    return (GCD(n, m % n));
}