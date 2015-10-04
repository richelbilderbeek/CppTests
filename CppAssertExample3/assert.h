//---------------------------------------------------------------------------
/*
Assert, a custom assert macro
Copyright (C) 2011 Richel Bilderbeek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/CppAssert.htm
//---------------------------------------------------------------------------
#ifndef BILDERBIKKEL_QT_ASSERT_H
#define BILDERBIKKEL_QT_ASSERT_H

//From http://www.richelbilderbeek.nl/CppAssert.htm
#ifdef NDEBUG_BILDERBIKKEL
  #define Assert(x) ((void)0)
#else
  #include <fstream>
  #include <iostream>
  #include <stdexcept>

  #define Assert(x)                      \
  if (!(x))                              \
  {                                      \
    std::cout                            \
      << "ERROR!! Assertion "            \
      <<  std::string (#x)               \
      <<  " failed\n on line "           \
      <<  (__LINE__)                     \
      <<  "\n in file "                  \
      <<  __FILE__                       \
      << std::endl;                      \
    std::ofstream f("assert_out.txt");   \
    f                                    \
      << "ERROR!! Assertion "            \
      <<  std::string (#x)               \
      <<  " failed\n on line "           \
      <<  (__LINE__)                     \
      <<  "\n in file "                  \
      <<  __FILE__                       \
      << std::endl;                      \
    f.close();                           \
      throw std::logic_error(            \
        "Assertion failed");             \
  }

#endif

#endif // BILDERBIKKEL_QT_ASSERT_H
