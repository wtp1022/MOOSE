#ifndef MOOSEAPP_H
#define MOOSEAPP_H

#include "MooseApp.h"

class MooseApp;

template<>
InputParameters validParams<MooseApp>();

class MooseApp : public MooseApp
{
public:
  MooseApp(InputParameters parameters);
  virtual ~MooseApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MOOSEAPP_H */
