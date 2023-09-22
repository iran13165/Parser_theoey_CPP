#include <iostream>

using namespace std;

bool E();
  /**
   * E’
   *   : + T E’
   *   | ε
   *   ;
   */
  bool _E();
  
  // -------------------------------------------------
  
  /**
   * T
   *   : F T’
   *   ;
   */
  bool T();
  
  /**
   * T’
   *   : * F T’
   *   | ε
   *   ;
   */
  bool _T();
  // -------------------------------------------------
  
  /**
   * F
   *   : NUMBER
   *   ;
   */
  bool F();
  string lookahead();
  
  /**
   * Expects a token, and increases the cursor.
   */
  bool term(string expected);

   bool parse(string s);