#include "quadraticsolvermenudialog.h"

#include "quadraticsolvermaindialog.h"

int ribi::QuadraticSolverMenuDialog::ExecuteSpecific(const std::vector<std::string>& argv) noexcept
{
  const int argc = static_cast<int>(argv.size());
  if (argc > 0)
  {
    QuadraticSolverMainDialog d;
    d.Execute();
    return 0;
  }
  return 0;
}

ribi::About ribi::QuadraticSolverMenuDialog::GetAbout() const noexcept
{
  About a(
    "Richel Bilderbeek",
    "QuadraticSolver",
    "solver of quadratic equations",
    "November 21st of 2015",
    "2008-2015",
    "http://www.richelbilderbeek.nl/ToolQuadraticSolver.htm",
    GetVersion(),
    GetVersionHistory()
  );
  return a;
}

ribi::Help ribi::QuadraticSolverMenuDialog::GetHelp() const noexcept
{
  return Help(
    this->GetAbout().GetFileTitle(),
    this->GetAbout().GetFileDescription(),
    {

    },
    {

    }
  );
}

std::string ribi::QuadraticSolverMenuDialog::GetVersion() const noexcept
{
  return "3.0";
}

std::vector<std::string> ribi::QuadraticSolverMenuDialog::GetVersionHistory() const noexcept
{
  return {
    "2008-xx-xx: version 1.0: initial version in C++ Builder",
    "2013-08-26: version 2.0: port to Qt Creator, console version",
    "2013-10-01: version 2.1: added desktop version",
    "2015-01-02: version 2.2: added picture of equation to desktop version",
    "2015-11-21: version 3.0: moved to own GitHub"
  };
}

