// Copyright (c) 2017-2018 The PIVX Developers
// Copyright (c) 2018 The HOTCHAIN Developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef zHOTXCONTROLDIALOG_H
#define zHOTXCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "primitives/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class zHotxControlDialog;
}

class CzHotxControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CzHotxControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CzHotxControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CzHotxControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class zHotxControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit zHotxControlDialog(QWidget *parent);
    ~zHotxControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::zHotxControlDialog *ui;
    WalletModel* model;
    PrivacyDialog* privacyDialog;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CzHotxControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // zHOTXCONTROLDIALOG_H
