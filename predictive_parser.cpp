#include <iostream>

using namespace std;
#include "./predictive_parser.h"
/**
 * E
 *   : T E’
 *   ;
 */
bool E() {
    return T() && _E();
  }
  
  /**
   * E’
   *   : + T E’
   *   | ε
   *   ;
   */
  bool _E() {
    // + T E’
    if (lookahead() == "+") {
      return term("+") && T() && _E();
    }
    // ε
    return true;
  }
  
  // -------------------------------------------------
  
  /**
   * T
   *   : F T’
   *   ;
   */
  bool T() {
    return F() && _T();
  }
  
  /**
   * T’
   *   : * F T’
   *   | ε
   *   ;
   */
  bool _T() {
    // * F T’
    if (lookahead() == "*") {
      return term("*") && F() && _T();
    }
    // ε
    return true;
  }
  
  // -------------------------------------------------
  
  /**
   * F
   *   : NUMBER
   *   ;
   */
  bool F() {
    return term("a");
  }
  
  // -------------------------------------------------
  // Token manipulations:
  
  int cursor = 0;
  string source;
  
  /**
   * Returns a token at cursor (lookahead).
   */
  string lookahead() {
    return source.substr(cursor,1);
  }
  
  /**
   * Expects a token, and increases the cursor.
   */
  bool term(string expected) {
    return source.substr(cursor++,1) == expected;
  }
  
  /**
   * Initializes the parsing string and cursor.
   *
   * Attempts to parse a string starting from the main symbol.
   */
  bool parse(string s) {
    source = s;
    cursor = 0;
    return E() && cursor == s.length();
  }
  
  // -------------------------------------------------
  // Tests:
