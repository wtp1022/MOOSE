#include "MooseApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<MooseApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

MooseApp::MooseApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(processor_id());

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  MooseApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  MooseApp::associateSyntax(_syntax, _action_factory);
}

MooseApp::~MooseApp()
{
}

void
MooseApp::registerApps()
{
  registerApp(MooseApp);
}

void
MooseApp::registerObjects(Factory & factory)
{
}

void
MooseApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
