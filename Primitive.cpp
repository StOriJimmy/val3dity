//
//  Primitive.cpp
//  val3dity
//
//  Created by Hugo Ledoux on 25/10/16.
//
//

#include "Primitive.h"


Primitive::Primitive() {
}




void Primitive::add_error(int code, std::string faceid, std::string info)
{
  std::tuple<std::string, std::string> a(faceid, info);
  _errors[code].push_back(a);
  std::clog << "\tERROR " << code << ": " << errorcode2description(code);
  if (faceid.empty() == false)
    std::clog << " (id: " << faceid << ")";
  std::clog << std::endl;
  if (info.empty() == false)
    std::clog << "\t[" << info << "]" << std::endl;
}

std::set<int> Primitive::get_unique_error_codes()
{
  std::set<int> errs;
  for (auto& err : _errors)
  {
    errs.insert(std::get<0>(err));
  }
  return errs;
}



