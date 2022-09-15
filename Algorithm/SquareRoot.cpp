float Q_sqrt(float z)
{
    unsigned int b;
    float g;
    b = *(unsigned int *)&z;

    b = (b >> 1) + 0x1fbffb72; // wtf
    g = *(float *)&b;
    g = (.5 * g + .5 * z / g);
    g = (.5 * g + .5 * z / g);
    return g;
}

float B_sqrt_search(float n, float an, float bn)
{
    float accuracy = 0.0001;
    float ans = (an + bn) / 2;
    if (ans * ans - n < accuracy && ans * ans - n > 0)
    {
        return ans;
    }
    if (ans * ans > n)
    {
        B_sqrt_search(n, an, ans);
    }
    else
    {
        B_sqrt_search(n, ans, bn);
    }
}

float B_sqrt(float n)
{
    float accuracy = 0.00001;
    float an = 0;
    float bn = n;
    float ans;
    while (ans * ans - n > accuracy || ans * ans - n < 0)
    {
        ans = (an + bn) / 2;
        if (ans * ans > n)
        {
            bn = ans;
        }
        else
        {
            an = ans;
        }
    }
    return ans;
}

float N_sqrt(float n)
{
    if (n == 0)
    {
        return 0.0;
    }
        double last = 0.0;
    double res = 1.0;
    while (res != last) {
        last = res;
        res = (res + n / res) / 2.0;
    }
    return res;
}