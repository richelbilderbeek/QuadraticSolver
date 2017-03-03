#ifndef QUADRATICSOLVERMAINDIALOG_H
#define QUADRATICSOLVERMAINDIALOG_H

#include <string>
#include <vector>

namespace ribi {

struct QuadraticSolverMainDialog
{
  QuadraticSolverMainDialog();

  void Execute() const noexcept;

  ///Calculates all solutions from the quadratic equation,
  ///y = a.x.x + b.x + c
  ///From http://www.richelbilderbeek.nl/CppSolveQuadratic.htm
  static const std::vector<double> SolveQuadratic(
    const double a, const double b, const double c);

  private:
  //From http://www.richelbilderbeek.nl/CppAskUserForString.htm
  static std::string AskUserForString() noexcept;

  //From http://www.richelbilderbeek.nl/CppAskUserForDouble.htm
  static double AskUserForDouble() noexcept;

  //From http://www.richelbilderbeek.nl/CppIsDouble.htm
  static bool IsDouble(const std::string& s) noexcept;
};

} //~namespace ribi

#endif // QUADRATICSOLVERMAINDIALOG_H
