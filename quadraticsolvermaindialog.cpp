#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "quadraticsolvermaindialog.h"

#include <cmath>
#include <iostream>
#include <iterator>
#include <sstream>

#include <boost/lexical_cast.hpp>

#pragma GCC diagnostic pop

ribi::QuadraticSolverMainDialog::QuadraticSolverMainDialog()
{

}

std::string ribi::QuadraticSolverMainDialog::AskUserForString() noexcept
{
  std::string s;
  std::getline(std::cin,s);
  return s;
}

double ribi::QuadraticSolverMainDialog::AskUserForDouble() noexcept
{
  while (1)
  {
    const std::string s = AskUserForString();
    if (IsDouble(s)==false) continue;
    return boost::lexical_cast<double>(s);
  }
}

void ribi::QuadraticSolverMainDialog::Execute() const noexcept
{
  while (1)
  {
    std::cout << "Please enter a value for a" << std::endl;
    const double a = AskUserForDouble();
    std::cout << "Please enter a value for b" << std::endl;
    const double b = AskUserForDouble();
    std::cout << "Please enter a value for c" << std::endl;
    const double c = AskUserForDouble();
    std::cout << "Solutions of this quadratic equations are:" << std::endl;
    const std::vector<double> v = ribi::QuadraticSolverMainDialog::SolveQuadratic(a,b,c);
    std::copy(v.begin(),v.end(),std::ostream_iterator<double>(std::cout," "));
    if (v.empty()==true)
      std::cout << "None..." << std::endl;
    else
      std::cout << std::endl;
    std::cout << "Type 'q' to quit, anything else to continue." << std::endl;
    const std::string quit = AskUserForString();
    if (quit == "q" || quit == "Q") break;
  }
}

bool ribi::QuadraticSolverMainDialog::IsDouble(const std::string& s) noexcept
{
  std::istringstream i(s);
  double temp;
  return ( (i >> temp) ? true : false );
}

const std::vector<double> ribi::QuadraticSolverMainDialog::SolveQuadratic(
  const double a, const double b, const double c)
{
  if (a == 0.0)
  {
    if (b == 0.0)
      return std::vector<double>(1,0.0);
    else
      return std::vector<double>(1,c/b);
  }
  const double d = (b * b) - (4.0 * a * c);
  if (d < 0.0)
    return std::vector<double>();
  if (d == 0.0)
    return std::vector<double>(1,-b/(2.0*a));
  const double rD = std::sqrt(d);
  std::vector<double> solutions;
  solutions.reserve(2);
  solutions.push_back((-b + rD)/(2.0 * a));
  solutions.push_back((-b - rD)/(2.0 * a));
  return solutions;
}


