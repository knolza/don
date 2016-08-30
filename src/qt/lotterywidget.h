// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef LotteryWIDGET_H
#define LotteryWIDGET_H

#include <QWidget>


/** Widget for entering bitcoin amounts.
  */
class LotteryWidget: public QWidget
{
    Q_OBJECT

    // Q_PROPERTY(qint64 value READ value WRITE setValue NOTIFY textChanged USER true)

public:
    explicit LotteryWidget(QWidget *parent = 0);

};

#endif // LotteryWIDGET_H
