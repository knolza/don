// Copyright (c) 2011-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef GAMBLEPAGEDIALOGDIALOG_H
#define GAMBLEPAGEDIALOGDIALOG_H

#include <QDialog>
#include <QHeaderView>
#include <QItemSelection>
#include <QKeyEvent>
#include <QMenu>
#include <QPoint>
#include <QVariant>

#include "guiutil.h"

namespace Ui {
    class GamblePageDialog;
}
class OptionsModel;
class WalletModel;

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Dialog for requesting payment of bitcoins */
class GamblePageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GamblePageDialog(QWidget *parent = 0);
    ~GamblePageDialog();
    inline void setModel(WalletModel *model) { walletModel = model; }

private:
    Ui::GamblePageDialog *ui;
    WalletModel * walletModel;
};

#endif // GAMBLEPAGEDIALOGDIALOG_H
