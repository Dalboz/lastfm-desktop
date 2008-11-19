/***************************************************************************
 *   Copyright 2005-2008 Last.fm Ltd.                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Steet, Fifth Floor, Boston, MA  02110-1301, USA.          *
 ***************************************************************************/
 
#ifndef TRACK_DASHBOARD_HEADER_H
#define TRACK_DASHBOARD_HEADER_H

#include <QWidget>
#include <QMouseEvent>


class TrackDashboardHeader : public QWidget
{
    Q_OBJECT
    
public:
    TrackDashboardHeader();
    
    void setCogMenu( class QMenu* menu );
    
    struct {
        class ScrobbleButton* scrobbleButton;
        class RadioProgressBar* radioProgress;
        class ImageButton* love;
        class ImageButton* ban;
        class ImageButton* cog;
        class QLabel* track;
    } ui;
    
protected:
    void paintEvent( QPaintEvent* e );    
    void resizeEvent( QResizeEvent* e );

    QPoint m_mouseDownPos;
    void mousePressEvent( QMouseEvent* e )
    {
        m_mouseDownPos = e->globalPos() - window()->pos();
    }
    
    void mouseMoveEvent( QMouseEvent* e )
    {
        if( !m_mouseDownPos.isNull())
            window()->move( e->globalPos() - m_mouseDownPos);
    }
    
    void mouseReleaseEvent( QMouseEvent* e )
    {
        m_mouseDownPos = QPoint();
    }
    
private slots:
    void onTrackSpooled( const class Track&, class StopWatch* );
    void onContextMenuRequested( const QPoint& pos );
    
    void onPraiseClientTeam();
    void onCurseClientTeam();
    void onCogMenuClicked();
    
private:
    class QMenu* m_cogMenu;
};


#endif //TRACK_DASHBOARD_HEADER_H