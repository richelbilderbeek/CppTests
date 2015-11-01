#include <iostream>
#include <sstream>
#include <boost/date_time/gregorian/gregorian.hpp>

int main()
{
  boost::gregorian::date day = boost::gregorian::day_clock::local_day();

  for (int i=0; i!=40; ++i)
  {
    std::cout << i << ": " << boost::gregorian::to_iso_string(day) << '\n';
    day += boost::gregorian::days(1);
  }

}
/* Screen output on November 1st 2015

0: 20151101
1: 20151102
2: 20151103
3: 20151104
4: 20151105
5: 20151106
6: 20151107
7: 20151108
8: 20151109
9: 20151110
10: 20151111
11: 20151112
12: 20151113
13: 20151114
14: 20151115
15: 20151116
16: 20151117
17: 20151118
18: 20151119
19: 20151120
20: 20151121
21: 20151122
22: 20151123
23: 20151124
24: 20151125
25: 20151126
26: 20151127
27: 20151128
28: 20151129
29: 20151130
30: 20151201
31: 20151202
32: 20151203
33: 20151204
34: 20151205
35: 20151206
36: 20151207
37: 20151208
38: 20151209
39: 20151210
Press <RETURN> to close this window...

*/
