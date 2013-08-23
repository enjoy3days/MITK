/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center,
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/


#ifndef MITKOLDTYPECONVERSIONS_H_
#define MITKOLDTYPECONVERSIONS_H_

#include <vnl/vnl_quaternion.h>

#include "mitkTypeBasics.h"
#include "mitkTypedefs.h"
#include "mitkVector.h"


template <class T> class VectorTraits {
public:
  typedef T ValueType;
};

template <> class VectorTraits<mitk::VnlVector> {
public:
  typedef mitk::ScalarType ValueType;
};

template<> class VectorTraits<float[4]> {
public:
  typedef float ValueType;
};

template<> class VectorTraits< itk::Index<5> > {
public:
  typedef itk::Index<5>::IndexValueType ValueType;
};

template<> class VectorTraits< itk::Index<3> > {
public:
  typedef itk::Index<3>::IndexValueType ValueType;
};

template<> class VectorTraits< long int [3]> {
public:
  typedef long int ValueType;
};
template<> class VectorTraits< float [3]> {
public:
  typedef float ValueType;
};
template<> class VectorTraits< double [3]> {
public:
  typedef double ValueType;
};

template<> class VectorTraits< vnl_vector_fixed<mitk::ScalarType, 3> > {
public:
  typedef mitk::ScalarType ValueType;
};

template<> class VectorTraits< long unsigned int[3]> {
public:
  typedef long unsigned int ValueType;
};

template<> class VectorTraits< unsigned int *> {
public:
  typedef unsigned int ValueType;
};

template<> class VectorTraits< double[4] > {
public:
  typedef double ValueType;
};

template<> class VectorTraits< itk::Vector<float,3> > {
public:
  typedef float ValueType;
};

template<> class VectorTraits< itk::Vector<double,3> > {
public:
  typedef double ValueType;
};

template<> class VectorTraits< itk::Vector<int,3> > {
public:
  typedef int ValueType;
};
/*
template<> class VectorTraits< mitk::Vector<double,3> > {
public:
  typedef double ValueType;
};*/

template<> class VectorTraits< mitk::Point<float,3> > {
public:
  typedef float ValueType;
};

template<> class VectorTraits< mitk::Point<float,4> > {
public:
  typedef float ValueType;
};

template<> class VectorTraits< itk::Point<float,3> > {
public:
  typedef float ValueType;
};

template<> class VectorTraits< itk::Point<float,4> > {
public:
  typedef float ValueType;
};

template<> class VectorTraits< mitk::Point<double,3> > {
public:
  typedef double ValueType;
};

template<> class VectorTraits< mitk::Point<double,4> > {
public:
  typedef double ValueType;
};

template<> class VectorTraits< itk::Point<double,3> > {
public:
  typedef double ValueType;
};

template<> class VectorTraits< itk::Point<double,4> > {
public:
  typedef double ValueType;
};

template<> class VectorTraits< mitk::Point<int,3> > {
public:
  typedef int ValueType;
};

namespace mitk
{

  template <class Tout>
  inline void FillVector3D(Tout& out, mitk::ScalarType x, mitk::ScalarType y, mitk::ScalarType z)
  {
    out[0] = (typename VectorTraits<Tout>::ValueType)x;
    out[1] = (typename VectorTraits<Tout>::ValueType)y;
    out[2] = (typename VectorTraits<Tout>::ValueType)z;
  }
  template <class Tout>
  inline void FillVector4D(Tout& out, mitk::ScalarType x, mitk::ScalarType y, mitk::ScalarType z, mitk::ScalarType t)
  {
    out[0] = (typename VectorTraits<Tout>::ValueType)x;
    out[1] = (typename VectorTraits<Tout>::ValueType)y;
    out[2] = (typename VectorTraits<Tout>::ValueType)z;
    out[3] = (typename VectorTraits<Tout>::ValueType)t;
  }

  template <class Tin, class Tout>
  inline void itk2vtk(const Tin& in, Tout& out)
  {
    out[0]=(typename VectorTraits<Tout>::ValueType)(in[0]);
    out[1]=(typename VectorTraits<Tout>::ValueType)(in[1]);
    out[2]=(typename VectorTraits<Tout>::ValueType)(in[2]);
  }

  template <class Tin, class Tout>
  inline void vtk2itk(const Tin& in, Tout& out)
  {
    out[0]=(typename VectorTraits<Tout>::ValueType)(in[0]);
    out[1]=(typename VectorTraits<Tout>::ValueType)(in[1]);
    out[2]=(typename VectorTraits<Tout>::ValueType)(in[2]);
  }

  template <class Tin, class Tout>
  inline void vnl2vtk(const vnl_vector<Tin>& in, Tout *out)
  {
    unsigned int i;
    for(i=0; i<in.size();++i)
      out[i]=(Tout) (in[i]);
  }

  template <class Tin, class Tout>
  inline void vtk2vnl(const Tin *in, vnl_vector<Tout>& out)
  {
    unsigned int i;
    for(i=0; i<out.size();++i)
      out[i]=(Tout) (in[i]);
  }

  template <class Tin, class Tout>
  inline void vtk2vnlref(const Tin *in, vnl_vector_ref<Tout>& out)
  {
    unsigned int i;
    for(i=0; i<out.size();++i)
      out[i]=(Tout) (in[i]);
  }

  template <class Tin, class Tout, unsigned int n>
  inline void vnl2vtk(const vnl_vector_fixed<Tin, n>& in, Tout *out)
  {
    unsigned int i;
    for(i=0; i<in.size();++i)
      out[i]=(Tout) (in[i]);
  }

  template <class Tin, class Tout, unsigned int n>
  inline void vtk2vnl(const Tin *in, vnl_vector_fixed<Tout, n>& out)
  {
    unsigned int i;
    for(i=0; i<out.size();++i)
      out[i]=(Tout) (in[i]);
  }


  template <typename U, typename V, unsigned int NRows, unsigned int NColumns>
  inline void TransferMatrix(const itk::Matrix<U, NRows, NColumns>& in, itk::Matrix<V, NRows, NColumns>& out)
  {
    for (unsigned int i = 0; i < in.RowDimensions; ++i)
      for (unsigned int j = 0; j < in.ColumnDimensions; ++j)
        out[i][j] = in[i][j];
  }


} // namespace mitk





#endif /* MITKOLDTYPECONVERSIONS_H_ */
