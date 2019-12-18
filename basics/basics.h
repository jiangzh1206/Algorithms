#pragma once



namespace basics
{
    
    // 欧几里得算法， q是0最大公约数为p
    inline int gcd(int p, int q)
    {
        if (q == 0) {
            return p;
        }
        int r = p % q;
        return gcd(q, r);
    }




} // namespace basics

