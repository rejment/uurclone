static char buf[100];

struct Math
{
    static LPSTR PrintInt(int i)
    {

    }


    static float ParseFloat(LPSTR str)
    {
        return 0.0f;
    }

    static LPSTR PrintFloat(float f)
    {
        SecureZeroMemory(buf, 100);
        int trunc = (int) f;
        int digits = Digits(trunc);
        char *ptr = buf+digits;
        if (f < 0)
        {
            *buf = '-';
            ptr++;
            f = -f;
        }
        for (int i=0; i<digits; i++)
        {
            *(--ptr) = '0' + (trunc%10);
            trunc /= 10;
        }
        ptr += digits;

        float rest = f - (int)f;
        if (rest != 0.0) {
            *ptr++ = ',';
            for (int i=0; i<2; i++) {
                rest *= 10.0;
                *ptr++ = '0' + (((int)rest)%10);
                rest -= (int) rest;
            }

        }

        return buf;
    }

    static int Digits(int x)
    {
        int cnt = 0;
        while (x > 0) {
            x /= 10;
            cnt++;
        }
        return cnt;
    }
};