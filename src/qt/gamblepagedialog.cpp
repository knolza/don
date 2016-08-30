// Copyright (c) 2011-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "gamblepagedialog.h"
#include "ui_gamblepagedialog.h"

#include "addressbookpage.h"
#include "addresstablemodel.h"
#include "bitcoinunits.h"
#include "guiutil.h"
#include "optionsmodel.h"
#include "receiverequestdialog.h"
#include "recentrequeststablemodel.h"
#include "walletmodel.h"

#include <QAction>
#include <QCursor>
#include <QItemSelection>
#include <QMessageBox>
#include <QScrollBar>
#include <QTextDocument>

GamblePageDialog::GamblePageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GamblePageDialog)
{
    ui->setupUi(this);

}

GamblePageDialog::~GamblePageDialog()
{
    delete ui;
}


