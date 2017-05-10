//
//  ISerializable.h
//  Solver
//
//  Created by Thomas Stainer on 07/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_API_ISERIALIZABLE_H
#define TOAST_API_ISERIALIZABLE_H

#include <iostream>
#include <iomanip> 
#include <memory>

using namespace toast::utils;

namespace toast { namespace api
  {
    /** @brief Interface for object that implements serialization
     *
     */
    class ISerializable
    {
    public:
      virtual ~ISerializable(){};
      virtual void Serialize(std::ostream& stream) const = 0;
      virtual void Deserialize(std::istream& stream) = 0;
    };
    
  }
}

#endif //TOAST_API_ISERIALIZABLE_H