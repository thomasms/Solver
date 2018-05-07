//
//  Grid.cpp
//  Solver
//
//  Created by Thomas Stainer on 05/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include "Grid.h"

namespace toast { namespace imp
{
    
    Grid::Grid(size_t nr_of_rows, size_t nr_of_columns)
    {
        CreateGrid(nr_of_rows, nr_of_columns);
    }

    Grid::~Grid()
    {
    }

    void Grid::CreateGrid(size_t nr_of_rows, size_t nr_of_columns)
    {
        _cells.resize(0);
        for(size_t i=0;i<nr_of_rows;++i){
            _cells.push_back(factory::CellFactory::CreateEmptyCellRow(nr_of_columns));
        }
    }
    
    void Grid::Operation(std::function<void(size_t row, size_t column)> func) const
    {
        for(size_t r=0; r<GetNrOfRows(); ++r)
        {
            for(size_t c=0; c<GetNrOfColumns(); ++c)
            {
                func(r,c);
            }
        }
    }

    void Grid::Validate() const
    {
        auto func = [&](size_t r, size_t c){
            auto cell = (*this)(r,c);
            cell->Validate();
            
            if((*cell) && ((*cell)() > GetMaxValue()))
                throw GridValidationException("Values cannot exceed the grid size");
        };
        Operation(func);
    }
      
  }
}
