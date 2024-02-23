#include <iostream>
#include <cstring>
using namespace std;

const int size1 = 1000000;

void reverse(char* str, int len)                 // for reverse string
{
    int start = 0, end = len - 1;
    while (start < end) {
        swap(*(str + start), *(str + end));
        start++;
        end--;
    }
}

void copyString(char* dest, const char* src)  // copy one string to another
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}


char* add(char* num1, char* num2)                // add two input and return result
{
    int len1 = strlen(num1), len2 = strlen(num2);
    int len = max(len1, len2);
    char* res = new char[len + 1];
    int carry = 0, sum;
    for (int i = 0; i < len; i++) {
        int n1 = (i < len1) ? (num1[len1 - i - 1] - '0') : 0;
        int n2 = (i < len2) ? (num2[len2 - i - 1] - '0') : 0;
        sum = n1 + n2 + carry;
        res[i] = (sum % 10) + '0';
        carry = sum / 10;
    }
    if (carry) {
        res[len] = carry + '0';
        res[len + 1] = '\0';
    }
    else {
        res[len] = '\0';
    }

    int count = 0;
    for (int i = 0; res[i] != NULL;i++)
        count++;

    reverse(res,count );

    return res;
}




char*  countEmailSequences(int n)                   // find total ways of input to send emails
{
    if (n < 3) 
    {
        if (n < 1) {
            char a[1];
            a[0] = 0;
            return a;
        }

        if (n == 1) {
            char a[1];
            a[0] = 0;
            return a;
        }

        if (n == 2) {
            char a[1];
            a[0] = 1;
            return a;
        }
    }


    char* first = new char[size1]{ "1"};  // declaration
    char* second = new char[size1]{ "1"};
    char*result=new char[size1];

 
    for (int i = 2; i <= n; i++)           // bottom up  approach
    { 
        copyString(result, add(first, second));   // used the concept of Fibonacci series
        copyString(first, second);
        copyString(second, result);
    }
    return second;
}


int main() 
{

    int n;
    
    cout << " Enter how many emails to send : ";
    cin >> n;

   string total_ways=countEmailSequences(n); // return total ways
    
    
    int count = 0;
     for (int i = 0; total_ways[i] != NULL;i++)      // count total digit of result
    count++;

     cout << " Result" << endl;

     cout << total_ways << endl;                          
     cout << " OR " << endl;
     cout << total_ways[0] << "."<<total_ways[1]<<"E" << count - 1 << endl;



    return 0;
}
