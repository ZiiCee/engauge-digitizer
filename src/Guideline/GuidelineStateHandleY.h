/******************************************************************************************************
 * (C) 2019 markummitchell@github.com. This file is part of Engauge Digitizer, which is released      *
 * under GNU General Public License version 2 (GPLv2) or (at your option) any later version. See file *
 * LICENSE or go to gnu.org/licenses for details. Distribution requires prior written permission.     *
 ******************************************************************************************************/

#ifndef GUIDELINE_STATE_HANDLE_Y_H
#define GUIDELINE_STATE_HANDLE_Y_H

#include "GuidelineStateHandleAbstract.h"

class GuidelineStateHandleY : public GuidelineStateHandleAbstract
{
public:
  /// Single constructor.
  GuidelineStateHandleY(GuidelineStateContext &context);
  virtual ~GuidelineStateHandleY();

  virtual void begin ();
  virtual void end ();
  virtual void handleMouseRelease (const QPointF &posScene);
  virtual QString stateName () const;

};

#endif // GUIDELINE_STATE_HANDLE_Y_H