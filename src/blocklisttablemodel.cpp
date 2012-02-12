#include "song.h"
#include "blocklisttablemodel.h"

BlockListTableModel::BlockListTableModel(QObject *parent) :
    QAbstractTableModel(parent),
    song(NULL)
{
}

void BlockListTableModel::setSong(Song *song)
{
    beginResetModel();
    this->song = song;
    endResetModel();
}

int BlockListTableModel::rowCount(const QModelIndex &parent) const
{
    return (parent.isValid() || song == NULL) ? 0 : song->blocks();
}

int BlockListTableModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 4;
}

QVariant BlockListTableModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= song->blocks() || index.column() < 0 || index.column() >= 4 || (role != Qt::DisplayRole && role != Qt::EditRole)) {
        return QVariant();
    } else {
        switch (index.column()) {
        case 0:
            return song->block(index.row())->name();
        case 1:
            return song->block(index.row())->tracks();
        case 2:
            return song->block(index.row())->length();
        case 3:
            return song->block(index.row())->commandPages();
        default:
            return QVariant();
        }
    }
}

QVariant BlockListTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            switch(section) {
            case 0:
                return QVariant("Name");
            case 1:
                return QVariant("Tracks");
            case 2:
                return QVariant("Length");
            case 3:
                return QVariant("Command pages");
            default:
                break;
            }
        } else {
            return QVariant(section + 1);
        }
    }
    return QVariant();
}

bool BlockListTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole && index.row() >= 0 && index.row() < song->blocks()) {
        bool success = false;

        switch(index.column()) {
        case 0:
            song->block(index.row())->setName(value.toString());
            success = true;
            break;
        case 1:
            song->block(index.row())->setTracks(value.toUInt(&success));
            break;
        case 2:
            song->block(index.row())->setLength(value.toUInt(&success));
            break;
        case 3:
            song->block(index.row())->setCommandPages(value.toUInt(&success));
            break;
        default:
            break;
        }

        return success;
    } else {
        return false;
    }
}

Qt::ItemFlags BlockListTableModel::flags(const QModelIndex &index) const
{
    Q_UNUSED(index)

    return Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable;
}

bool BlockListTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(row)
    Q_UNUSED(count)
    Q_UNUSED(parent)

    return false;
}

bool BlockListTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(row)
    Q_UNUSED(count)
    Q_UNUSED(parent)

    return false;
}
