//
//  CellCheckerTester.h
//  Solver
//
//  Created by Thomas Stainer on 10/06/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_UNIT_TESTS_CELL_CHECKER_TESTER_H
#define TOAST_UNIT_TESTS_CELL_CHECKER_TESTER_H

#include "catch.hpp"

#include "Types.h"

#include "IGrid.h"
#include "CellChecker.h"

#include "ITester.h"

using namespace toast::utils;

namespace toast { namespace unittests
  {
    class CellCheckerTester : public ITwoCaseTester
    {
    public:
      CellCheckerTester(const PTR<api::IGrid>& grid,
                        size_t row_index,
                        size_t column_index,
                        TNATURAL value)
      :
      _grid(grid),
      _row_index(row_index),
      _column_index(column_index),
      _value(value)
      {
      }
      
      virtual ~CellCheckerTester()
      {
      }
      
      virtual void ValidateSunny() override
      {
        ValidateGrid();
        REQUIRE(imp::CellChecker(_grid).IsOk(_row_index, _column_index, _value) == true);
      }
      
      virtual void ValidateRainy() override
      {
        ValidateGrid();
        REQUIRE(imp::CellChecker(_grid).IsOk(_row_index, _column_index, _value) == false);
      }
      
    private:
      void ValidateGrid()
      {
        REQUIRE(_grid != nullptr);
        REQUIRE_NOTHROW(_grid->Validate());
      }
      
    private:
      TNATURAL _value;
      size_t _row_index;
      size_t _column_index;
      PTR<api::IGrid> _grid;
    };
    
  }
}

#endif //TOAST_UNIT_TESTS_CELL_CHECKER_TESTER_H
