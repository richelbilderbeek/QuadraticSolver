#ifndef QUADRATICSOLVERMENUDIALOG_H
#define QUADRATICSOLVERMENUDIALOG_H

#include "menudialog.h"

namespace ribi {

///GUI independent QuadraticSolver menu dialog
struct QuadraticSolverMenuDialog final : public MenuDialog
{
  About GetAbout() const noexcept override;
  Help GetHelp() const noexcept override;
  std::string GetVersion() const noexcept override;
  std::vector<std::string> GetVersionHistory() const noexcept override;

  private:
  int ExecuteSpecific(const std::vector<std::string>& argv) noexcept override;

};

} //~namespace ribi

#endif // QUADRATICSOLVERMENUDIALOG_H
