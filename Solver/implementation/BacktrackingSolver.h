//
//  BacktrackingSolver.h
//  Solver
//
//  Created by Thomas Stainer on 09/06/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_IMP_BACKTRACKING_SOLVER_H
#define TOAST_IMP_BACKTRACKING_SOLVER_H

#include <cmath>
#include <vector>

#include "CellChecker.h"
#include "GridOperation.h"
#include "GeneralException.h"

#include "ISolver.h"

namespace toast { namespace imp
  {
    class BacktrackingSolver : public api::ISolver
    {
    public:
      BacktrackingSolver();
      ~BacktrackingSolver();
      
      // Returns false if no solution exists
      virtual bool Solve(PTR<api::IGrid>& grid) override;
      
    private:
      bool VerifyGrid(PTR<api::IGrid>& grid) const;
      bool Loop(PTR<api::IGrid>& grid);
      bool Initialise(PTR<api::IGrid>& grid);
      
    private:
      std::vector< PTR<api::ICell> > _empty_cells;
    };
  }
}

#endif //TOAST_IMP_BACKTRACKING_SOLVER_H
