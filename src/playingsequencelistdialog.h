/*
 * playingsequencelistdialog.h
 *
 * Copyright 2002-2012 Vesa Halttunen
 *
 * This file is part of Tutka.
 *
 * Tutka is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Tutka is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Tutka; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef PLAYINGSEQUENCELISTDIALOG_H
#define PLAYINGSEQUENCELISTDIALOG_H

#include <QDialog>

namespace Ui {
    class PlayingSequenceListDialog;
}

class Song;
class PlayingSequenceListTableModel;

class PlayingSequenceListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlayingSequenceListDialog(QWidget *parent = 0);
    ~PlayingSequenceListDialog();

public slots:
    void setSong(Song *song);
    void setPlayingSequence(unsigned int playingSequence);

private slots:
    void insertPlayingSequence();
    void appendPlayingSequence();
    void deletePlayingSequence();

private:
    Ui::PlayingSequenceListDialog *ui;
    Song *song;
    PlayingSequenceListTableModel *playingSequenceListTableModel;
};

#endif // PLAYINGSEQUENCELISTDIALOG_H
