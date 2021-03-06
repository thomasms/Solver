//
//  main.cpp
//  Solver
//
//  Created by Thomas Stainer on 05/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include <iostream>

#include "GridFactory.h"
#include "SolverFactory.h"
#include "GeneralException.h"

#include "Serializer.h"
#include "FileIO.h"

using namespace toast;

std::string filename_unsolved = "";

void GetCmdLineArgs(int argc, const char * argv[]){

    if ( argc != 2 )
        std::cout<<"usage: "<< argv[0] <<" <filename>\n";
    else {
        // We assume argv[1] is a filename to open
        filename_unsolved = std::string(argv[1]);
    }
}

int main(int argc, const char * argv[])
{
    try{
        GetCmdLineArgs(argc, argv);

        // Create an empty grid and the solver
        auto grid = factory::GridFactory::CreateEmptySquareGrid(0);
        auto solver = factory::SolverFactory::CreateBacktrackingSolver(grid);
        
        // Read in the grid from file
        io::ReadFromFile(filename_unsolved, grid);

        // Validate the grid
        grid->Validate();

        // Perform solve
        if(solver->Solve())
            std::cout << "Solution found!" << NEWLINE;
        else
            std::cout << "No solution found!" << NEWLINE;

        // Write the solved grid to file
        io::WriteToFile(filename_unsolved + ".solved", grid);

        // Write to std output
        io::Serialize<' '>(std::cout, grid);
    }
    catch(GeneralException& ex)
    {
        std::cout << ex.what() << NEWLINE;
    }
    catch(std::exception& ex)
    {
        std::cout << ex.what() << NEWLINE;
    }
    catch(...)
    {
        std::cout << "Unknown error!" << NEWLINE;
    }
    return 0;
}
