#include "qhelpers.h"

#include <QStringBuilder>

QString prompt_text(const QString& prompt, const QString& info, const QString& dlm) {
    QString qs = "<b>" % prompt % "</b>:" % dlm %  info;
    return qs;
}

QString prompt_text(const QString& prompt, const std::string& info, const QString& dlm) {
    return prompt_text(prompt, QString::fromStdString(info), dlm);
}

QString prompt_text(const QString& prompt, const int info, const QString& dlm) {
    return prompt_text(prompt, QString(info), dlm);
}
