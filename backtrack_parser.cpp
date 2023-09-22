#include <stdlib.h>
#include <iostream>


using namespace std;

void backtrack_cursor();
void save_cursor();
bool E1();
bool E2();
bool T();
bool T1();
bool T2();
bool term(string expected);
bool F()
{
    return term("a");
}
/***
* grammar E: T+E | T
*/
bool E()
{
    return E1() || E2();
}
bool E1()
{
    save_cursor();
  return T() && term("+") && T();
}
bool E2()
{
    backtrack_cursor();
      save_cursor();
  return T();
}

/***
 * grammar T: F*T | F
*/
bool T()
{
     return T1() || T2();
}
bool T1()
{
     save_cursor();
   return F() && term("*") && T();
}
bool T2()
{
     backtrack_cursor();
      save_cursor();
   return F();
}

int cursor=0;
int saved_cursor = cursor;
string source;
void save_cursor()
{
    saved_cursor = cursor;
}
void backtrack_cursor()
{
    cursor = saved_cursor;
}
bool term(string expected)
{
    return source.substr(cursor++,1) == expected;
}
bool parse(string s)
{
    source = s;
    cursor = 0;
    return E() && s.length() == cursor;
}