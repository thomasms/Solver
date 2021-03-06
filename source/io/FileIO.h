//
//  FileIO.h
//  Solver
//
//  Created by Thomas Stainer on 07/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_IO_FILE_IO_H
#define TOAST_IO_FILE_IO_H

#include <fstream>

#include "GeneralException.h"
#include "Types.h"

#include "Serializer.h"

#include "IGrid.h"

namespace toast { namespace io
  {
    void WriteToFile(std::string filename, const PTR<api::IGrid>& grid)
    {
      std::ofstream file(filename);
      if(!file)
        throw utils::GeneralException("Cannot open file: " + filename);

      file << grid;
      file.close();
    }
    
    void ReadFromFile(std::string filename, PTR<api::IGrid>& grid)
    {
      std::ifstream file(filename);
      if(!file)
        throw utils::GeneralException("Cannot open file: " + filename);

      file >> grid;
      file.close();
    }
  }
}
#endif //TOAST_IO_FILE_IO_H
