/******************************************************************************************************
 * (C) 2019 markummitchell@github.com. This file is part of Engauge Digitizer, which is released      *
 * under GNU General Public License version 2 (GPLv2) or (at your option) any later version. See file *
 * LICENSE or go to gnu.org/licenses for details. Distribution requires prior written permission.     *
 ******************************************************************************************************/

#include "EngaugeAssert.h"
#include "GraphicsScene.h"
#include "GuidelineAbstract.h"
#include "GuidelineFormat.h"
#include "GuidelineState.h"
#include "GuidelineStateContext.h"
#include "GuidelineStateHandleAbstract.h"
#include "Logger.h"
#include <QPen>
#include "ZValues.h"

GuidelineStateHandleAbstract::GuidelineStateHandleAbstract (GuidelineStateContext &context) :
  GuidelineStateAbstractBase (context)
{
}

GuidelineStateHandleAbstract::~GuidelineStateHandleAbstract ()
{
}

void GuidelineStateHandleAbstract::beginCommon ()
{
  LOG4CPP_INFO_S ((*mainCat)) << "GuidelineStateHandleAbstract::beginCommon";

  GuidelineFormat guidelineFormat (context().color());
  
  context().guideline().setGraphicsItemZValue (Z_VALUE_GUIDELINE_HANDLE);
  context().guideline().setGraphicsItemVisible (true);
  // ItemIsSelectable is overkill, and in special cases adds ugly selected dashes
  context().guideline().setGraphicsItemFlags (QGraphicsItem::ItemIsFocusable |
                                              QGraphicsItem::ItemIsMovable);
  context().guideline().setGraphicsItemAcceptHoverEvents (false);
  context().guideline().setGraphicsItemPen (guidelineFormat.colorHidden (),
                                            guidelineFormat.lineWidthNonHover ());
}

QPointF GuidelineStateHandleAbstract::convertGraphCoordinateToScreenPoint (double /* valueGraph */)
{
  LOG4CPP_ERROR_S ((*mainCat)) << "GuidelineStateHandleAbstract::convertGraphCoordinateToScreenPoint "
                               << "should not be called";

  ENGAUGE_ASSERT (false);

  return QPointF (0, 0); // No-harm value
}

bool GuidelineStateHandleAbstract::doPaint () const
{
  return false;
}

void GuidelineStateHandleAbstract::handleActiveChange (bool /* active */)
{
  // Noop  
}

void GuidelineStateHandleAbstract::handleHoverEnterEvent ()
{
  LOG4CPP_DEBUG_S ((*mainCat)) << "GuidelineStateHandleAbstract::handleHoverEnterEvent";

  // Noop
}

void GuidelineStateHandleAbstract::handleHoverLeaveEvent ()
{
  LOG4CPP_DEBUG_S ((*mainCat)) << "GuidelineStateHandleAbstract::handleHoverEnterEvent";

  // Noop
}

void GuidelineStateHandleAbstract::handleMousePress (const QPointF & /* posScene */)
{
  LOG4CPP_DEBUG_S ((*mainCat)) << "GuidelineStateHandleAbstract::handleMousePress";

  // Noop
}

void GuidelineStateHandleAbstract::handleVisibleChange (bool /* visible */)
{
  // Noop
}

bool GuidelineStateHandleAbstract::isDiscarded () const
{
  return true;
}

EllipseParameters GuidelineStateHandleAbstract::pointToEllipse (const QPointF & /* poscreen */) const
{
  return EllipseParameters();
}

QLineF GuidelineStateHandleAbstract::pointToLine (const QPointF & /* posGraph */) const
{
  return QLineF (0, 0, 0, 0);
}

void GuidelineStateHandleAbstract::updateWithLatestTransformation ()
{
  // Noop
}