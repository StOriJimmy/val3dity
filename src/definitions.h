#ifndef VAL3DITY_VALIDATE_DEFS_H
#define VAL3DITY_VALIDATE_DEFS_H

/*
 val3dity - Copyright (c) 2011-2016, Hugo Ledoux.  All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     * Neither the name of the authors nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL HUGO LEDOUX BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
*/


// CGAL kernel
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/basic.h>
#include <CGAL/Triangulation_vertex_base_with_id_2.h>
#include <CGAL/Triangulation_face_base_with_info_2.h>
#include <CGAL/Polygon_2.h>

#include <CGAL/Nef_polyhedron_3.h>
#include <CGAL/IO/Polyhedron_iostream.h>
#include <CGAL/IO/Nef_polyhedron_iostream_3.h>
#include <CGAL/Polyhedron_copy_3.h>

#include <CGAL/Aff_transformation_3.h>

namespace val3dity
{

struct FaceInfo2
{
  FaceInfo2() {}
  int nesting_level;
  bool in_domain() {
    return nesting_level % 2 == 1;
  }
};  

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;

//
typedef K::Point_2                  Point2;
typedef K::Point_3                  Point3;
typedef K::Vector_3                 Vector;
typedef K::Triangle_3               Triangle;
typedef K::Tetrahedron_3            Tetrahedron;
typedef K::Plane_3                  Plane;
typedef CGAL::Polygon_2<K>          Polygon;
typedef CGAL::Polyhedron_3<K>       CgalPolyhedron;


// CGAL typedefs
typedef CGAL::Triangulation_vertex_base_with_id_2 <K>             Vb;
typedef CGAL::Triangulation_face_base_with_info_2<FaceInfo2, K>   Fbb;
typedef CGAL::Constrained_triangulation_face_base_2<K, Fbb>       Fb;
typedef CGAL::Triangulation_data_structure_2<Vb,Fb>               TDS;
typedef CGAL::Exact_intersections_tag                             Itag;
typedef CGAL::Constrained_triangulation_2<K, TDS, Itag>           CT;


//-- Nef requires EPEC (exact-predicates & exact-construction) and thus diff kernels
typedef CGAL::Exact_predicates_exact_constructions_kernel   KE;
typedef KE::Point_3                                         Point3E;
typedef KE::Plane_3                                         PlaneE;
typedef CGAL::Polyhedron_3<KE>                              CgalPolyhedronE;
typedef CGAL::Nef_polyhedron_3<KE>                          Nef_polyhedron;
typedef CGAL::Aff_transformation_3<KE>                      Transformation;

typedef CGAL::Polyhedron_copy_3<CgalPolyhedron, CgalPolyhedronE::HalfedgeDS> Polyhedron_convert; 


typedef long long int64;

typedef enum
{
  SOLID            = 0,
  COMPOSITESOLID   = 1,
  MULTISOLID       = 2,
  COMPOSITESURFACE = 3,
  MULTISURFACE     = 4,
  ALL              = 5,
} Primitive3D;

typedef enum
{
  GML   = 0,
  JSON  = 1,
  OBJ   = 2,
  POLY  = 3,
  OFF   = 4,
  OTHER = 5,
} InputTypes;

} // namespace val3dity

#endif
