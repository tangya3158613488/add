#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main()
{
	int n = 0x11223344;
	char *pc = (char *)&n;
	char *pi = (char *)&n;
	*pc = 0x55;
	*pi = 0;
	return 0;
}
class Solution {
public:
    int StrToInt(string str) {
        if(str.size()==0 || str.empty())
            return 0;
        int fuhao = 1;
        if(str[0] == '-')
        {
            fuhao = -1;
            str[0] = '0';
        }
        else if(str[0] == '+')
        {
            fuhao = 1;
            str[0] = '0';
        }
        double sum=0;
        for(size_t i = 0;i < str.size(); i++)
        {
            if(str[i] < '0' || str[i] > '9')
            {
                sum = 0;
                break;
            }
            sum = sum * 10 + str[i] - '0';
        }
        return fuhao * sum;
    }
};

