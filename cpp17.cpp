#include "cpp14.h"

#include <algorithm>
#include <chrono>
#include <execution>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <random>
#include <string>
#include <tuple>
#include <type_traits>
#include <vector>

#include <any>
#include <variant>

#include <boost/any.hpp>
#include <boost/variant.hpp>

void show_cpp_17_features()
{
  std::cout << "\n\n";
  std::cout << "--------------\n";
  std::cout << "C++17 features\n";
  std::cout << "--------------\n";

  std::cout << '\n';

  std::cout << "----------------\n";
  std::cout << "Any\n";
  std::cout << "----------------\n\n";

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

  std::cout << '\n';

  std::cout << "--------------\n";
  std::cout << "STL Algorithms\n";
  std::cout << "--------------\n";
  
  // for_each_n
  std::vector<int> v1{ 3, 5, 7, 9, 11, 15, 17 };
  std::for_each_n( v1.begin(), 4, [] ( auto& n ) { n = n * n; } );
  if( v1[ 0 ] != 9  || v1[ 1 ] != 25 || v1[ 2 ] != 49 || v1[ 3 ] != 81 ||
      v1[ 4 ] != 11 || v1[ 5 ] != 15 || v1[ 6 ] != 17 )
    std::cout << "std::for_each_n failure\n\n";
  else
    std::cout << "std::for_each_n success\n\n";

  // sample
  std::vector<int> v2;
  std::sample( v1.begin(), v1.end(), std::back_inserter( v2 ), 2, std::mt19937{ std::random_device{}() } );
  std::cout << "std::sample() output = ";
  for( auto val : v2 )
    std::cout << val << ", ";

  std::cout << "\n\n";

  // clamp
  auto low = 27;
  auto high = 123;
  auto res1 = std::clamp( 23, low, high );
  if( res1 == 27 )
    std::cout << "std::clamp() for below low passed\n";
  else
    std::cout << "std::clamp() for below low failed\n";

  res1 = std::clamp( 124, low, high );
  if( res1 == 123 )
    std::cout << "std::clamp() for above high passed\n";
  else
    std::cout << "std::clamp() for above high failed\n";

  res1 = std::clamp( 77, low, high );
  if( res1 == 77 )
    std::cout << "std::clamp() for in range value passed\n\n";
  else
    std::cout << "std::clamp() for in range value failed\n\n";

  // std::reduce -> compare with std::accumulate
  std::vector<double> v( 100'000, 0.5 );
  auto t1a = std::chrono::high_resolution_clock::now();
  double result1 = std::accumulate( v.begin(), v.end(), 11.0 );
  auto t2a = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> ms1 = t2a - t1a;
  std::cout << std::fixed << "std::accumulate = " << result1 << " took " << ms1.count() << " ms\n";

  auto t1r = std::chrono::high_resolution_clock::now();
  double result2 = std::reduce(/*std::execution::par,*/ v.begin(), v.end(), 11.0 );
  auto t2r = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> ms2 = t2r - t1r;
  std::cout << std::fixed << "std::reduce = " << result2 << " took " << ms2.count() << " ms\n\n";

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
