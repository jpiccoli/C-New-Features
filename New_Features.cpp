// New_Features.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include "cpp14.h"

#include <iostream>
#include <any>
#include <variant>
#include <string>

#include <boost/any.hpp>
#include <boost/variant.hpp>

int main()
{
  std::cout << "This is a test program of C++14 and C++ 17 new features\n\n";

  show_cpp_14_features();

  std::cout << '\n';

  std::cout << "------------------------\n";
  std::cout << "Any\n";
  std::cout << "------------------------\n\n";

  std::cout << "----------------\n";
  std::cout << "C++ 17 std::any:\n";
  std::cout << "----------------\n";
  auto a = std::any( 42 );
  std::cout << "a #1 = " << std::any_cast<int>(a) << '\n';
  a = true;
  std::cout << "a #2 = " << std::boolalpha << std::any_cast<bool>(a) << '\n';

  std::cout << std::endl;

  std::cout << "----------\n";
  std::cout << "boost::any\n";
  std::cout << "----------\n";
  boost::any b = 1;
  std::cout << "b #1 = " << boost::any_cast<int>(b) << '\n';
  std::cout << "Type = " << b.type().name() << '\n';

  b = 3.14;
  std::cout << "b #2 = " << boost::any_cast<double>(b) << '\n';
  std::cout << "Type = " << b.type().name() << '\n';

  b = true;
  std::cout << "b # = 3 " << std::boolalpha << boost::any_cast<bool>(b) << '\n';
  std::cout << "Type = " << b.type().name() << '\n';
  std::cout << std::endl;

  std::cout << "------------------------\n";
  std::cout << "Variant\n";
  std::cout << "------------------------\n";


  std::cout << "------------------------\n";
  std::cout << "boost::variant\n";
  std::cout << "------------------------\n";

  // STL Algorithms
  // sample
  // clamp
  // iota
  // reduce
  // exclusive_scan
  // inclusive_scan
  // transform_reduce
  // transform_exclusive_scan
  // transform_inclusive_scan

  // Functional
  // invoke
  // not_fn

  // Utility
  // byte
  // default_searcher
  // boyer_moore
  // boyer_more_horspool
  // apply
  // make_from_tuple
  // to_chars
  // from_chars
  // chars_format



}

