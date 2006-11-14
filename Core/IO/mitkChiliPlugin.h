/*=========================================================================

Program:   Medical Imaging & Interaction Toolkit
Module:    $RCSfile$
Language:  C++
Date:      $Date$
Version:   $Revision$

Copyright (c) German Cancer Research Center, Division of Medical and
Biological Informatics. All rights reserved.
See MITKCopyright.txt or http://www.mitk.org/copyright.html for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.

=========================================================================*/


#ifndef MITKCHILIPLUGIN_H_HEADER_INCLUDED_C1EBD0AD
#define MITKCHILIPLUGIN_H_HEADER_INCLUDED_C1EBD0AD


#include <itkObject.h>
#include <itkObjectFactory.h>
#include <mitkCommon.h>

class QcPlugin;

namespace mitk {

const int m_QmitkChiliPluginConferenceID = 5001;
typedef enum
{
  MITKc = 0,
  QTc,
  LAUNCHc,
  ARRANGEc,
  TOKENREQUESTc,
  TOKENSETc,
  TEXTc,
  MOUSEMOVEc ,
} ConfMsgType;

class ChiliPlugin : public itk::Object

{
public:
  static bool IsPlugin();
  static QcPlugin* GetPluginInstance();
  static void SetPluginInstance(QcPlugin* instance);
  static int GetConferenceID();

  mitkClassMacro(ChiliPlugin,itk::Object);
  itkNewMacro(ChiliPlugin);
  virtual ~ChiliPlugin();
protected:
  ChiliPlugin::ChiliPlugin() {}
private:
  static QcPlugin* s_PluginInstance;
};



} // namespace mitk

#endif /* MITKCHILIPLUGIN_H_HEADER_INCLUDED_C1EBD0AD */
