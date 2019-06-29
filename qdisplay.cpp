#include "qdisplay.h"

#include <QStringBuilder>

QString prompt_text(const QString& prompt, const QString& info, const QString& dlm) {
    QString qs = "<b>" % prompt % "</b>:" % dlm %  info;
    return qs;
}

QString prompt_text(const QString& prompt, const std::string& info, const QString& dlm) {
    return prompt_text(prompt, QString::fromStdString(info), dlm);
}

QString prompt_text(const QString& prompt, const int info, const QString& dlm) {
    return prompt_text(prompt, QString::number(info), dlm);
}

QString sign_str(int x) {
    if (x > 0) {
        return "+";
    } else if (x < 0) {
        return "-";
    } else {
        return "";
    }
}

QString yn_qstring(bool b) {
    QString bqs = b ? QStringLiteral("yes") : QStringLiteral("no");
    return bqs;
}

QString bold(const QString& qs) {
    return "<b>" % qs % "</b>";
}

void set_text_none_empty(QLabel* label, const QString& prompt, const QString& text) {
    if (!text.isEmpty()) {
        if (label->isHidden()) { label->show(); }
        label->setText(prompt_text(prompt, text));
    } else {
        label->setText(prompt_text(prompt, QStringLiteral("None")));
    }
}

void set_text_hide_empty(QLabel* label, const QString& prompt, const QString& text) {
    if (!text.isEmpty()) {
        if (label->isHidden()) { label->show(); }
        label->setText(prompt_text(prompt, text));
    } else {
        label->clear();
        label->hide();
    }
}
