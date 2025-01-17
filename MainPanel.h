#ifndef HEADER_MainPanel
#define HEADER_MainPanel
/*
htop - ColumnsPanel.h
*/

#include "Action.h"
#include "IncSet.h"
#include "Panel.h"

typedef struct MainPanel_ {
   Panel super;
   State* state;
   IncSet* inc;
   Htop_Action *keys;
   pid_t pidSearch;
} MainPanel;

typedef bool(*MainPanel_ForeachProcessFn)(Process*, Arg);

#define MainPanel_getFunctionBar(this_) (((Panel*)(this_))->defaultBar)

void MainPanel_updateTreeFunctions(MainPanel* this, bool mode);

void MainPanel_pidSearch(MainPanel* this, int ch);

int MainPanel_selectedPid(MainPanel* this);

const char* MainPanel_getValue(MainPanel* this, int i);

bool MainPanel_foreachProcess(MainPanel* this, MainPanel_ForeachProcessFn fn, Arg arg, bool* wasAnyTagged);

extern PanelClass MainPanel_class;

MainPanel* MainPanel_new(void);

void MainPanel_setState(MainPanel* this, State* state);

void MainPanel_delete(Object* object);

#endif
