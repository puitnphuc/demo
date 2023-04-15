#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
class poly
{
public:
    int n;
    vector<int> coeff;
public:
    int getSize()
    {
        return n;
    }

    void creatPoly(int x)
    {
        n = x;
        coeff.resize(x+1);
        for(int i=0;i<=x;i++)
        {
            cin>>coeff[i];
        }

    }
    void show()
    {

        for(int i=0;i<=n; i++)
        {
            if(i==0)
            {
                cout<<coeff[i] <<"x^"<<i;
            }
            else if(coeff[i]>=0)
                cout<<"+"<<coeff[i] <<"x^"<<i;
            else
                cout<<coeff[i] <<"x^"<<i;

        }

    }

     poly operator + (const poly b)
    {
      poly result;
      int sz = max(n,b.n);
      result.n = sz;
      result.coeff.resize(sz+1);
      for(int i=0;i<=sz;i++)
      {
          result.coeff[i] = coeff[i] + b.coeff[i];

      }
      return result;
    }
    poly operator - (const poly b)
    {
      poly result;
      int sz = max(n,b.n);
      result.n = sz;
      result.coeff.resize(sz+1);
      for(int i=0;i<=sz;i++)
      {
          result.coeff[i] = coeff[i] - b.coeff[i];

      }
      return result;
    }


    poly operator * (const poly b)
    {
    poly result;
    int sz = n+b.n;
    result.n = sz;
    result.coeff.resize(sz+1,0);
    for(int i=0;i<= n;i++)
    {
        for(int j=0; j<= b.n;j++)
        {
            int index = i+j;
            result.coeff[index] += coeff[i]*b.coeff[j];
        }
    }



      return result;
    }



    void ChangeSz(int x)
    {
        coeff.resize(x+1,0);

        n = x;
    }
};



int main()
{
    int x;
    char command;
    poly a,b,result;
    cin>>x;
    a.creatPoly(x);
    cin>>x;
    b.creatPoly(x);

    cin>>command;
    if( command == '+' || command == '-')
    {   if(command =='+')
        {
        int resz = max(a.getSize(),b.getSize());
        ( a.getSize() >= b.getSize() ) ? b.ChangeSz(resz) : a.ChangeSz(resz);
            result = a+b;

        result.show(); }
        else
        {
        int resz = max(a.getSize(),b.getSize());
        ( a.getSize() >= b.getSize() ) ? b.ChangeSz(resz) : a.ChangeSz(resz);
            result = a-b;

        result.show();
        }
    }

    else
    {
        result = a*b;

         result.show();
    }


    return 0;
}
