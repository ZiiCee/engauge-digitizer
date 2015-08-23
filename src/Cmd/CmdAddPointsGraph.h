#ifndef CMD_ADD_POINTS_GRAPH_H
#define CMD_ADD_POINTS_GRAPH_H

#include "CmdAbstract.h"
#include <QList>
#include <QPointF>
#include <QStringList>

class QXmlStreamReader;
class Transformation;

/// Command for adding one or more graph points. This is for Segment Fill mode
class CmdAddPointsGraph : public CmdAbstract
{
 public:
  /// Constructor for normal creation
  CmdAddPointsGraph(MainWindow &mainWindow,
                    Document &document,
                    const QString &curveName,
                    const QList<QPoint> &points,
                    const QList<double> &ordinals);

  /// Constructor for parsing error report file xml
  CmdAddPointsGraph(MainWindow &mainWindow,
                    Document &document,
                    const QString &cmdDescription,
                    QXmlStreamReader &reader);

  virtual ~CmdAddPointsGraph();

  virtual void cmdRedo ();
  virtual void cmdUndo ();
  virtual void saveXml (QXmlStreamWriter &writer) const;

private:
  CmdAddPointsGraph();

  QString m_curveName;

  QList<QPoint> m_points; // Screen coordinates
  QList<double> m_ordinals;

  QStringList m_identifiersAdded; // Points that got added. This is generated by the Document during the Redo
};

#endif // CMD_ADD_POINTS_GRAPH_H